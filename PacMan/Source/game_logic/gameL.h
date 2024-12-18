#include <stdint.h>
#include "joystick/joystick.h"

typedef struct {
    uint32_t posPac_Row;	//y
		uint32_t posPac_Col;	//x
		uint32_t countDown;
		Direction actDir;
} game_state;

void draw_backgoround(uint32_t off_X, uint32_t off_Y);

void count_down();

void tim_PacMan(uint32_t speed);

void game_init();

void move_pacMan(game_state gs, uint32_t newCol, uint32_t newRow);

void direct_pacMan(Direction direction);

void mod_objMat(uint32_t i, uint32_t j, uint32_t new_obj);