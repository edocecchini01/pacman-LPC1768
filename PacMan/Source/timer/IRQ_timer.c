/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_timer.c
** Last modified Date:  2014-09-25
** Last Version:        V1.00
** Descriptions:        functions to manage T0 and T1 interrupts
** Correlated files:    timer.h
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#include <string.h>
#include "LPC17xx.h"
#include "timer.h"
#include "../GLCD/GLCD.h" 
#include "../TouchPanel/TouchPanel.h"
#include "game_logic/gameL.h"
#include <stdio.h> /*for sprintf*/

extern game_state gs;
extern random_init rand_init;

/******************************************************************************
** Function name:		Timer0_IRQHandler
**
** Descriptions:		Timer/Counter 0 interrupt handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/

void TIMER0_IRQHandler (void)
{
	if(gs.actDir != STOP)
	{
		Direction currentDir = gs.actDir;
		direct_pacMan(currentDir);
  }
	
	//reset_RIT();					//gestice il bug dell'emulatore
  LPC_TIM0->IR = 1;			/* clear interrupt flag */
  return;
}


/******************************************************************************
** Function name:		Timer1_IRQHandler
**
** Descriptions:		Timer/Counter 1 interrupt handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/


void TIMER1_IRQHandler (void)
{
	gs.countDown = gs.countDown - 1;
	
	if(gs.countDown <= (60-rand_init.powerPill_Tim) && gs.isPowerGen == 0)
	{
		gen_powerPills();
	}
	
	if(gs.countDown <= 0)
	{
		end_game(0);
	}
	
	uint32_t actTime = gs.countDown;
	refresh_timer(actTime);
	
	LPC_TIM1->IR |= 1;
  return;
}

void TIMER2_IRQHandler (void)
{
	
	if(gs.changeScoreUI == 1)
	{
			uint32_t actPoints = gs.score;
			refresh_points(actPoints);
			gs.changeScoreUI = 0;
	}
	
	LPC_TIM2->IR |= 1;
  return;
}

void TIMER3_IRQHandler (void)
{
	//your code here
	
	LPC_TIM3->IR |= 1;
  return;
}

/******************************************************************************
**                            End Of File
******************************************************************************/
