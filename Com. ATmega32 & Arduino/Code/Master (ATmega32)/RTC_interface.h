/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 23/10/2023      **********************/
/***************  MC     : ATmega32       **********************/
/***************  SWC    : RTC       	   **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#ifndef _RTC_INTERFACE_H
#define _RTC_INTERFACE_H

typedef struct {
	u8 u8Seconds;
	u8 u8Minutes;
	u8 u8Hours;
	u8 u8DayOfWeek;
	u8 u8Days;
	u8 u8Months;
	u16 u8Years;
} RTC_t;

void RTC_vidInit(void);
void RTC_vidSetTime(RTC_t *);
void RTC_vidGetTime(RTC_t *);
void RTC_vidSetDate(RTC_t *);
void RTC_vidGetDate(RTC_t *);
void RTC_vidSetDayOfWeek(RTC_t *);
void RTC_vidGetDayOfWeek(RTC_t *);
u8 RTC_u8IsAM(void);

u8 RTC_DEC2BCD(u8);
u8 RTC_BCD2DEC(u8);

#endif
