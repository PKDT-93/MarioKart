/* GIMP RGB C-Source image dump (pipe.c) */

static const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel; /* 2:RGB16, 3:RGB, 4:RGBA */ 
  unsigned char	 pixel_data[32 * 32 * 2 + 1];
} pipe = {
  32, 32, 2,
  ".\277.\277.\277\240\216\240\216\240\216\240\024\240\024\240\024.\277.\277.\277"
  "\040\013\040\013\040\013\240\024\240\216\240\216\240\216\240\216\240\216\240\216"
  "\240\216\240\024\240\024\240\024\240\024\040\013\240\024\240\024\240\024\040\013.\277"
  ".\277.\277\240\216\240\216\240\216\240\024\240\024\240\024.\277.\277.\277\040"
  "\013\040\013\040\013\240\024\240\216\240\216\240\216\240\216\240\216\240\216\240"
  "\216\240\024\240\024\240\024\240\024\040\013\240\024\240\024\240\024\040\013.\277.\277"
  ".\277\240\216\240\216\240\216\240\024\240\024\240\024.\277.\277.\277\040\013\040"
  "\013\040\013\240\024\240\216\240\216\240\216\240\216\240\216\240\216\240\216"
  "\240\024\240\024\240\024\240\024\040\013\240\024\240\024\240\024\040\013.\277.\277."
  "\277\240\216\240\216\240\216\240\024\240\024\240\024.\277.\277.\277\040\013\040"
  "\013\040\013\240\024\240\216\240\216\240\216\240\216\240\216\240\216\240\216"
  "\240\024\240\024\240\024\240\024\040\013\240\024\240\024\240\024\040\013.\277.\277."
  "\277\240\216\240\216\240\216\240\024\240\024\240\024.\277.\277.\277\040\013\040"
  "\013\040\013\240\024\240\216\240\216\240\216\240\216\240\216\240\216\240\216"
  "\240\024\240\024\240\024\240\024\040\013\240\024\240\024\240\024\040\013.\277.\277."
  "\277\240\216\240\216\240\216\240\024\240\024\240\024.\277.\277.\277\040\013\040"
  "\013\040\013\240\024\240\216\240\216\240\216\240\216\240\216\240\216\240\216"
  "\240\024\240\024\240\024\240\024\040\013\240\024\240\024\240\024\040\013.\277.\277."
  "\277\240\216\240\216\240\216\240\024\240\024\240\024.\277.\277.\277\040\013\040"
  "\013\040\013\240\024\240\216\240\216\240\216\240\216\240\216\240\216\240\216"
  "\240\024\240\024\240\024\240\024\040\013\240\024\240\024\240\024\040\013.\277.\277."
  "\277\240\216\240\216\240\216\240\024\240\024\240\024.\277.\277.\277\040\013\040"
  "\013\040\013\240\024\240\216\240\216\240\216\240\216\240\216\240\216\240\216"
  "\240\024\240\024\240\024\240\024\040\013\240\024\240\024\240\024\040\013.\277.\277."
  "\277\240\216\240\216\240\216\240\024\240\024\240\024.\277.\277.\277\040\013\040"
  "\013\040\013\240\024\240\216\240\216\240\216\240\216\240\216\240\216\240\216"
  "\240\024\240\024\240\024\240\024\040\013\240\024\240\024\240\024\040\013.\277.\277."
  "\277\240\216\240\216\240\216\240\024\240\024\240\024.\277.\277.\277\040\013\040"
  "\013\040\013\240\024\240\216\240\216\240\216\240\216\240\216\240\216\240\216"
  "\240\024\240\024\240\024\240\024\040\013\240\024\240\024\240\024\040\013.\277.\277."
  "\277\240\216\240\216\240\216\240\024\240\024\240\024.\277.\277.\277\040\013\040"
  "\013\040\013\240\024\240\216\240\216\240\216\240\216\240\216\240\216\240\216"
  "\240\024\240\024\240\024\240\024\040\013\240\024\240\024\240\024\040\013.\277.\277."
  "\277\240\216\240\216\240\216\240\024\240\024\240\024.\277.\277.\277\040\013\040"
  "\013\040\013\240\024\240\216\240\216\240\216\240\216\240\216\240\216\240\216"
  "\240\024\240\024\240\024\240\024\040\013\240\024\240\024\240\024\040\013\240\216\240"
  "\216\240\216\240\024\240\024\240\024\040\013\040\013\040\013\240\216\240\216\240\216"
  "\206\061\206\061\206\061\040\013\240\024\240\024\240\024\240\024\240\024\240\024\240"
  "\024\040\013\040\013\040\013\040\013\206\061\040\013\040\013\040\013\206\061\240\216\240\216"
  "\240\216\240\216\240\024\240\024\240\024\040\013\040\013\040\013\240\216\240\216\206"
  "\061\206\061\206\061\040\013\240\024\240\024\240\024\240\024\240\024\240\024\040\013\040"
  "\013\040\013\040\013\206\061\040\013\040\013\040\013\206\061\206\061\206\061\206\061\206"
  "\061\206\061\206\061\000\000\000\000\000\000\000\000\000\000\206\061\206\061\206\061\000\000\000\000\206\061"
  "\206\061\000\000\206\061\000\000\000\000\000\000\206\061\206\061\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000.\277.\277.\277.\277.\277.\277\240\216\240\216\240\024\240\024\240\024."
  "\277.\277.\277\040\013\040\013\240\216\240\216\240\216\240\216\240\216\240\024"
  "\240\024\040\013\040\013\240\024\240\024\040\013\040\013\040\013\040\013\040\013.\277.\277"
  ".\277.\277.\277.\277.\277\240\216\240\216\240\024\240\024.\277.\277.\277\040"
  "\013\040\013\240\216\240\216\240\216\240\216\240\216\240\024\240\024\040\013\240"
  "\024\240\024\040\013\040\013\040\013\040\013\040\013\040\013.\277.\277.\277.\277.\277."
  "\277.\277\240\216\240\216\240\024\240\024.\277.\277.\277\040\013\040\013\240\216"
  "\240\216\240\216\240\216\240\216\240\024\240\024\040\013\240\024\240\024\040\013"
  "\040\013\040\013\040\013\040\013\040\013.\277.\277.\277.\277.\277.\277.\277\240\216"
  "\240\216\240\024\240\024.\277.\277.\277\040\013\040\013\240\216\240\216\240\216"
  "\240\216\240\216\240\024\240\024\040\013\240\024\240\024\040\013\040\013\040\013\040\013"
  "\040\013\040\013.\277.\277.\277.\277.\277.\277.\277\240\216\240\216\240\024\240"
  "\024.\277.\277.\277\040\013\040\013\240\216\240\216\240\216\240\216\240\216\240"
  "\024\240\024\040\013\240\024\240\024\040\013\040\013\040\013\040\013\040\013\040\013.\277."
  "\277.\277.\277.\277.\277.\277\240\216\240\216\240\024\240\024.\277.\277.\277"
  "\040\013\040\013\240\216\240\216\240\216\240\216\240\216\240\024\240\024\040\013"
  "\240\024\240\024\040\013\040\013\040\013\040\013\040\013\040\013.\277.\277.\277.\277.\277"
  ".\277.\277\240\216\240\216\240\024\240\024.\277.\277.\277\040\013\040\013\240\216"
  "\240\216\240\216\240\216\240\216\240\024\240\024\040\013\240\024\240\024\040\013"
  "\040\013\040\013\040\013\040\013\040\013.\277.\277.\277.\277.\277.\277.\277\240\216"
  "\240\216\240\024\240\024.\277.\277.\277\040\013\040\013\240\216\240\216\240\216"
  "\240\216\240\216\240\024\240\024\040\013\240\024\240\024\040\013\040\013\040\013\040\013"
  "\040\013\040\013.\277.\277.\277.\277.\277.\277.\277\240\216\240\216\240\024\240"
  "\024.\277.\277.\277\040\013\040\013\240\216\240\216\240\216\240\216\240\216\240"
  "\024\240\024\040\013\240\024\240\024\040\013\040\013\040\013\040\013\040\013\040\013.\277."
  "\277.\277.\277.\277.\277.\277\240\216\240\216\240\024\240\024.\277.\277.\277"
  "\040\013\040\013\240\216\240\216\240\216\240\216\240\216\240\024\240\024\040\013"
  "\240\024\240\024\040\013\040\013\040\013\040\013\040\013\040\013.\277.\277.\277.\277.\277"
  ".\277.\277\240\216\240\216\240\024\240\024.\277.\277.\277\040\013\040\013\240\216"
  "\240\216\240\216\240\216\240\216\240\024\240\024\040\013\240\024\240\024\040\013"
  "\040\013\040\013\040\013\040\013\040\013.\277.\277.\277.\277.\277.\277.\277\240\216"
  "\240\216\240\024\240\024.\277.\277.\277\040\013\040\013\240\216\240\216\240\216"
  "\240\216\240\216\240\024\240\024\040\013\240\024\240\024\040\013\040\013\040\013\040\013"
  "\040\013\040\013.\277.\277.\277.\277.\277.\277.\277\240\216\240\216\240\024\240"
  "\024.\277.\277.\277\040\013\040\013\240\216\240\216\240\216\240\216\240\216\240"
  "\024\240\024\040\013\240\024\240\024\040\013\040\013\040\013\040\013\040\013\040\013.\277."
  "\277.\277.\277.\277.\277.\277\240\216\240\216\240\024\240\024.\277.\277.\277"
  "\040\013\040\013\240\216\240\216\240\216\240\216\240\216\240\024\240\024\040\013"
  "\240\024\240\024\040\013\040\013\040\013\040\013\040\013\040\013.\277.\277.\277.\277.\277"
  ".\277.\277\240\216\240\216\240\024\240\024.\277.\277.\277\040\013\040\013\240\216"
  "\240\216\240\216\240\216\240\216\240\024\240\024\040\013\240\024\240\024\040\013"
  "\040\013\040\013\040\013\040\013\040\013.\277.\277.\277.\277.\277.\277.\277\240\216"
  "\240\216\240\024\240\024.\277.\277.\277\040\013\040\013\240\216\240\216\240\216"
  "\240\216\240\216\240\024\240\024\040\013\240\024\240\024\040\013\040\013\040\013\040\013"
  "\040\013\040\013.\277.\277.\277.\277.\277.\277.\277\240\216\240\216\240\024\240"
  "\024.\277.\277.\277\040\013\040\013\240\216\240\216\240\216\240\216\240\216\240"
  "\024\240\024\040\013\240\024\240\024\040\013\040\013\040\013\040\013\040\013\040\013",
};

