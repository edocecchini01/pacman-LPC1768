#include "utils.h"
#include "timer.h"
#include "RIT/RIT.h"

//funzione che inizializza un timer con il tempo in millisecondi fornito in input (speed)
void game_tim_init(uint32_t timer, uint32_t speed)
{
	uint32_t count = speed * 25000;
	
	switch (timer){
		case 0:
			init_timer(timer, 0, count);
			enable_timer(timer);
			break;
		case 1:
			init_timer(timer, 0, count);
			enable_timer(timer);
			break;
		case 2:
			init_timer(timer, 0, count);
			enable_timer(timer);
			break;
		default:
			init_timer(0, 0, count);
			enable_timer(0);
	}
}

//funzione che genera un singolo valore random entro un intervallo
uint32_t single_randonm_gen(uint32_t min, uint32_t max)
{
	int i = 0;
	uint32_t result;
	
	result = rand() % (max - min + 1) + min;
	
	return result;
}

//funzione che genera un array di valori random entro un certo intervallo
void multiple_random_gen(uint32_t n, uint32_t min, uint32_t max, volatile uint32_t *result)
{
	int i = 0;

  for (i = 0; i < n; i++) {
		result[i] = rand() % (max - min + 1) + min;
  }
}