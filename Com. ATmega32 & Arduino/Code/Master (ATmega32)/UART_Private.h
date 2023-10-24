/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 24/10/2023      **********************/
/***************  MC     : ATmega32        **********************/
/***************  SWC    : UART		  	   **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/
#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H
#include"STD_TYPES.h"
/*********************Registers Addresses******************/
#define UART_UBRRH_REG    *((volatile u8*)0x40)
#define UART_UBRRL_REG    *((volatile u8*)0x29)
#define UART_UCSRC_REG    *((volatile u8*)0x40)   //Byte Access
#define UART_UDR_REG      *((volatile u8*)0x2c)
#define UART_UCSRA_REG    *((volatile u8*)0x2b)
#define UART_UCSRB_REG    *((volatile u8*)0x2a)
/*********************Registers Bits******************/
#define MPCM        0
#define U2X         1
#define TXC         6
#define RXC         7
#define TXB8        0
#define RXB8        1
#define UCZ2        2
#define TXEN        3
#define RXEN        4
#define UDRIE       5
#define TXCIE       6
#define RXCIE       7
#define URSEL       7
#define UMSEL       6
#define UPM0        4
#define UPM1        5
#define USBS        3
#define UCZ1        2
#define UCZ0        1
#define UCPOL       0
#define UDRE        5
/**************************************************************************/
#define ASYNCH_NORMAL_MODE      0
#define ASYNCH_DOUBLE_SPEED     1
#define SYNCHRONOUS             2
#define ONE_BIT                 1
#define TWO_BITS                2
#define NONE                    0
#define ODD_PARITY              1
#define EVEN_PARITY             2
#define _5_BITS                 0
#define _6_BITS                 1
#define _7_BITS                 2
#define _8_BITS                 3
#define _9_BITS                 4
#define UCSRC_INITIAL_VALUE    0x80
/****************************ISR**********************/
void __vector_13(void)    __attribute__((signal));
void __vector_15(void)    __attribute__((signal));
#endif
