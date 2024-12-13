#include "utils.h"
#include "timer.h"

void wait_milli(uint32_t time)
{
	uint32_t count = (time * 25000000)/1000;
	init_timer(0, 0, count);
	enable_timer(0);
	
	while(LPC_TIM0->TC < count){
		//wait
	}
	
	disable_timer(0);
}