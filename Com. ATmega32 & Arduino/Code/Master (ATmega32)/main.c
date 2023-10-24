/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 24/10/2023      **********************/
/***************  MC     : ATmega32       **********************/
/***************  SWC    : RTC_Master  	   **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

/* Lib layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "UART_Interface.h"
#include "I2C_interface.h"
#include "RTC_interface.h"

/* Defines */
#undef F_CPU
#define F_CPU 16000000UL //setting CPU clock to 16MHz

/* main function */
int main(void) {

	/* Initializations */
	DIO_voidInit();
	LCD_voidInit();
	UART_enu_Init();
	RTC_vidInit();

	LCD_voidGotoxy(0,5);
	LCD_voidSendString("RTC Master");

	/*
	 * My RTC struct variables
	 typedef struct {
	 u8 u8Seconds;
	 u8 u8Minutes;
	 u8 u8Hours;
	 u8 u8DayOfWeek;
	 u8 u8Days;
	 u8 u8Months;
	 u16 u8Years;
	 } RTC_t;
	 */

	/* Setting time
	 * You have two ways to set time(accessing struct)
	 * */
	RTC_t rtc;
	//RTC_t rtc = { 57, 53, 1, 1, 24, 10, 2023 }; //Comment this line after setting the time
	//RTC_vidSetTime(&rtc);//Comment this line after setting the time

	/*
	 * Or you can use this
	 *  rtc.u8Seconds = 57;
	 *	rtc.u8Minutes = 59;
	 *	rtc.u8Hours   = 5;
	 */


	/* My Special Characters */
	u8 Local_u8SpecialCharacterStand[] = { 0x0E, 0x0A, 0x0E, 0x15, 0x15, 0x04, 0x0A, 0x0A};
	u8 Local_u8SpecialCharacterLeft[]  = { 0x00, 0x00, 0x0E, 0x1B, 0x0E, 0x04, 0x1E, 0x02};
	u8 Local_u8SpecialCharacterRight[] = { 0x00, 0x00, 0x0E, 0x1B, 0x0E, 0x04, 0x0F, 0x08};

	while (1) {

		/* Getting time */
		RTC_vidGetTime(&rtc);

		/* Check if its AM or PM */
		u8 Local_u8IsAMFlag = RTC_u8IsAM();

		/* Collection data in one buffer to print it with AM_PM flag*/
		u8 Local_u8Buffer[50];
		sprintf(Local_u8Buffer, "%02d:%02d:%02d:%02d", rtc.u8Hours,rtc.u8Minutes, rtc.u8Seconds, Local_u8IsAMFlag);

		/* Sending the buffer using UART */
		UART_enu_sendString(Local_u8Buffer);

		/* Collection data in one buffer to print it without AM_PM flag*/
		sprintf(Local_u8Buffer, "%02d:%02d:%02d", rtc.u8Hours,rtc.u8Minutes, rtc.u8Seconds);

		/* Printing buffer on LCD */
		LCD_voidGotoxy(1,6);
		LCD_voidSendString(Local_u8Buffer);

		/* Print AM or PM */
		LCD_voidGotoxy(2, 9);
		if (!Local_u8IsAMFlag)
			LCD_voidSendString("PM");
		else
			LCD_voidSendString("AM");

		/* Special Character */
		if (rtc.u8Seconds % 2 == 0) {
			LCD_voidWriteSpecialCharacter(Local_u8SpecialCharacterLeft, 1, 3, 11);
			LCD_voidWriteSpecialCharacter(Local_u8SpecialCharacterStand, 2, 3, 8);
		} else {
			LCD_voidWriteSpecialCharacter(Local_u8SpecialCharacterRight, 3, 3, 8);
			LCD_voidWriteSpecialCharacter(Local_u8SpecialCharacterStand, 4, 3, 11);
		}
	}
}
