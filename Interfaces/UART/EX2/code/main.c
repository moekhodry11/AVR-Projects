/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 012/07/2023      **********************/
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
#include "UART_interface.h"

/* HAL */

/* Functions Declaration */
void delay_ms(u16 milliseconds);
int main(void) {

	/* Initialization Functions */
	DIO_voidInit();
	UART_voidinit();

	/* Local Variables */
	u8 data;

	/* Super Loop */
	while (1) {
		UART_void_resive_databyte(&data);
		if(data=='a')
			DIO_u8SetPinValue(DIO_u8_PORTC, DIO_u8_PIN0, DIO_u8_HIGH);
		else if(data=='b')
			DIO_u8SetPinValue(DIO_u8_PORTC, DIO_u8_PIN0, DIO_u8_LOW);
	}

	return 0;
}

/* Functions Implementation */
void delay_ms(u16 milliseconds) {
	while (milliseconds--) {
		_delay_ms(1);
	}
}
