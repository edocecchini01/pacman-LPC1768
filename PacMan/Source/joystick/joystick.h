																			 /*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           joystick.h
** Last modified Date:  2018-12-30
** Last Version:        V1.00
** Descriptions:        Prototypes of functions included in the lib_joystick, funct_joystick .c files
** Correlated files:    lib_joystick.c, funct_joystick.c
**--------------------------------------------------------------------------------------------------------       
*********************************************************************************************************/

typedef enum {
		STOP = 0,
    LEFT = 1,
    RIGHT = 2,
    UP = 3,
    DOWN = 4
} Direction;

/* lib_joystick */
void joystick_init(void);
