//****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 23/10/2023      **********************/
/***************  MC     : ATmega32       **********************/
/***************  SWC    : RTC       	   **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#ifndef RTC_PRIVATE_H_
#define RTC_PRIVATE_H_

#define C_Ds1307ReadMode_U8   0xD1u  // DS1307 ID
#define C_Ds1307WriteMode_U8  0xD0u  // DS1307 ID

#define RTC_MODE_WRITE 0xD0
#define RTC_MODE_READ 0xD1

#define RTC_u8_HOURS_12_MODE			0
#define RTC_u8_HOURS_24_MODE			1

#define RTC_u8_AM			0
#define RTC_u8_PM			1


#endif /* RTC_PRIVATE_H_ */
