#include "draw.h"


void draw_tail2(uint16_t x0, uint16_t y0)
{
	LCD_DrawLine(x0, y0, x0+10, y0+3 ,Blue);
}