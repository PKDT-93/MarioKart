drawMenu(0, 0, gameoverup);
void gameOver()
{
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
			drawMenu(0, 0, gameoverup);
			flag = 0;
		}
		// when pressing up
		if (buttons[BTN_D] == 0)
		{
			drawMenu(0, 0, gameoverdown);
			flag = 1;
		}

		if (buttons[BTN_A] == 0 && flag == 0)
			goto restart break;
		if (buttons[BTN_A] == 0 && flag == 1)
		{
			system("clear");
			exit(0);
		}
	}