/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 01/10/2023      **********************/
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
#include "LCD_interface.h"
#include "I2C_interface.h"

/* HAL */

/* Functions Declaration */
void delay_ms(u16 milliseconds);

int main(void) {

	/* Initialization Functions */
	DIO_voidInit();
	LCD_voidInit();
	I2C_voidMasterInit();

	/* Local Variables */
	u8 u8LocaReturnData;


	/* Write data on EEPROM */
	EEPROM_u8WriteDataByte(2, 23);

	/* You have to wait some time before read the data */
	delay_ms(10);

	/* Read data from EEPROM */
	EEPROM_u8ReadDataByte(2, &u8LocaReturnData);

	/* Print data on the LCD */
	LCD_voidSendIntger(u8LocaReturnData);

	/* Super Loop */
	while (1) {

	}

	return 0;
}

/* Functions Implementation */
void delay_ms(u16 milliseconds) {
	while (milliseconds--) {
		_delay_ms(1);
	}
}
