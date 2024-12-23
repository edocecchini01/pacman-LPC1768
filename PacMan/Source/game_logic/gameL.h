#include <stdint.h>
#include "joystick/joystick.h"

volatile typedef struct {
    int posPac_Row;	//y
		int posPac_Col;	//x
		uint32_t countDown;
		uint32_t score;
		uint32_t lives;
		uint32_t next_life_threshold;
		Direction actDir;
		uint8_t isPause;
} game_state;

volatile typedef struct {
    uint8_t changeScore;
		uint8_t changeTime;
		uint8_t changeLive;
} GUI_changes;

void draw_backgoround(uint32_t off_X, uint32_t off_Y);

void count_down();

void game_tim_init(uint32_t timer, uint32_t speed);

void game_init();

void direct_pacMan(Direction direction);

void move_pacMan(int movRow, int movCol);

void add_score(uint32_t points);

void refresh_screen();

void pause_resume_game(uint8_t state);