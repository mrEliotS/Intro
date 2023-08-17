#include <stdio.h>

#define FONT_SZ 512
enum { RESET,BRIGHT,DIM,UNDERLINE,BLINK };
enum { REVERSE=7,HIDDEN };
enum { BLACK,RED,GREEN,YELLOW,BLUE,MAGENTA,CYAN,WHITE };
void textcolor(int attr,int fg,int bg);



