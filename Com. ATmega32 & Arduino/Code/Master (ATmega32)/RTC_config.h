/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 23/10/2023      **********************/
/***************  MC     : ATmega32       **********************/
/***************  SWC    : RTC       	   **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#ifndef RTC_CONFIG_H_
#define RTC_CONFIG_H_

/** OPTIONS: 1- RTC_u8_HOURS_12_MODE
 * 			 2- RTC_u8_HOURS_24_MODE
 */
#define RTC_u8_Mode				RTC_u8_HOURS_12_MODE

/** OPTIONS: 1- RTC_u8_AM
 * 			 2- RTC_u8_PM
 */
#define RTC_u8_AM_PM			RTC_u8_AM


#endif /* RTC_CONFIG_H_ */
