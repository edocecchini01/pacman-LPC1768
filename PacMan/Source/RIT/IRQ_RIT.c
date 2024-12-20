/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_RIT.c
** Last modified Date:  2014-09-25
** Last Version:        V1.00
** Descriptions:        functions to manage T0 and T1 interrupts
** Correlated files:    RIT.h
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#include "LPC17xx.h"
#include "RIT.h"
#include "../led/led.h"
#include "game_logic/gameL.h"
#include "timer/timer.h"

/******************************************************************************
** Function name:		RIT_IRQHandler
**
** Descriptions:		REPETITIVE INTERRUPT TIMER handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/
volatile int down_0 = 0;
volatile int down_1 = 0;
volatile int down_2 = 0;

extern game_state gs;

void RIT_IRQHandler (void)
{			
/* Static as its value persists between calls to the function. It is not reinitialized each time the function is executed.*/
static int joystic_up=0;
static int joystic_down=0;
static int joystic_left=0;
static int joystic_right=0;
static int joystic_sel=0;
	
// BUTTON AREA

/*************************INT0***************************/
if(down_0 !=0){   //verifica se una delle down è != 0, implica che è stata scatenata un'interruzione dal relativo pulsante
	down_0++;
	if((LPC_GPIO2->FIOPIN & (1<<10)) == 0){ //leggiamo il segnale, se zero allora il pulsante è premuto
		switch(down_0){
			case 2:     //case a 2 perchè nell'Interrupt handler del pulsante impostiamo down a 1 e qui la incrementiamo nuovamente
				if(gs.isPause == 0)
				{
					gs.isPause = 1;
					pause_resume_game(0);
				}
				else
				{
					gs.isPause = 0;
					pause_resume_game(1);
				}
			
				break;
			default:
				break;
		}
	}
	else {	/* button released */ 
		down_0=0;			
		NVIC_EnableIRQ(EINT0_IRQn);							 /* enable Button interrupts */
		LPC_PINCON->PINSEL4    |= (1 << 20);     /* External interrupt 0 pin selection, lo reimposto in modalità interruzione */
	}
} // end INT0

/*************************KEY1***************************/
if(down_1 !=0){
	down_1++;
	if((LPC_GPIO2->FIOPIN & (1<<11)) == 0){    //leggiamo il segnale
		switch(down_1){
			case 2:
				//your code here
				
				break;
			default:
				break;
		}
	}
	else {	/* button released */
		down_1=0;			
		NVIC_EnableIRQ(EINT1_IRQn);							 /* enable Button interrupts */
		LPC_PINCON->PINSEL4    |= (1 << 22);     /* External interrupt 0 pin selection */
	}
} // end KEY1

/*************************KEY2***************************/
if(down_2 !=0){
	down_2++;
	if((LPC_GPIO2->FIOPIN & (1<<12)) == 0){    //leggiamo il segnale
		switch(down_2){
			//your code here
			
				break;
			default:
				break;
		}
	}
	else {	/* button released */
		down_2=0;		
		NVIC_EnableIRQ(EINT2_IRQn);							 /* enable Button interrupts */
		LPC_PINCON->PINSEL4    |= (1 << 24);     /* External interrupt 0 pin selection */
	}
} // end KEY2

// JOYSTICK AREA	
	
/*************************JOY_UP***************************/
	if((LPC_GPIO1->FIOPIN & (1<<29)) == 0){	
		/* Joytick UP pressed */
		joystic_up++;
		switch(joystic_up){
			case 1:
				gs.actDir = UP;
				break;
			case 60:	//3sec = 3000ms/50ms = 60

				break;
			default:
				break;
		}
	}
	else{
			joystic_up=0;
	}
	
/*************************JOY_DOWN***************************/
	if((LPC_GPIO1->FIOPIN & (1<<26)) == 0){	
		/* Joytick DOWN pressed */
		joystic_down++;
		switch(joystic_down){
			case 1:
				gs.actDir = DOWN;
				break;
			case 60:	//3sec = 3000ms/50ms = 60

				break;
			default:
				break;
		}
	}
	else{
			joystic_down=0;
	}
	
/*************************JOY_LEFT***************************/
	if((LPC_GPIO1->FIOPIN & (1<<27)) == 0){	
		/* Joytick LEFT pressed */
		joystic_left++;
		switch(joystic_left){
			case 1:
				gs.actDir = LEFT;
				break;
			case 60:	//3sec = 3000ms/50ms = 60

				break;
			default:
				break;
		}
	}
	else{
			joystic_left=0;
	}

/*************************JOY_RIGHT***************************/
	if((LPC_GPIO1->FIOPIN & (1<<28)) == 0){	
		/* Joytick RIGHT pressed */
		joystic_right++;
		switch(joystic_right){
			case 1:
			gs.actDir = RIGHT;
				break;
			case 60:	//3sec = 3000ms/50ms = 60

				break;
			default:
				break;
		}
	}
	else{
			joystic_right=0;
	}
	
/*************************JOY_SELECT***************************/
	if((LPC_GPIO1->FIOPIN & (1<<25)) == 0){	
		/* Joytick SELECT pressed */
		joystic_sel++;
		switch(joystic_sel){
			case 1:

				break;
			case 60:	//3sec = 3000ms/50ms = 60

				break;
			default:
				break;
		}
	}
	else{
			joystic_sel=0;
	}
	
	if(gs.actDir != STOP)
	{
		enable_timer(0);
	}
	
	reset_RIT();
  LPC_RIT->RICTRL |= 0x1;	/* clear interrupt flag */
	
  return;
}

/******************************************************************************
**                            End Of File
******************************************************************************/
