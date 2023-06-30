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

/* delay function */
void delay_ms(uint16_t milliseconds)
{
    while (milliseconds--)
    {
        _delay_ms(1);
    }
}

int main(void) {

	/* Initialization Functions */
	DIO_voidInit();
	LCD_voidInit();
	ADC_voidInit();

	/* Local Variables */
	/* Variable to get the ADC Digital value */
	u16 Local_u16ADCDigitalValue = 0;
	/* Variable to save the temperature value in C */
	u16 Local_u16TempValue = 0;
	/* Variable to save the temperature value in mv */
	u16 Local_u16TempValuemv = 0;

	LCD_voidSendString("Temperature =");

	/* Super Loop */
	while (1) {

		ADC_u8GetDigitalValueSynchNonBlocking(ADC_u8_CHANNEL_0, &Local_u16ADCDigitalValue);
		Local_u16TempValuemv = ((Local_u16ADCDigitalValue * 5000UL) / 1024);
		Local_u16TempValue = Local_u16TempValuemv / 10;

		LCD_voidGotoxy(1, 14);
		LCD_voidSendString("   ");
		LCD_voidGotoxy(1, 14);
		LCD_voidSendIntger(Local_u16TempValue);

		while (Local_u16TempValue >= 60) {

			DIO_u8SetPinValue( DIO_u8_PORTC, DIO_u8_PIN1, DIO_u8_HIGH);
			DIO_u8SetPinValue( DIO_u8_PORTC, DIO_u8_PIN2, DIO_u8_HIGH);

			DIO_u8SetPinValue( DIO_u8_PORTC, DIO_u8_PIN0, DIO_u8_HIGH);
			delay_ms(500);
			DIO_u8SetPinValue( DIO_u8_PORTC, DIO_u8_PIN0, DIO_u8_LOW);
			delay_ms(500);

			LCD_voidGotoxy(1, 14);
			LCD_voidSendString("   ");
			LCD_voidGotoxy(1, 14);
			LCD_voidSendIntger(Local_u16TempValue);

			ADC_u8GetDigitalValueSynchNonBlocking(ADC_u8_CHANNEL_0, &Local_u16ADCDigitalValue);
			Local_u16TempValuemv = ((Local_u16ADCDigitalValue * 5000UL) / 1024);
			Local_u16TempValue = Local_u16TempValuemv / 10;
		}
		DIO_u8SetPinValue( DIO_u8_PORTC, DIO_u8_PIN0, DIO_u8_LOW);
		DIO_u8SetPinValue( DIO_u8_PORTC, DIO_u8_PIN1, DIO_u8_LOW);
		DIO_u8SetPinValue( DIO_u8_PORTC, DIO_u8_PIN2, DIO_u8_LOW);
	}

	return 0;
}
