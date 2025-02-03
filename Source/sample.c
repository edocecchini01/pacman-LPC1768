/****************************************Copyright (c)****************************************************
**                                      
**                                 http://www.powermcu.com
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               main.c
** Descriptions:            Pac-Man
**
**--------------------------------------------------------------------------------------------------------
** Created by:              Edoardo Cecchini
** Created date:            2024-2025
** Version:                 v1.0
** Descriptions:            Part 1
**
*********************************************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "LPC17xx.h"
#include "button_EXINT/button.h"
#include "GLCD/GLCD.h" 
#include "timer/timer.h"
#include "RIT/RIT.h"
#include "draw_img/draw.h"
#include "game_logic/gameL.h"
#include "utils/utils.h"


#ifdef SIMULATOR
extern uint8_t ScaleFlag; // <- ScaleFlag needs to visible in order for the emulator to find the symbol (can be placed also inside system_LPC17xx.h but since it is RO, it needs more work)
#endif

volatile const mapOff[2] = {8,32}; //offset x,y necessari per disegnare correttamente la mappa di gioco

volatile game_state gs = {
		.posPac_Row = 0,
		.posPac_Col = 0,
		.countDown = 60,
		.score = 0,
		.lives = 1,
		.next_life_threshold = 1000,
		.actDir = STOP,
		.isPause = 1,
		.isPowerGen = 0,
		.changeScoreUI = 0
};

volatile random_init rand_init = {
	.powerPill_Row = 0,
	.powerPill_Col = 0,
	.powerPill_Tim = 0
};

int main(void)
{
  SystemInit();  												/* System Initialization (i.e., PLL)  */
  BUTTON_init();												/* BUTTON Initialization              */
	joystick_init();											/* Joystick Initialization            */
	init_RIT(0x004C4B40);								  /* RIT Initialization 50 msec       	*/
	enable_RIT();
	
  LCD_Initialization();									
	
	LCD_Clear(Black);
	
	draw_backgoround(mapOff[0], mapOff[1]);			//visualizzazione su schermo della mappa di gioco
	
	game_init();			//init dei Timer e della UI
	
	srand((LPC_RIT->RICOUNTER ^ LPC_TIM0->TC) & 0xFFFFFFFF);		//set del seed per la randomizzazione delle Power Pills
	
	init_powerPills();			//generazione randomica delle coordinate e tempo di creazione delle Power Pills
	
	pause_resume_game(0);		//inizio in pausa
	
	LPC_SC->PCON |= 0x1;									/* power-down	mode										*/
	LPC_SC->PCON &= ~(0x2);						
	
  while (1)	
  {
		__ASM("wfi");
  }
}

/*********************************************************************************************************
      END FILE
*********************************************************************************************************/
