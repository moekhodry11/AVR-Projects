################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_program.c \
../I2C_program.c \
../LCD_program.c \
../RTC_program.c \
../UART_Program.c \
../main.c 

OBJS += \
./DIO_program.o \
./I2C_program.o \
./LCD_program.o \
./RTC_program.o \
./UART_Program.o \
./main.o 

C_DEPS += \
./DIO_program.d \
./I2C_program.d \
./LCD_program.d \
./RTC_program.d \
./UART_Program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


