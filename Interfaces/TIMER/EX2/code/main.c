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
#include "GI_interface.h"
#include "timer_interface.h"

/* delay function */
void delay_ms(uint16_t milliseconds) {
	while (milliseconds--) {
		_delay_ms(1);
	}
}

/* Functions Declaration */
void App_voidTogLed(void);

int main(void) {

	/* Initialization Functions */
	DIO_voidInit();
	GI_voidEnable();

	/* TIMER set call back */
	TIMER_u8Timer0SetCallBackOCR(&App_voidTogLed);

	/* Start timer */
	TIMER_voidTimer0Init();

	/* Local Variables */

	/* Super Loop */
	while (1) {

	}

	return 0;
}

void App_voidTogLed(void) {
	static u8 flag = 0;
	if (flag == 0) {
		DIO_u8SetPinValue(DIO_u8_PORTC, DIO_u8_PIN0, DIO_u8_HIGH);
		flag = 1;
	} else {
		DIO_u8SetPinValue(DIO_u8_PORTC, DIO_u8_PIN0, DIO_u8_LOW);
		flag = 0;
	}
}
