#include <stdint.h>
#include <stdlib.h>
#include "LPC17xx.h"

uint32_t single_randonm_gen(uint32_t min, uint32_t max);

void multiple_random_gen(uint32_t n, uint32_t min, uint32_t max, uint32_t *result);