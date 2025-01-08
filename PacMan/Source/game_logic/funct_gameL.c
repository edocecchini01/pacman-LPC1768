#include "gameL.h"
#include "draw_img/draw.h"
#include "timer/timer.h"
#include "RIT/RIT.h"

//NOTA: il display è ruotato

#define ROWS 31
#define COLUMNS 28

volatile uint8_t obj_matrix[ROWS][COLUMNS] = {
    {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
    {2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2},
    {2, 3, 2, 2, 2, 2, 3, 2, 2, 2, 2, 2, 3, 2, 2, 3, 2, 2, 2, 2, 2, 3, 2, 2, 2, 2, 3, 2},
    {2, 3, 2, 2, 2, 2, 3, 2, 2, 2, 2, 2, 3, 2, 2, 3, 2, 2, 2, 2, 2, 3, 2, 2, 2, 2, 3, 2},
    {2, 3, 2, 2, 2, 2, 3, 2, 2, 2, 2, 2, 3, 2, 2, 3, 2, 2, 2, 2, 2, 3, 2, 2, 2, 2, 3, 2},
    {2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2},
    {2, 3, 2, 2, 2, 2, 3, 2, 2, 3, 2, 2, 2, 2, 2, 2, 2, 2, 3, 2, 2, 3, 2, 2, 2, 2, 3, 2},
    {2, 3, 2, 2, 2, 2, 3, 2, 2, 3, 2, 2, 2, 2, 2, 2, 2, 2, 3, 2, 2, 3, 2, 2, 2, 2, 3, 2},
    {2, 3, 3, 3, 3, 3, 3, 2, 2, 3, 3, 3, 3, 2, 2, 3, 3, 3, 3, 2, 2, 3, 3, 3, 3, 3, 3, 2},
    {2, 2, 2, 2, 2, 2, 3, 2, 2, 2, 2, 2, 0, 2, 2, 0, 2, 2, 2, 2, 2, 3, 2, 2, 2, 2, 2, 2},
    {0, 0, 0, 0, 0, 2, 3, 2, 2, 2, 2, 2, 0, 2, 2, 0, 2, 2, 2, 2, 2, 3, 2, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 2, 3, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 3, 2, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 2, 3, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 3, 2, 0, 0, 0, 0, 0},
    {2, 2, 2, 2, 2, 2, 3, 2, 2, 0, 2, 0, 0, 0, 0, 0, 0, 2, 0, 2, 2, 3, 2, 2, 2, 2, 2, 2},
    {0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0},
    {2, 2, 2, 2, 2, 2, 3, 2, 2, 0, 2, 0, 0, 0, 0, 0, 0, 2, 0, 2, 2, 3, 2, 2, 2, 2, 2, 2},
    {0, 0, 0, 0, 0, 2, 3, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 3, 2, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 2, 3, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 3, 2, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 2, 3, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 3, 2, 0, 0, 0, 0, 0},
    {2, 2, 2, 2, 2, 2, 3, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 3, 2, 2, 2, 2, 2, 2},
    {2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2},
    {2, 3, 2, 2, 2, 2, 3, 2, 2, 2, 2, 2, 3, 2, 2, 3, 2, 2, 2, 2, 2, 3, 2, 2, 2, 2, 3, 2},
    {2, 3, 2, 2, 2, 2, 3, 2, 2, 2, 2, 2, 3, 2, 2, 3, 2, 2, 2, 2, 2, 3, 2, 2, 2, 2, 3, 2},
    {2, 3, 3, 3, 2, 2, 3, 0, 0, 3, 3, 3, 3, 1, 0, 3, 3, 3, 3, 0, 0, 3, 2, 2, 3, 3, 3, 2},
    {2, 2, 2, 3, 2, 2, 3, 0, 0, 3, 2, 2, 2, 2, 2, 2, 2, 2, 3, 0, 0, 3, 2, 2, 3, 2, 2, 2},
    {2, 2, 2, 3, 2, 2, 3, 2, 2, 3, 2, 2, 2, 2, 2, 2, 2, 2, 3, 2, 2, 3, 2, 2, 3, 2, 2, 2},
    {2, 3, 3, 3, 3, 3, 3, 2, 2, 3, 3, 3, 3, 2, 2, 3, 3, 3, 3, 2, 2, 3, 3, 3, 3, 3, 3, 2},
    {2, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 2, 2, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 2},
    {2, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 2, 2, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 2},
    {2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2},
    {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
};

/*
	OBJECT_CODES
	
	corridoio -> 0
	pacman -> 1
	muro -> 2
	pallina -> 3
	mega-pallina -> 4
	??fantasmino
*/


volatile const uint8_t back_matrix[ROWS][COLUMNS] = {
	
	  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1},
    {1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1},
    {1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
			
	};


extern game_state gs;
extern mapOff[];
extern random_init rand_init;

/*
	game_tim_init GUIDE:
	
	TIM0 -> PACMAN
	TIM1 -> COUNTDOWN
	TIM2 -> REFRESH SCREEN
*/

void game_tim_init(uint32_t timer, uint32_t speed) //in milliseconds
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

void game_init()
{
	game_initUI();
	game_tim_init(0,200);	//PACMAN SPEED MOVMENT SET TO 250ms
	game_tim_init(1,1000); //START COUNTDOWN
	game_tim_init(2,500); //START REFRESH SYSTEM
}

void draw_backgoround(uint32_t off_X, uint32_t off_Y)
{
	int i = 0, j = 0;
	
	for(i=0; i<ROWS; i++){
		for(j=0; j<COLUMNS ;j++){
			switch(back_matrix[i][j]){
				case 0:		
				break;
				case 1:
					draw_scalPixel((j*8)+off_X,(i*8)+off_Y,2); //muro blu
				break;
				case 2:
					//draw_tail_2((i+off_X)*7,(j+off_Y)*7);
				break;
				default:
				break;
			}
			
			//draw pacman
			if(obj_matrix[i][j] == 1)
			{
				draw_obj((j*8)+off_X,(i*8)+off_Y, 1);
				gs.posPac_Row = i;
				gs.posPac_Col = j;
			}
			
			//draw the pills
			if(obj_matrix[i][j] == 3)
			{
				draw_obj((j*8)+off_X,(i*8)+off_Y, 3);
			}
		}
	}
	
}

void move_pacMan(int movRow, int movCol)
{
	gs.changeScoreUI = 0;
	int newPosRow = gs.posPac_Row + movRow;
  int newPosCol = gs.posPac_Col + movCol;
	
	//gestione teletrasporto
	
	if(newPosCol > 27)
	{
		newPosCol = 0;
	}
	else if(newPosCol < 0)
	{
		newPosCol = 27;
	}
	
	if(obj_matrix[newPosRow][newPosCol] == 2)  // la nuova posizione è un muro
  {
		gs.actDir = STOP;
		return;
  }
	else
	{
		if(obj_matrix[newPosRow][newPosCol] == 3) //standard pill
		{
			add_score(10);
			gs.changeScoreUI = 1;
		}
		else if(obj_matrix[newPosRow][newPosCol] == 4) //power pill
		{
			add_score(50);
			gs.changeScoreUI = 1;
		}
		
		draw_obj((gs.posPac_Col * 8)+ mapOff[0], (gs.posPac_Row * 8)+ mapOff[1], 0);  // Cancella nella vecchia posizione
    obj_matrix[gs.posPac_Row][gs.posPac_Col] = 0;	//setta 0 nella posizione attuale della matrice degli oggetti
		
		if(movCol == 0)  // Movimento lungo le righe (Y)
    {
			draw_obj((gs.posPac_Col * 8) + mapOff[0], (newPosRow * 8) + mapOff[1], 1);  // Crea pacman nella nuova posizione
    }
    else  // Movimento lungo le colonne (X)
    {
			draw_obj((newPosCol * 8) + mapOff[0], (gs.posPac_Row * 8) + mapOff[1], 1);  // Crea pacman nella nuova posizione
    }
		
		gs.posPac_Row = newPosRow;
		gs.posPac_Col = newPosCol;
		obj_matrix[gs.posPac_Row][gs.posPac_Col] = 1;	//sposta pacman nella nuova posizione, nella matrice degli oggetti
		
	}
	
}

void direct_pacMan(Direction direction)
{
	switch(direction){
		case LEFT:
			move_pacMan(0, -1);
			break;
		case RIGHT:
			move_pacMan(0, 1);
			break;
		case UP:
			move_pacMan(-1, 0);
			break;
		case DOWN:
			move_pacMan(1, 0);
			break;
		default:
			break;
	}
}

void init_powerPills()
{
	multiple_random_gen(6, 1, COLUMNS-2, rand_init.powerPill_Col);
	multiple_random_gen(6, 1, ROWS-2, rand_init.powerPill_Row);
	rand_init.powerPill_Tim = single_randonm_gen(1,15);
}

void gen_powerPills()
{
	int i = 0;
	uint32_t actRow = 0;
	uint32_t actCol = 0;
	for(i=0;i<6;i++)
	{
		actRow = rand_init.powerPill_Row[i];
		actCol = rand_init.powerPill_Col[i];
		while (obj_matrix[actRow][actCol] != 3) {
			actRow++;
			if(actRow == ROWS-2)
			{
				if(actCol < COLUMNS-2)
				{
					actRow = 1;
					actCol++;
				}else{
					actRow = 1;
					actCol = 1;
				}
			}
		}
		obj_matrix[actRow][actCol] = 4;
		draw_obj((actCol * 8)+ mapOff[0], (actRow * 8)+ mapOff[1], 4);
	}
	gs.isPowerGen = 1;
}

void add_score(uint32_t points)
{
	gs.score += points;
	if(gs.score >= gs.next_life_threshold)
	{
		gs.lives += 1;
		gs.next_life_threshold += 1000;
		
		uint32_t actLives = gs.lives;
		refresh_lives(actLives);
	}
	
	if(gs.score >= 2640)
	{
		end_game(1);
	}
}

void pause_resume_game(uint8_t state)
{
	//THE GAME IS ACTIVE
	if(state == 0)
	{
		//NVIC_DisableIRQ(EINT0_IRQn);
		disable_timer(0);
		disable_timer(1);
		disable_timer(2);
		draw_cancel_pause(1);
		reset_RIT();
		//NVIC_EnableIRQ(EINT0_IRQn);
	}
	//GAME IS IN PAUSE
	else 
	{
		//NVIC_DisableIRQ(EINT0_IRQn);
		draw_cancel_pause(0);
		reset_RIT();
		enable_timer(0);
		enable_timer(1);
		enable_timer(2);
		//NVIC_EnableIRQ(EINT0_IRQn);
  }
}

void end_game(uint8_t win)
{
		NVIC_DisableIRQ(EINT0_IRQn);
		disable_timer(0);
		disable_timer(1);
		disable_timer(2);
		disable_RIT();
		draw_win_loose_screen(win);
}