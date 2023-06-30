/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 30/06/2023      **********************/
/****************************************************************/

/* LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define F_CPU 8000000UL
#include <avr/io.h>

/*MCAL*/
#include "DIO_interface.h"
#include "ADC_interface.h"

/* HAL */
#include "LCD_interface.h"

int main(void) {

	/* Initialization Functions */
	DIO_voidInit();
	LCD_voidInit();
	ADC_voidInit();

	/* Local Variables */
	u16 value;
	f32 voltage;

	/* Super Loop */
	while (1) {

		/* Get Analog Value */
		ADC_u8GetDigitalValueSynchNonBlocking(ADC_u8_CHANNEL_0, &value);
		voltage = value * (5 / 1023.0);

		/* Display voltage value on the LCD */
		LCD_voidSendCmnd(LCD_CLEAR);
		LCD_voidGotoxy(1, 1);
		LCD_voidSendFloat(voltage);
		LCD_voidSendChar('V');

		if (voltage < 1.5) {
			/* RED led on */
			DIO_u8SetPinValue(DIO_u8_PORTC, DIO_u8_PIN0, DIO_u8_HIGH);
			DIO_u8SetPinValue(DIO_u8_PORTC, DIO_u8_PIN1, DIO_u8_LOW);
			DIO_u8SetPinValue(DIO_u8_PORTC, DIO_u8_PIN2, DIO_u8_LOW);
		} else if (voltage >= 1.5 && voltage <= 3) {
			/* YELLOW led on */
			DIO_u8SetPinValue(DIO_u8_PORTC, DIO_u8_PIN0, DIO_u8_LOW);
			DIO_u8SetPinValue(DIO_u8_PORTC, DIO_u8_PIN1, DIO_u8_HIGH);
			DIO_u8SetPinValue(DIO_u8_PORTC, DIO_u8_PIN2, DIO_u8_LOW);
		} else {
			/* GREEN led on */
			DIO_u8SetPinValue(DIO_u8_PORTC, DIO_u8_PIN0, DIO_u8_LOW);
			DIO_u8SetPinValue(DIO_u8_PORTC, DIO_u8_PIN1, DIO_u8_LOW);
			DIO_u8SetPinValue(DIO_u8_PORTC, DIO_u8_PIN2, DIO_u8_HIGH);
		}
	}

	return 0;
}
