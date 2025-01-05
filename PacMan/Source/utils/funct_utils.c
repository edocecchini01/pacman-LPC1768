#include "utils.h"
#include "timer.h"
#include "RIT/RIT.h"

uint32_t single_randonm_gen(uint32_t min, uint32_t max)
{
	int i = 0;
	uint32_t result;
	
	result = rand() % (max - min + 1) + min;
	
	return result;
}

void multiple_random_gen(uint32_t n, uint32_t min, uint32_t max, uint32_t *result)
{
	int i = 0;

  for (i = 0; i < n; i++) {
		result[i] = rand() % (max - min + 1) + min;
  }
}