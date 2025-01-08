#include <stdint.h>
#include "joystick/joystick.h"

//struttura per la gestione dinamica dell'intero gioco
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

//struttura per contenere i dati randomici delle Power Pills
volatile typedef struct {
    uint32_t powerPill_Row[6];
		uint32_t powerPill_Col[6];
		uint32_t powerPill_Tim;
	} random_init;

void game_init();

void draw_backgoround(uint32_t off_X, uint32_t off_Y);

void move_pacMan(int movRow, int movCol);

void direct_pacMan(Direction direction);

void init_powerPills();

void gen_powerPills();

void add_score(uint32_t points);

void pause_resume_game(uint8_t state);

void end_game(uint8_t win);