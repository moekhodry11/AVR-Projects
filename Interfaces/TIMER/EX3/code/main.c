/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 01/07/2023      **********************/
/****************************************************************/

/* Defines */
#define F_CPU 8000000UL

/* LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <avr/io.h>
#include "util/delay.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*MCAL*/
#include "DIO_interface.h"

/* HAL */

/* delay function */
void delay_ms(uint16_t milliseconds) {
	while (milliseconds--) {
		_delay_ms(1);
	}
}

/* Functions Declaration */

int main(void) {

	/* Initialization Functions */
	DIO_voidInit();


	/* Start timer */
	TIMER_voidTimer0Init();

	/* Local Variables */

	/* Super Loop */
	while (1) {
		for(int i=0; i<256; i++){
			TIMER_voidTimer0SetCompareValue(i);
			_delay_us(10);
		}

		for(int i=255; i>=0; i--){
					TIMER_voidTimer0SetCompareValue(i);
					_delay_us(10);
				}

	}

	return 0;
}
