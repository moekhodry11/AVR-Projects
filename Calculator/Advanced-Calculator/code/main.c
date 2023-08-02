/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 20/04/2023      **********************/
/***************  SWC    : Advanced Calc.  **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

/* Lib layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "LCD_interface.h"
#include "KPD_interface.h"

/* defines */
#define MAX_buffer_LENGTH 100
#define F_CPU 8000000UL

/*flags */
u8 flagClear = 0, flagZero = 0,flagSyntax=0; //to clear LCD after every process, detect dividing by 0

/* functions declaration */
f64 evaluate(u8 *buffer);

/* main */
int main(void) {
	DIO_voidInit();
	LCD_voidInit();

	u8 key, flagClear = 0, buffer_position = 0;

	u8 buffer[MAX_buffer_LENGTH]; //array to store the whole buffer

	while (1) {

		KPD_u8GetKeyState(&key);
		if (key != KPD_u8_KEY_NOT_PRESSED
				&& (key == '1' || key == '2' || key == '3' || key == '4'
						|| key == '5' || key == '6' || key == '7' || key == '8'
						|| key == '9' || key == '0' || key == '+' || key == '-'
						|| key == '*' || key == '/')) {

			if (flagClear == 1) {//clearing the LCD
				LCD_voidSendCmnd(LCD_CLEAR);
				flagClear = 0;
			}
			if (buffer_position < MAX_buffer_LENGTH - 1)//store the characters in the array
				buffer[buffer_position++] = key;

			LCD_voidSendChar(key);//printing every character
		} else if (key == '=') {
			flagClear = 1;    //flag is up after every process
			buffer[buffer_position] = '\0'; // terminate the string
			f64 result = evaluate(buffer);//calling the evaluate function to calculate the buffer
			if (flagZero == 1) {//when divide by zero flag is up
				LCD_voidGotoxy(2, 1);
				LCD_voidSendString("error div by 0");
				flagZero = 0;
			}else if (flagSyntax == 1) {//when divide by zero flag is up
				LCD_voidGotoxy(2, 1);
				LCD_voidSendString("Syntax error");
				flagSyntax = 0;
			} else {
				LCD_voidGotoxy(2, 1);
				LCD_voidSendChar('=');
				LCD_voidSendFloat(result);
			}
			buffer_position = 0;
			memset(buffer, 0, sizeof(buffer));//to clear the buffer
		}
		else if (key == 'C') {//clearing the LCD
			buffer_position = 0;
			memset(buffer, 0, sizeof(buffer));
			LCD_voidSendCmnd(LCD_CLEAR);
			;
		}
	};
	return 0;
}

f64 evaluate(u8 *buffer) {//6*5-1/9
    f64 result = 0.0f;
    f32 num = 0.0f;
    s8 op = '+';
    s16 length = strlen(buffer);
    s16 i = 0;
    while (i < length) {
        if (buffer[i] >= '0' && buffer[i] <= '9') {
            num = num * 10.0f + (buffer[i] - '0');
            i++;
        }  else if (buffer[i] == '*' || buffer[i] == '/') {
        	if(buffer[i+1]=='*' || buffer[i+1] == '/' || buffer[i+1]=='-' || buffer[i+1] == '+' )
        		flagSyntax=1;

            s8 c = buffer[i];
            i++;
            f32 next_num = 0.0f;
            u8 flagNextNum=0;
            while (i < length && buffer[i] == ' ') {
                i++;
            }
            while (i < length && buffer[i] >= '0' && buffer[i] <= '9') {
                next_num = next_num * 10.0f + (buffer[i] - '0');
                i++;
                flagNextNum++;
            }
            while (i < length && buffer[i] == ' ') {
                i++;
            }
            if (c == '*') {
                num *= next_num;
            } else {
            	if(flagNextNum<1){
            		flagSyntax=1;
            		return flagSyntax;
            	}
                if (next_num == 0.0f) {
                	flagZero = 1;
                	return flagZero;
                }
                num /= next_num;
            }
        } else {
        	if(buffer[i+1]=='*' || buffer[i+1] == '/' || buffer[i+1]=='-' || buffer[i+1] == '+' )
        	        		flagSyntax=1;
            if (op == '+') {
                result += num;
            } else {
                result -= num;
            }
            num = 0.0f;
            op = buffer[i];
            i++;
        }
    }
    if (op == '+') {
        result += num;
    } else {
        result -= num;
    }
    return result;
}
