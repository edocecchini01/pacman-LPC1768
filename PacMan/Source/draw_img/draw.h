#include <stdint.h>
#include <stdio.h>
#include "GLCD/GLCD.h"

void LCD_DrawLineVertical(uint16_t x0, uint16_t y0, uint16_t y1, uint16_t color);

void LCD_DrawLineHorizontal(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t color);

void draw_tail_1(uint16_t x0, uint16_t y0);

void draw_tail2(uint16_t x0, uint16_t y0);

void draw_scalPixel(uint16_t x0, uint16_t y0, uint16_t color);

void draw_obj(uint16_t x0, uint16_t y0, uint16_t obj);

void game_initUI();

void draw_pacMan_live(uint16_t x0, uint16_t y0, uint16_t color);

void refresh_timer(uint32_t time);

void refresh_points(uint32_t points);

void refresh_lives(uint32_t lives);

void draw_cancel_pause(uint8_t option);

void draw_win_loose_screen(uint8_t win);

