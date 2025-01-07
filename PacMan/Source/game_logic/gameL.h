#include <stdint.h>
#include "joystick/joystick.h"

volatile typedef struct {
    uint32_t powerPill_Row[6];
		uint32_t powerPill_Col[6];
		uint32_t powerPill_Tim;
	} random_init;

volatile typedef struct {
    int posPac_Row;	//y
		int posPac_Col;	//x
		uint32_t countDown;
		uint32_t score;
		uint32_t lives;
		uint32_t next_life_threshold;
		Direction actDir;
		uint8_t isPause;
		uint8_t isPowerGen;
		uint8_t changeScoreUI;
} game_state;

void draw_backgoround(uint32_t off_X, uint32_t off_Y);

void count_down();

void game_tim_init(uint32_t timer, uint32_t speed);

void game_init();

void direct_pacMan(Direction direction);

void move_pacMan(int movRow, int movCol);

void init_powerPills();

void gen_powerPills();

void add_score(uint32_t points);

void pause_resume_game(uint8_t state);

void end_game(uint8_t win);