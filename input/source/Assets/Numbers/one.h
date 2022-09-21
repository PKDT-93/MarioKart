/* GIMP RGBA C-Source image dump (one.c) */

static const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel; /* 2:RGB16, 3:RGB, 4:RGBA */ 
  unsigned char	 pixel_data[32 * 32 * 2 + 1];
} one = {
  32, 32, 2,
  "\377\377\377\377]\357\367\275U\255\024\245\024\245\024\245\024\245\024\245\024"
  "\245\024\245\024\245\024\245\024\245\024\245\024\245\024\245\024\245\024\245\024\245"
  "\024\245\024\245\024\245\024\245\064\245\266\265\373\336\377\377\377\377\377\377"
  "\377\377\377\377\030\306$!\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000a\010\323\234\377\377\377"
  "\377\377\377\337\377\216s\000\000\000\000``\001\271\001\271\001\271\001\271\001\271\001\271\001"
  "\271\001\271\001\271\001\271\001\271\001\271\001\271\001\271\001\271\001\271\001\271\001\271\001"
  "\271\001\271\240\210\000\000\000\000\246\061]\357\377\377\377\377\337\377Mk\000\000\000\000"
  "\240\200\202\361\202\361\202\361\202\361\202\361\202\361\202\361\202\361"
  "\202\361\202\361\202\361\202\361\202\361\202\361\202\361\202\361\202\361"
  "\202\361\202\361\202\361\000\261\000\000\000\000\206\061<\347\377\377\377\377\337\377"
  "Mk\000\000\000\000\240\200\202\361\202\361\202\361\202\361\202\361\202\361\202\361"
  "\202\361\202\361\202\361\202\361\202\361\202\361\202\361\202\361\202\361"
  "\202\361\202\361\202\361\202\361\000\261\000\000\000\000\206\061<\347\377\377\377\377"
  "\337\377Mk\000\000\000\000\240\200\202\361\202\361\202\361\202\361\202\361\202\361"
  "\202\361\202\361\202\361\202\361\202\361\202\361\202\361\202\361\202\361"
  "\202\361\202\361\202\361\202\361\202\361\000\261\000\000\000\000\206\061<\347\377\377"
  "\377\377\337\377\020\204\000\000\000\000\040@\240\200\240\200\240\200\240\200\240\200"
  "\240\200\340\240\202\361\202\361\202\361\202\361\202\361\202\361\202\361"
  "\202\361\202\361\202\361\202\361\202\361\202\361\000\261\000\000\000\000\206\061<\347"
  "\377\377\377\377\377\377\034\347\216sa\010\000\000\000\000\000\000\000\000\000\000\000\000\000\000\240"
  "x\202\361\202\361\202\361\202\361\202\361\202\361\202\361\202\361\202\361"
  "\202\361\202\361\202\361\202\361\000\261\000\000\000\000\206\061<\347\377\377\377\377"
  "\377\377\377\377\377\377]\357\373\336\272\326\272\326\232\326\313Z\000\000\000"
  "\000\240x\202\361\202\361\202\361\202\361\202\361\202\361\202\361\202\361\202"
  "\361\202\361\202\361\202\361\202\361\000\261\000\000\000\000\206\061<\347\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\337\377mk\000"
  "\000\000\000\240x\202\361\202\361\202\361\202\361\202\361\202\361\202\361\202\361"
  "\202\361\202\361\202\361\202\361\202\361\000\261\000\000\000\000\206\061<\347\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\337\377"
  "mk\000\000\000\000\240x\202\361\202\361\202\361\202\361\202\361\202\361\202\361\202"
  "\361\202\361\202\361\202\361\202\361\202\361\000\261\000\000\000\000\206\061<\347\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\337"
  "\377mk\000\000\000\000\240x\202\361\202\361\202\361\202\361\202\361\202\361\202\361"
  "\202\361\202\361\202\361\202\361\202\361\202\361\000\261\000\000\000\000\206\061<\347"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
  "\337\377mk\000\000\000\000\240x\202\361\202\361\202\361\202\361\202\361\202\361\202"
  "\361\202\361\202\361\202\361\202\361\202\361\202\361\000\261\000\000\000\000\206\061"
  "<\347\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
  "\377\337\377mk\000\000\000\000\240x\202\361\202\361\202\361\202\361\202\361\202\361"
  "\202\361\202\361\202\361\202\361\202\361\202\361\202\361\000\261\000\000\000\000\206"
  "\061<\347\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
  "\377\377\337\377mk\000\000\000\000\240x\202\361\202\361\202\361\202\361\202\361\202"
  "\361\202\361\202\361\202\361\202\361\202\361\202\361\202\361\000\261\000\000\000"
  "\000\206\061<\347\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
  "\377\377\377\337\377mk\000\000\000\000\240x\202\361\202\361\202\361\202\361\202\361"
  "\202\361\202\361\202\361\202\361\202\361\202\361\202\361\202\361\000\261\000"
  "\000\000\000\206\061<\347\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
  "\377\377\377\377\337\377mk\000\000\000\000\240x\202\361\202\361\202\361\202\361\202"
  "\361\202\361\202\361\202\361\202\361\202\361\202\361\202\361\202\361\000\261"
  "\000\000\000\000\206\061<\347\377\377\377\377\377\377\377\377\377\377\377\377\377"
  "\377\377\377\377\377\337\377mk\000\000\000\000\240x\202\361\202\361\202\361\202\361"
  "\202\361\202\361\202\361\202\361\202\361\202\361\202\361\202\361\202\361"
  "\000\261\000\000\000\000\206\061<\347\377\377\377\377\377\377\377\377\377\377\377\377"
  "\377\377\377\377\377\377\337\377mk\000\000\000\000\240x\202\361\202\361\202\361\202"
  "\361\202\361\202\361\202\361\202\361\202\361\202\361\202\361\202\361\202"
  "\361\000\261\000\000\000\000\206\061<\347\377\377\377\377\377\377\377\377\377\377\377"
  "\377\377\377\377\377\377\377\337\377mk\000\000\000\000\240x\202\361\202\361\202\361"
  "\202\361\202\361\202\361\202\361\202\361\202\361\202\361\202\361\202\361"
  "\202\361\000\261\000\000\000\000\206\061<\347\377\377\377\377\377\377\377\377\377\377"
  "\377\377\377\377\377\377\377\377\337\377mk\000\000\000\000\240x\202\361\202\361\202"
  "\361\202\361\202\361\202\361\202\361\202\361\202\361\202\361\202\361\202"
  "\361\202\361\000\261\000\000\000\000\206\061<\347\377\377\377\377\377\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\337\377mk\000\000\000\000\240x\202\361\202\361"
  "\202\361\202\361\202\361\202\361\202\361\202\361\202\361\202\361\202\361"
  "\202\361\202\361\000\261\000\000\000\000\206\061<\347\377\377\377\377\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\337\377mk\000\000\000\000\240x\202\361\202"
  "\361\202\361\202\361\202\361\202\361\202\361\202\361\202\361\202\361\202"
  "\361\202\361\202\361\000\261\000\000\000\000\206\061<\347\377\377\377\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\337\377mk\000\000\000\000\240x\202\361"
  "\202\361\202\361\202\361\202\361\202\361\202\361\202\361\202\361\202\361"
  "\202\361\202\361\202\361\000\261\000\000\000\000\206\061<\347\377\377\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\337\377mk\000\000\000\000\240x\202"
  "\361\202\361\202\361\202\361\202\361\202\361\202\361\202\361\202\361\202"
  "\361\202\361\202\361\202\361\000\261\000\000\000\000\206\061<\347\377\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\337\377mk\000\000\000\000\240"
  "x\202\361\202\361\202\361\202\361\202\361\202\361\202\361\202\361\202\361"
  "\202\361\202\361\202\361\202\361\000\261\000\000\000\000\206\061<\347\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\337\377mk\000\000\000"
  "\000\240x\202\361\202\361\202\361\202\361\202\361\202\361\202\361\202\361\202"
  "\361\202\361\202\361\202\361\202\361\000\261\000\000\000\000\206\061<\347\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\337\377mk\000"
  "\000\000\000\240x\202\361\202\361\202\361\202\361\202\361\202\361\202\361\202\361"
  "\202\361\202\361\202\361\202\361\202\361\000\261\000\000\000\000\206\061<\347\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\337\377"
  "mk\000\000\000\000\240x\202\361\202\361\202\361\202\361\202\361\202\361\202\361\202"
  "\361\202\361\202\361\202\361\202\361\202\361\000\261\000\000\000\000\206\061<\347\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\337"
  "\377mk\000\000\000\000\200x\202\361\202\351\202\351\202\351\202\351\202\351\202\351"
  "\202\351\202\351\202\351\202\351\202\351\202\351\000\261\000\000\000\000\206\061<\347"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
  "\377\377\222\224\000\000\000\000\000\040\040@\040@\040@\040@\040@\040@\040@\040@\040@\040@\040"
  "@\040@\040@\000\060\000\000\000\000IJ\276\367\377\377\377\377\377\377\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\236\367\363\234e)\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\242\020\020\204\034\347\377\377"
  "\377\377\377\377",
};

