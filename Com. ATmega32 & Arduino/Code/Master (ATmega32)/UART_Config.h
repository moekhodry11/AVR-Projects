/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 24/10/2023      **********************/
/***************  MC     : ATmega32        **********************/
/***************  SWC    : UART		  	   **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#ifndef UART_CONFIG_H
#define UART_CONFIG_H
/*Options For Mode :
                                1-ASYNCH_NORMAL_MODE 
                                2-ASYNCH_DOUBLE_SPEED
                                3-SYNCHRONOUS 
*/
/*Options For Baud Rate :
                                1-2400 
                                2-4800
                                3-9600
                                4-14400
                                5-19200
                                6-28800 
*/
/*Options For Stop Bits :
                                1-ONE_BIT 
                                2-TWO_BITS
*/
/*Options For Data Bits :
                                1- _5_BITS 
                                2- _6_BITS
                                2- _7_BITS
                                2- _8_BITS
                                2- _9_BITS
*/
/*Options For Parity Bit :
                                1-NONE 
                                2-ODD_PARITY
                                3-EVEN_PARITY 
*/
/************************ UART Configuration ************************/
#define UART_MODE           ASYNCH_NORMAL_MODE
#define UART_BAUD_RATE      9600
#define UART_STOP_BITS      ONE_BIT
#define UART_DATA_BITS      _8_BITS
#define UART_PARITY_BIT     NONE
#define F_CPU               16000000


#endif
