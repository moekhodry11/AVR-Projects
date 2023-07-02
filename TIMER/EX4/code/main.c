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
void sevo(u8 x);

int main(void) {

	/* Initialization Functions */
	DIO_voidInit();

	/* Start timer */
	TIMER_voidTimer1Init();

	/* period of servo motor 20ms */
	TIMER_voidTimer1SetInputCaptureValue(19999);

	/* Local Variables */

	/* Super Loop */
	while (1) {

		/* duty cycle of servo motor form 0 to 2ms */
		for (int i = 0; i <= 180; i++) {
			sevo(i);
			_delay_us(500);
		}
		delay_ms(1000);

		for (int i = 180; i >= 0; i--) {
			sevo(i);
			_delay_us(500);
		}
		delay_ms(1000);


	}

	return 0;
}


/* servo map function */
void sevo(u8 x) {//input is and angel form 0 to 180 and output is scale from 999 to 1999
  f32 mapped= (x - 0) * (1999.0 - 999.0) / (180.0 - 0) + 999.0;
  TIMER_voidTimer1ASetCompareValue((u16)mapped);
}
