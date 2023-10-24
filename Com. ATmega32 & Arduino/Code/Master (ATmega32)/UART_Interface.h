/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 24/10/2023      **********************/
/***************  MC     : ATmega32        **********************/
/***************  SWC    : UART		  	   **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/
#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

#include"STD_TYPES.h"

ES_t UART_enu_Init(void);
ES_t UART_enu_sendChar(u8 Copy_u8_Char);
ES_t UART_enu_recieveChar(u8 *Copy_pu8_recievedChar);
ES_t UART_enu_sendString(u8 *Copy_pu8_String);
ES_t UART_enu_recieveString(u8 *Copy_pu8_recievedString,u8 Copy_u8_messageSize);
ES_t UART_enu_sendNUmber(s32 Copy_s32_Num);



#endif
