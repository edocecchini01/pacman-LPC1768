#include "draw.h"

//LCD_SetPoint(uint16_t Xpos,uint16_t Ypos,uint16_t point);
//LCD_DrawLine( uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1 , uint16_t color );


void draw_tail_1(uint16_t x0, uint16_t y0)
{
	LCD_DrawLine(x0+6, y0+3, x0+5, y0+3 ,Blue);
	LCD_SetPoint(x0+4, y0+4, Blue);
	LCD_DrawLine(x0+3, y0+5, x0+3, y0+6 ,Blue);

	LCD_SetPoint(x0, y0, Green);
}

void draw_tail_2(uint16_t x0, uint16_t y0)
{
	LCD_DrawLine(x0, y0+3, x0+6, y0+3 ,Blue);

	LCD_SetPoint(x0, y0, Green);
}