#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/mman.h>
#include "framebuffer.h"
#include <wiringPi.h>
#include "initGPIO.h"
#include "Assets/mario.h"
#include "Assets/mushroom.h"
#include "Assets/finish.h"
#include "Assets/flower.h"
#include "Assets/goomba.h"
#include "Assets/pipe.h"
#include "Assets/shell.h"
#include "Assets/star.h"
#include "Assets/wall.h"
#include "Assets/wall2.h"
#include "Assets/Numbers/zero.h"
#include "Assets/Numbers/one.h"
#include "Assets/Numbers/two.h"
#include "Assets/Numbers/three.h"
#include "Assets/Numbers/four.h"
#include "Assets/Numbers/five.h"
#include "Assets/Numbers/six.h"
#include "Assets/Numbers/seven.h"
#include "Assets/Numbers/eight.h"
#include "Assets/Numbers/nine.h"
#include "Assets/life.h"
#include "Assets/ui.h"
#include "Assets/Labels/liveslabel.h"
#include "Assets/Labels/scorelabel.h"
#include "Assets/Labels/timelabel.h"
#include "Assets/Background/bgup.h"
#include "Assets/Background/bgdown.h"
#include "Assets/Background/gameoverdown.h"
#include "Assets/Background/gameoverup.h"
#include <time.h>


// GPIO setup macros.
// Always use INP_GPIO(x) before using OUT_GPIO(x) or SET_GPIO_ALT(x,y)
#define INP_GPIO(g) *(gpio + ((g) / 10)) &= ~(7 << (((g) % 10) * 3))
#define OUT_GPIO(g) *(gpio + ((g) / 10)) |= (1 << (((g) % 10) * 3))
#define SET_GPIO_ALT(g, a) *(gpio + ((g) / 10)) |= (((a) <= 3 ? (a) + 4 : (a) == 4 ? 3 : 2) << (((g) % 10) * 3))

#define GPSET0 7
#define GPCLR0 10
#define GPLEV0 13

#define CLK 11
#define LAT 9  // MISO
#define DAT 10 // MOSI

// SNES Controller Buttons
#define BTN_B 0
#define BTN_Y 1
#define BTN_SEL 2
#define BTN_STA 3
#define BTN_U 4
#define BTN_D 5
#define BTN_L 6
#define BTN_R 7
#define BTN_A 8
#define BTN_X 9
#define BTN_SL 10
#define BTN_SR 11

static unsigned int *gpio;

// attributes for the game
int stillobjects = 20;
int moveObjects = 10;
int backgroundOffset = 96;
int gridSize = 32;
int xResolution = 1280;
int yResolution = 720;
int digit = 3;				// the digit number of score and lives

/* Definitions */
typedef struct
{
	short int color;
	int x, y;
} Pixel;

// to store player's position
struct Player
{ 
	int prev_x;
	int prev_y;
	int curr_x;
	int curr_y;
} player;

struct Status
{
	int playerSpeed;
	int objSpeed;
	int gameTime;
	int score;
	int life;
} status;

struct fbs framebufferstruct;

void init_GPIO(int line, int mode)
{
	// set line as input
	if (mode == 0)
	{
		INP_GPIO(line);
	}
	// set line as output
	else if (mode == 1)
	{
		INP_GPIO(line);
		OUT_GPIO(line);
	}
	// wrong mode
	else
	{
		printf("Wrong mode!\n");
	}
}

// write the inputted value to the bit of the GPIO Latch line
void write_Latch(int val)
{
	// set value 0 to Latch line (CLR)
	if (val == 0)
	{
		gpio[GPCLR0] = 1 << LAT;
	}
	// set value 1 to Latch line (SET)
	else if (val == 1)
	{
		gpio[GPSET0] = 1 << LAT;
	}
	// wrong value
	else
	{
		printf("Wrong value!\n");
	}
}

// write the inputted value to the bit of the GPIO Clock line
void write_Clock(int val)
{
	// set value 0 to Latch line (CLR)
	if (val == 0)
	{
		gpio[GPCLR0] = 1 << CLK;
	}
	// set value 1 to Latch line (SET)
	else if (val == 1)
	{
		gpio[GPSET0] = 1 << CLK;
	}
	// wrong value
	else
	{
		printf("Wrong value!\n");
	}
}

// read a bit from the GPIO data line
// 0 means being pressed; 1 means not being pressed
int read_Data()
{
	return (gpio[GPLEV0] >> DAT) & 1;
}

// wait inputted micro seconds
void wait(int microSec)
{
	delayMicroseconds(microSec);
}

// read input from a SNES controller and return them as an int array
int *read_SNES()
{
	static int buttons[16];

	write_Clock(1); // Clock rising edge
	write_Latch(1); // Latch rising edge
	wait(12);		// signal to SNES to sample buttons
	write_Latch(0); // Latch falling edge

	for (int i = 0; i < 16; i++)
	{
		wait(6);				  // wait 6 micro seconds
		write_Clock(0);			  // Clock falling edge
		wait(6);				  // wait 6 micro seconds
		buttons[i] = read_Data(); // read the data from Data line and store it to buttons
		write_Clock(1);			  // Clock rising edge
	}

	return buttons;
}

/* Draw a pixel */
void drawPixel(Pixel *pixel)
{
	long int location = (pixel->x + framebufferstruct.xOff) * (framebufferstruct.bits / 8) +
						(pixel->y + framebufferstruct.yOff) * framebufferstruct.lineLength;
	*((unsigned short int *)(framebufferstruct.fptr + location)) = pixel->color;
}

// draw white block
void drawWhite(int pos_x, int pos_y, int length, int width)
{
	/* initialize a pixel */
	Pixel *bg;
	bg = malloc(sizeof(Pixel));

	for (int y = pos_y; y < pos_y+width; y++)
	{
		for (int x = pos_x; x < pos_x+length; x++)
		{
			bg->color = 0xFFFF;
			bg->x = x;
			bg->y = y;

			drawPixel(bg);
		}
	}
}

void drawline(int pos_x, int pos_y, int length, int width)
{
	/* initialize a pixel */
	Pixel *bg;
	bg = malloc(sizeof(Pixel));

	for (int y = pos_y; y < pos_y+width; y++)
	{
		for (int x = pos_x; x < pos_x+length; x++)
		{
			bg->color = 0x0000;
			bg->x = x;
			bg->y = y;

			drawPixel(bg);
		}
	}
}

// draw the object
void drawObject(int pos_x, int pos_y, short int * obj)
{
	/* initialize a pixel */
	Pixel *pixel;
	pixel = malloc(sizeof(Pixel));

	int i = 0;
	for (int y = pos_y; y < pos_y + 32; y++)
	{
		for (int x = pos_x; x < pos_x+ 32; x++)
		{
			pixel->color = obj[i];
			pixel->x = x;
			pixel->y = y;
			drawPixel(pixel);
			i++;
		}
	}
}

//draw label
void drawlabel(int pos_x, int pos_y, short int * obj)
{
	/* initialize a pixel */
	Pixel *pixel;
	pixel = malloc(sizeof(Pixel));

	int i = 0;
	for (int y = pos_y; y < pos_y + 32; y++)
	{
		for (int x = pos_x; x < pos_x + 128; x++)
		{
			pixel->color = obj[i];
			pixel->x = x;
			pixel->y = y;
			drawPixel(pixel);
			i++;
		}
	}
}

// draw the beginneg menu
void drawMenu(int pos_x, int pos_y, short int * obj)
{
	/* initialize a pixel */
	Pixel *pixel;
	pixel = malloc(sizeof(Pixel));

	int i = 0;
	for (int y = pos_y; y < pos_y + 720; y++)
	{
		for (int x = pos_x; x < pos_x + 1280; x++)
		{
			pixel->color = obj[i];
			pixel->x = x;
			pixel->y = y;
			drawPixel(pixel);
			i++;
		}
	}
}

// draw start menu
void startMenu(int *buttons)
{
	short int *bgupObj = (short int *)bgup.pixel_data;
	short int *bgdownObj = (short int *)bgdown.pixel_data;
	short int *gameoverupObj = (short int *)gameoverup.pixel_data;
	short int *gameoverdownObj = (short int *)gameoverdown.pixel_data;
	int pressingButtons[12]; // store which buttons is being pressed
	int flag = 0;			// defalut by start game
	// draw the initial menu
	drawMenu(0, 0, bgupObj);

	while (1)
	{
		buttons = read_SNES(buttons); // scan all the buttons being pressed

		for (int i = 0; i < 12; i++)
		{
			if (buttons[i] == 0) // update the status of being pressed buttons (not pressed to pressed)
				pressingButtons[i] = 0;
			else if ((pressingButtons[i] == 0)) // update the status of being pressed buttons (pressed to not pressed)
				pressingButtons[i] = 1;
		}
		// when pressing down
		if (buttons[BTN_U] == 0)
		{
			drawMenu(0, 0, bgupObj);
			flag = 0;
		}
		// when pressing up
		if (buttons[BTN_D] == 0)
		{
			drawMenu(0, 0, bgdownObj);
			flag = 1;
		}

		if (buttons[BTN_A] == 0 && flag == 0)
			break;
		if (buttons[BTN_A] == 0 && flag == 1) {
			system("clear");
			exit(0);
		}
	}
}

void gameOverMenu(int *buttons)
{
	short int *gameoverupObj = (short int *)gameoverup.pixel_data;
	short int *gameoverdownObj = (short int *)gameoverdown.pixel_data;
	int pressingButtons[12]; // store which buttons is being pressed
	int flag = 0;			// defalut by start game
	// draw the initial menu
	drawMenu(0, 0, gameoverupObj);

	while (1)
	{
		buttons = read_SNES(buttons); // scan all the buttons being pressed

		for (int i = 0; i < 12; i++)
		{
			if (buttons[i] == 0) // update the status of being pressed buttons (not pressed to pressed)
				pressingButtons[i] = 0;
			else if ((pressingButtons[i] == 0)) // update the status of being pressed buttons (pressed to not pressed)
				pressingButtons[i] = 1;
		}
		// when pressing down
		if (buttons[BTN_U] == 0)
		{
			drawMenu(0, 0, gameoverupObj);
			flag = 0;
		}
		// when pressing up
		if (buttons[BTN_D] == 0)
		{
			drawMenu(0, 0, gameoverdownObj);
			flag = 1;
		}

		if (buttons[BTN_A] == 0 && flag == 0)
			break;
		if (buttons[BTN_A] == 0 && flag == 1)
		{
			system("clear");
			exit(0);
		}
	}
}

// delete one life while die
void die() {
	drawWhite((4+status.life)*gridSize, gridSize, gridSize, gridSize);
}

// draw the number at (x,y)
// not finish yet
void drawNum(int x, int y, int num) {
	int revNum = 0;
	do {
		revNum *= 10;
		revNum += num%10;
		num /= 10;
	} while(num != 0);

	printf("%d\n", revNum);
	
	// for (int i = 0; i < digit; i++) {
	// 	switch (num%10) {
	// 		case /* constant-expression */:
	// 		/* code */
	// 		break;
	// 	}
	// }
	
}

// get time in microsecond
long getMicrotime(){
	struct timeval currentTime;
	gettimeofday(&currentTime, NULL);
	return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
}

int main(int argc, char const *argv[])
{
	drawNum(0,0,10);	
	int xMaxGrid = xResolution/gridSize-1;
	int yMaxGrid = (yResolution-16)/gridSize-1;

	/* initialize + get FBS */
	framebufferstruct = initFbInfo();

	// get the GPIO address
	gpio = getGPIOPtr();

	// initialize the SNES
	init_GPIO(LAT, 1); // set Latch line as output
	init_GPIO(CLK, 1); // set Clock line as output
	init_GPIO(DAT, 0); // set Data line as input

	int *buttons;			 // store which buttons is pressed
	buttons = calloc(12, sizeof(int));
	int pressingButtons[12]; // store which buttons is being pressed

	// initialize the player position
	player.prev_x = xMaxGrid*gridSize;
	player.prev_y = yMaxGrid*gridSize;
	player.curr_x = xMaxGrid*gridSize;
	player.curr_y = yMaxGrid*gridSize;

	// stillObject.curr_x = gridSize * 10 + backgroundOffset;
	// stillObject.curr_y = gridSize * 10 + backgroundOffset;

	// declare all image
	short int *marioPtr = (short int *)marioImage.pixel_data;
	short int *wallObj = (short int *)wall.pixel_data;
	short int *goombaObj = (short int *)goomba.pixel_data;
	short int *liveslabelObj = (short int *)liveslabel.pixel_data;
	short int *scoreObj = (short int *)scorelabel.pixel_data;
	short int *timeObj = (short int *)timelabel.pixel_data;

	// short int *mushroomObj = (short int *)mushroom.pixel_data;
	short int *zeroObj = (short int *)zero.pixel_data;
	// short int *oneObj = (short int *)one.pixel_data;
	// short int *twoObj = (short int *)two.pixel_data;
	// short int *threeObj = (short int *)three.pixel_data;
	// short int *fourObj = (short int *)four.pixel_data;
	// short int *fiveObj = (short int *)five.pixel_data;
	// short int *sixObj = (short int *)six.pixel_data;
	// short int *sevenObj = (short int *)seven.pixel_data;
	// short int *eightObj = (short int *)eight.pixel_data;
	// short int *nineObj = (short int *)nine.pixel_data;
	short int *lifeObj = (short int *)life.pixel_data;
	// short int *starObj = (short int *)star.pixel_data;
	// short int *shellObj = (short int *)shell.pixel_data;
	// short int *wall2Obj = (short int *)wall2.pixel_data;
	// short int *flowerObj = (short int *)flower.pixel_data;

	// initialize locations for still object
	int stillObjArray[stillobjects][2];

	for (int i = 0; i < stillobjects; i++)
	{
		stillObjArray[i][0] = i * gridSize;			// x axis for still object
		stillObjArray[i][1] = yMaxGrid * gridSize;// y axis for still object
	}

	// initialize locations for moving object
	int moveObjArray[moveObjects][2];
	int direction[moveObjects];

	for (int i = 0; i < moveObjects; i++)
	{
		// x axis for still object
		moveObjArray[i][0] = i * gridSize;			// x axis for moving object
		moveObjArray[i][1] = (yMaxGrid-1) * gridSize;// y axis for moving object
		direction[i] = 1;							// moving direction
	}

	// initialize the pressingButtons array to all buttons is not being pressed
	for (int i = 0; i < 12; i++)
	{
		pressingButtons[i] = 1;
	}

	// game initial status
	status.playerSpeed = 50000;
	status.objSpeed = 500000;						// speed of moving objects (delay time)
	status.life = 3;								// initial lives
	status.gameTime = 60;							// initial time
	status.score = 1000;							// initial score

	// initial screeen setup
	startMenu(buttons);
restart:
	drawWhite(0, 0, xResolution, yResolution);		// draw white background
	drawline(0, 2*gridSize, xResolution, gridSize);	// draw a line to seperate play world and status
	drawline(0, yResolution-16, xResolution, 16);	// draw a line to fix the playground

	drawlabel(4*gridSize, 0, liveslabelObj);
	drawObject(4*gridSize, gridSize, lifeObj);
	drawObject(5*gridSize, gridSize, lifeObj);
	drawObject(6*gridSize, gridSize, lifeObj);

	drawlabel(19*gridSize, 0, timeObj);
	drawObject(19*gridSize, gridSize, zeroObj);
	drawObject(20*gridSize, gridSize, zeroObj);
	drawObject(21*gridSize, gridSize, zeroObj);

	drawlabel(32*gridSize, 0, scoreObj);
	drawObject(32*gridSize, gridSize, zeroObj);
	drawObject(33*gridSize, gridSize, zeroObj);
	drawObject(34*gridSize, gridSize, zeroObj);

	drawObject(player.curr_x, player.curr_y, marioPtr);	// draw player
	




	// draw still objects
	for (int i = 0; i < stillobjects; i++) {
		drawObject(stillObjArray[i][0], stillObjArray[i][1], wallObj);
	}


	long microSec_player = getMicrotime();
	long microSec_obj = getMicrotime();
	time_t timer = time(NULL);

	do
	{
		// avoid keep reading while pressing buttons
		for (int i = 0; i < 12; i++)
		{
			if (buttons[i] == 0) // update the status of being pressed buttons (not pressed to pressed)
				pressingButtons[i] = 0;
			else if ((pressingButtons[i] == 0)) // update the status of being pressed buttons (pressed to not pressed)
				pressingButtons[i] = 1;
		}

		buttons = read_SNES(buttons); // scan all the buttons being pressed

		// when press right
		if (buttons[BTN_R] == 0 && pressingButtons[BTN_R] && player.curr_x < xResolution-gridSize && getMicrotime()-microSec_player > status.playerSpeed)
		{
			player.curr_x += gridSize;	// move a grid (32 pixels) to right
			drawWhite(player.prev_x, player.prev_y, 32, 32);	// clear previous position
			microSec_player = getMicrotime();
			
		}

		// when press left
		if (buttons[BTN_L] == 0 && pressingButtons[BTN_L] && player.curr_x > 0 && getMicrotime()-microSec_player > status.playerSpeed) 
		{
			player.curr_x -= gridSize;	// move a grid (32 pixels) to left
			drawWhite(player.prev_x, player.prev_y, 32, 32);	// clear previous position
			microSec_player = getMicrotime();
			
		}

		// when press down
		if (buttons[BTN_D] == 0 && pressingButtons[BTN_D] && player.curr_y < yResolution-16-32 && getMicrotime()-microSec_player > status.playerSpeed)
		{
			player.curr_y += gridSize;	// move a grid (32 pixels) to down
			drawWhite(player.prev_x, player.prev_y, 32, 32);	// clear previous position
			microSec_player = getMicrotime();
		}

		// when press up
		if (buttons[BTN_U] == 0 && pressingButtons[BTN_U] && player.curr_y > backgroundOffset && getMicrotime()-microSec_player > status.playerSpeed)
		{
			player.curr_y -= gridSize;	// move a grid (32 pixels) to up
			drawWhite(player.prev_x, player.prev_y, 32, 32);	// clear previous position
			microSec_player = getMicrotime();
		}


		// to see if crossing the still objects
		for (int i = 0; i < stillobjects; i++) {
			if (player.curr_x == stillObjArray[i][0] && player.curr_y == stillObjArray[i][1]) {
				player.curr_x = player.prev_x;
				player.curr_y = player.prev_y;
				break;
			}
		}

		// to see if touching the moving objects
		for (int i = 0; i < moveObjects; i++) {
			if (player.curr_x == moveObjArray[i][0] && player.curr_y == moveObjArray[i][1]) {
				player.curr_x = xMaxGrid*gridSize;
				player.curr_y = yMaxGrid*gridSize;
				status.life -= 1;
				die();
				break;
			}
		}
		

		// change the previous position to current position
		player.prev_x = player.curr_x;
		player.prev_y = player.curr_y;

		// draw player at current position
		drawObject(player.curr_x, player.curr_y, marioPtr);


		





		// draw the moving objects
		if (getMicrotime() - microSec_obj  > status.objSpeed) {
			for (int i = 0; i < moveObjects; i++) {
				drawWhite(moveObjArray[i][0], moveObjArray[i][1], gridSize, gridSize);
				// decide the direction
				if (direction[i] == 1) {
					moveObjArray[i][0] += gridSize;
					moveObjArray[i][1] -= gridSize;
				}
				else {
					moveObjArray[i][0] -= gridSize;
					moveObjArray[i][1] += gridSize;
				}

				if (moveObjArray[i][0] == xMaxGrid*gridSize || moveObjArray[i][1] == 3*gridSize)
					direction[i] = 0;
				if (moveObjArray[i][0] == 0 || moveObjArray[i][1] == (yMaxGrid-1)*gridSize)
					direction[i] = 1;
				
				drawObject(moveObjArray[i][0], moveObjArray[i][1], goombaObj);
			}

			microSec_obj = getMicrotime();
		}

		// to see if moving objects touch player
		for (int i = 0; i < moveObjects; i++) {
			if (player.curr_x == moveObjArray[i][0] && player.curr_y == moveObjArray[i][1]) {
				player.curr_x = xMaxGrid*gridSize;
				player.curr_y = yMaxGrid*gridSize;
				status.life -= 1;
				die();
				break;
			}
		}

	} while (buttons[BTN_STA] && status.life >= 0);
	gameOverMenu(buttons);
	goto restart;

	munmap(framebufferstruct.fptr, framebufferstruct.screenSize);

	return 0;
}
