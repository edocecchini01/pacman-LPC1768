#include <stdint.h>
#include "joystick/joystick.h"

typedef struct {
    int posPac_Row;	//y
		int posPac_Col;	//x
		uint32_t countDown;
		uint32_t score;
		volatile Direction actDir;
} game_state;

void draw_backgoround(uint32_t off_X, uint32_t off_Y);

void count_down();

void tim_PacMan(uint32_t speed);

void game_init();

void direct_pacMan(Direction direction);

void move_pacMan(int movRow, int movCol);

void add_score(uint32_t points);

void mod_objMat(uint32_t i, uint32_t j, uint32_t new_obj);