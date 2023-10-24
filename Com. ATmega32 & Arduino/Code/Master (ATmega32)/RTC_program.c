/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 23/10/2023      **********************/
/***************  MC     : ATmega32       **********************/
/***************  SWC    : RTC       	   **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "I2C_interface.h"
#include "RTC_interface.h"
#include "RTC_config.h"
#include "RTC_private.h"

//RTC_t G_rtc;


u8 RTC_DEC2BCD(u8 val)
{
	return (val + 6*(val/10));
}

u8 RTC_BCD2DEC(u8 val)
{
	return (val - 6*(val>>4));
}

void RTC_vidInit(void)
{

	TWI_vidInit();
	TWI_vidSendStart();
	/*Sending address of DS1307 RTC module*/
	TWI_vidSendByte(0xd0);
	/*Sending address of control register*/
	TWI_vidSendByte(0x07);
	TWI_vidSendByte(0x00);

	TWI_vidSendStop();

}

/*Write time to RTC: Complete*/
void RTC_vidSetTime(RTC_t * rtc)
{
	u8 Local_u8BCDHours;
	TWI_vidSendStart();
	TWI_vidSendByte(RTC_MODE_WRITE);
	TWI_vidSendByte(0x00);
	TWI_vidSendByte(RTC_DEC2BCD(rtc->u8Seconds));
	TWI_vidSendByte(RTC_DEC2BCD(rtc->u8Minutes));

	Local_u8BCDHours=RTC_DEC2BCD(rtc->u8Hours);
	#if RTC_u8_Mode == RTC_u8_HOURS_12_MODE
	Local_u8BCDHours |= (1<<6);
	#elif RTC_u8_Mode == RTC_u8_HOURS_12_MODE
	Local_u8BCDHours &= ~(1<<6);
	#endif

	#if RTC_u8_AM_PM == RTC_u8_PM
		Local_u8BCDHours &= ~(1<<5);
	#elif RTC_u8_AM_PM == RTC_u8_AM
		Local_u8BCDHours |= (1<<5);
	#endif

	TWI_vidSendByte(Local_u8BCDHours);

	TWI_vidSendByte(0x00);

	TWI_vidSendStop();
}

void RTC_vidGetTime(RTC_t * rtc)
{
	TWI_vidSendStart();
	TWI_vidSendByte(RTC_MODE_WRITE);
	TWI_vidSendByte(0x00);
	TWI_vidSendStop();

	TWI_vidSendStart();
	TWI_vidSendByte(RTC_MODE_READ);

	rtc->u8Seconds = RTC_BCD2DEC(TWI_u8ReceiveWithAck());
	TWI_u8CheckAck(0x01);
	rtc->u8Minutes = RTC_BCD2DEC(TWI_u8ReceiveWithAck());
	TWI_u8CheckAck(0x01);
	rtc->u8Hours =RTC_BCD2DEC((TWI_u8ReceiveWithNoAck() & 0b00011111));

	TWI_vidSendStop();
}

void RTC_vidSetDate(RTC_t * rtc)
{
	TWI_vidSendStart();
	TWI_vidSendByte(RTC_MODE_WRITE);
	TWI_vidSendByte(0x04);
	TWI_vidSendByte(rtc->u8Days);
	TWI_vidSendByte(rtc->u8Months);
	TWI_vidSendByte(rtc->u8Years);
	TWI_vidSendByte(0x00);
	TWI_vidSendStop();
}

void RTC_vidGetDate(RTC_t * rtc)
{
	TWI_vidSendStart();
	TWI_vidSendByte(RTC_MODE_WRITE);
	TWI_vidSendByte(0x04);
	TWI_vidSendStop();

	TWI_vidSendStart();
	TWI_vidSendByte(RTC_MODE_READ);

	rtc->u8Days = TWI_u8ReceiveWithAck();
	TWI_u8CheckAck(0x01);
	rtc->u8Months = TWI_u8ReceiveWithAck();
	TWI_u8CheckAck(0x01);
	rtc->u8Years = TWI_u8ReceiveWithNoAck();

	TWI_vidSendStop();

}

void RTC_vidSetDayOfWeek(RTC_t * rtc)
{
	TWI_vidSendStart();
	TWI_vidSendByte(RTC_MODE_WRITE);
	TWI_vidSendByte(0x03);

	TWI_vidSendByte(rtc->u8DayOfWeek);
	TWI_vidSendStop();
}

void RTC_vidGetDayOfWeek(RTC_t * rtc)
{
	TWI_vidSendStart();
	TWI_vidSendByte(RTC_MODE_WRITE);
	TWI_vidSendByte(0x03);
	TWI_vidSendStop();

	TWI_vidSendStart();
	TWI_vidSendByte(RTC_MODE_READ);
	rtc->u8DayOfWeek = TWI_u8ReceiveWithNoAck();
	TWI_vidSendStop();

}

u8 RTC_u8IsAM(void){
	TWI_vidSendStart();
		TWI_vidSendByte(RTC_MODE_WRITE);
		TWI_vidSendByte(0x02);
		TWI_vidSendStop();

		TWI_vidSendStart();
		TWI_vidSendByte(RTC_MODE_READ);

		u8 flag=0;
		flag =(TWI_u8ReceiveWithNoAck() & 0b00100000);
		if(flag==1)
			flag =1;

		TWI_vidSendByte(0x00);
		TWI_vidSendStop();
		return flag;
}
