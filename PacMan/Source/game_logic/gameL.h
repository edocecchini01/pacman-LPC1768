#include <stdint.h>
#include "joystick/joystick.h"

typedef struct {
    uint32_t posPac_X;
		uint32_t posPac_Y;
		uint32_t countDown;
		Direction actPos;
} game_state;

void draw_backgoround(uint32_t off_X, uint32_t off_Y);

void draw_objMat(uint32_t off_X, uint32_t off_Y);

void count_down();

void init_UI();

void move_pacMan(game_state gs, uint32_t dX, uint32_t dY);

void direct_pacMan(Direction direction);

void mod_objMat(uint32_t i, uint32_t j, uint32_t new_obj);