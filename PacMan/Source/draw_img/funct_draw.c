#include "draw.h"
#include "game_logic/gameL.h"

#define ROWS 31
#define COLUMNS 28

//LCD_SetPoint(uint16_t Xpos,uint16_t Ypos,uint16_t point);
//LCD_DrawLine( uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1 , uint16_t color );

volatile const uint8_t loose_screen[ROWS][COLUMNS] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 4, 0, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

volatile const uint8_t win_screen[31][28] = {
    {3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3},
    {3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3},
    {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
    {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 3, 0, 3, 3, 3, 0, 3, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 3, 0, 0, 3, 3, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 3, 0, 3, 0, 3, 0, 0, 3, 0, 0, 3, 0, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 3, 3, 0, 3, 3, 0, 0, 3, 0, 0, 3, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 3, 0, 3, 3, 3, 0, 3, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 4, 0, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 0, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 4, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 4, 4, 4, 0, 0, 0, 4, 4, 4, 0, 0},
    {0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 4, 0, 0, 0, 0, 0, 4, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {3, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 3},
    {3, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 3},
    {3, 3, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3},
    {3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3},
};

extern mapOff[2];
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

void draw_scalPixel(uint16_t x0, uint16_t y0, uint16_t color) //quadrato 8x8
{
	int i = 0;
	uint16_t selColor = 0;
	
	switch(color){
				case 0:
					selColor = Black;
				break;
				case 1:
					selColor = Red;
				break;
				case 2:
					selColor = Blue;
				break;
				case 3:
					selColor = Yellow;
				break;
				case 4:
					selColor = White;
				break;
				default:
					selColor = Black;
				break;
			}
	
	for(i = 0; i<8; i++)
	{
		LCD_DrawLineHorizontal(x0,y0+i,x0+7,selColor);
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
		case 4: //POWERPILLS
			LCD_DrawLineHorizontal(x0+2, y0+1, x0+5, Red);
			LCD_DrawLineHorizontal(x0+1, y0+2, x0+6, Red);
			LCD_DrawLineHorizontal(x0+1, y0+3, x0+6, Red);
			LCD_DrawLineHorizontal(x0+1, y0+4, x0+6, Red);
			LCD_DrawLineHorizontal(x0+1, y0+5, x0+6, Red);
			LCD_DrawLineHorizontal(x0+2, y0+6, x0+5, Red);
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
	if(time < 10)
	{
		draw_scalPixel(104, 7, 0);
		draw_scalPixel(104, 15, 0);
	}
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
	draw_pacMan_live((lives*16),288, Yellow);
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

void draw_win_loose_screen(uint8_t win)
{
	int i = 0, j = 0;
	
	if(win == 1)
	{
		for(i=0; i<ROWS; i++){
			for(j=0; j<COLUMNS ;j++){		
				draw_scalPixel((j*8)+mapOff[0],(i*8)+mapOff[1],win_screen[i][j]);
			}
		}
	}
	else
	{
		for(i=0; i<ROWS; i++){
			for(j=0; j<COLUMNS ;j++){		
				draw_scalPixel((j*8)+mapOff[0],(i*8)+mapOff[1],loose_screen[i][j]);
			}
		}
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