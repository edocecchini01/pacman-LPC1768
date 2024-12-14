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
	// your code here
	
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

char str[2];

void TIMER1_IRQHandler (void)
{
	gs.countDown = gs.countDown - 1;
	sprintf(str, "%d", gs.countDown);
	GUI_Text(96, 7, (uint8_t *) str, White, Black);
	
	LPC_TIM1->IR |= 1;
  return;
}

void TIMER2_IRQHandler (void)
{
	//your code here
	
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
