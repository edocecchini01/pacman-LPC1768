#include <stdint.h>
#include "joystick/joystick.h"

typedef struct {
    int posPac_Row;	//y
		int posPac_Col;	//x
		uint32_t countDown;
		uint32_t score;
		uint32_t lives;
		Direction actDir;
		uint8_t isPause;
} game_state;

void draw_backgoround(uint32_t off_X, uint32_t off_Y);

void count_down();

void game_tim_init(uint32_t timer, uint32_t speed);

void game_init();

void direct_pacMan(Direction direction);

void move_pacMan(int movRow, int movCol);

void add_score(uint32_t points);

void refresh_screen();

void pause_resume_game(uint8_t state);