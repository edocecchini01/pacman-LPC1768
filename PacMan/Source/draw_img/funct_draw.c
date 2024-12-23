#include "draw.h"
#include "game_logic/gameL.h"

//LCD_SetPoint(uint16_t Xpos,uint16_t Ypos,uint16_t point);
//LCD_DrawLine( uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1 , uint16_t color );

extern game_state gs;

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

void draw_tail_0(uint16_t x0, uint16_t y0) //quadrato 8x8
{
	int i = 0;
	
	for(i = 0; i<8; i++)
	{
		LCD_DrawLineHorizontal(x0,y0+i,x0+7,Blue);
		//LCD_DrawLine(x0,y0+i,x0+7,y0+i, Blue); 
	}
	
}

void draw_obj(uint16_t x0, uint16_t y0, uint16_t obj)
{
	int i = 0;
	
	switch(obj){
		case 0: //CORRIDOIO
			for(i = 0; i<8; i++)
			{
				LCD_DrawLineHorizontal(x0,y0+i,x0+7,Black);
			}
			break;
		case 1: //PACMAN
			LCD_DrawLineHorizontal(x0+2, y0, x0+5, Yellow);
			LCD_DrawLineHorizontal(x0+1, y0+1, x0+6, Yellow);
			LCD_DrawLineHorizontal(x0, y0+2, x0+7, Yellow);
			LCD_DrawLineHorizontal(x0, y0+3, x0+4, Yellow);
			LCD_DrawLineHorizontal(x0, y0+4, x0+4, Yellow);
			LCD_DrawLineHorizontal(x0, y0+5, x0+7, Yellow);
			LCD_DrawLineHorizontal(x0+1, y0+6, x0+6, Yellow);
			LCD_DrawLineHorizontal(x0+2, y0+7, x0+5, Yellow);
			break;
		case 3: //PILLS
			LCD_DrawLineHorizontal(x0+3, y0+2, x0+4, SalmonPink);
			LCD_DrawLineHorizontal(x0+2, y0+3, x0+5, SalmonPink);
			LCD_DrawLineHorizontal(x0+2, y0+4, x0+5, SalmonPink);
			LCD_DrawLineHorizontal(x0+3, y0+5, x0+4, SalmonPink);
			break;
		default:
			break;
	}
	
}

void draw_pacMan_live(uint16_t x0, uint16_t y0, uint16_t color)
{
		LCD_DrawLineHorizontal(x0+4, y0, x0+9,color);
		LCD_DrawLineHorizontal(x0+2, y0+1, x0+11,color);
		LCD_DrawLineHorizontal(x0+1, y0+2, x0+12,color);
		LCD_DrawLineHorizontal(x0+1, y0+3, x0+12,color);
		LCD_DrawLineHorizontal(x0+3, y0+4, x0+13,color);
		LCD_DrawLineHorizontal(x0+6, y0+5, x0+13,color);
		LCD_DrawLineHorizontal(x0+9, y0+6, x0+13,color);//CENTRO
		LCD_DrawLineHorizontal(x0+6, y0+7, x0+13,color);
		LCD_DrawLineHorizontal(x0+3, y0+8, x0+13,color);
		LCD_DrawLineHorizontal(x0+1, y0+9, x0+12,color);
		LCD_DrawLineHorizontal(x0+1, y0+10, x0+12,color);
		LCD_DrawLineHorizontal(x0+2, y0+11, x0+11,color);
		LCD_DrawLineHorizontal(x0+4, y0+12, x0+9,color);
}


void refresh_timer(uint32_t time)
{
	char str[2];
	sprintf(str, "%d", time);
	GUI_Text(96, 7, (uint8_t *) str, White, Black);
}

void refresh_points(uint32_t points)
{
	char str[4];
	sprintf(str, "%d", points);
	GUI_Text(196, 7, (uint8_t *) str, White, Black);
}

void refresh_lives(uint32_t lives)
{
	draw_obj((lives*16),288, 1);
}

void draw_cancel_pause(uint8_t option)
{
	//cancella
	if(option == 0)
	{
		GUI_Text(96, 144, (uint8_t *) "PAUSE!", Black, Black);
	}
	//disegna
	else
	{
		GUI_Text(96, 144, (uint8_t *) "PAUSE!", Yellow, Black);
	}
	
}

void LCD_DrawLineHorizontal(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t color)
{
	while(x0 <= x1){
		LCD_SetPoint(x0, y0, color);
		x0++;
	}
}

//funzione custom che disegna SOLO dal'alto verso il basso
void LCD_DrawLineVertical(uint16_t x0, uint16_t y0, uint16_t y1, uint16_t color)
{
	while(y0 <= y1){
		LCD_SetPoint(x0, y0, color);
		y0++;
	}
}