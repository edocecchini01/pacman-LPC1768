#include <stdint.h>
#include <stdlib.h>
#include "LPC17xx.h"

void game_tim_init(uint32_t timer, uint32_t speed);

uint32_t single_randonm_gen(uint32_t min, uint32_t max);

void multiple_random_gen(uint32_t n, uint32_t min, uint32_t max, volatile uint32_t *result);
