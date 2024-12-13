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


void draw_pacMan(uint16_t x0, uint16_t y0, uint16_t color)
{
		LCD_DrawLine(x0+4, y0, x0+9, y0 ,color);
		LCD_DrawLine(x0+2, y0+1, x0+11, y0+1,color);
		LCD_DrawLine(x0+1, y0+2, x0+12, y0+2,color);
		LCD_DrawLine(x0+1, y0+3, x0+12, y0+3,color);
		LCD_DrawLine(x0+3, y0+4, x0+13, y0+4,color);
		LCD_DrawLine(x0+6, y0+5, x0+13, y0+5,color);
		LCD_DrawLine(x0+9, y0+6, x0+13, y0+6,color);//CENTRO
		LCD_DrawLine(x0+6, y0+7, x0+13, y0+7,color);
		LCD_DrawLine(x0+3, y0+8, x0+13, y0+8,color);
		LCD_DrawLine(x0+1, y0+9, x0+12, y0+9,color);
		LCD_DrawLine(x0+1, y0+10, x0+12,y0+10,color);
		LCD_DrawLine(x0+2, y0+11, x0+11,y0+11,color);
		LCD_DrawLine(x0+4, y0+12, x0+9, y0+12,color);		
		LCD_SetPoint(x0, y0, Green);
}