/*****************************************************************************/
/***************  Name   : Mohamed Khodary 				**********************/
/***************  Date   : 3/08/2023      				**********************/
/***************  SWC    : Multiplexed 4 Digits 7-Seg   **********************/
/*************** Version : 1.0         				    **********************/
/*****************************************************************************/

/* Lib layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "FourDigits7Seg_interface.h"

/* defines */
#define F_CPU 8000000UL

/*flags */

/* functions declaration */
/* delay function */
void delay_ms(uint16_t milliseconds);
/* main */
int main(void) {
	DIO_voidInit();


	u16 counter;
	for(counter=0; counter<=9999;counter++){
				FourDigits7Seg_u8SendNumber(counter);
				delay_ms(50);
	}


	while (1) {



	};
	return 0;
}

/* Function Initialization */
void delay_ms(uint16_t milliseconds) {
	while (milliseconds--) {
		_delay_ms(1);
	}
}
