################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_program.c \
../EXTI_program.c \
../GI_program.c \
../LCD_program.c \
../main.c \
../timer_program.c 

OBJS += \
./DIO_program.o \
./EXTI_program.o \
./GI_program.o \
./LCD_program.o \
./main.o \
./timer_program.o 

C_DEPS += \
./DIO_program.d \
./EXTI_program.d \
./GI_program.d \
./LCD_program.d \
./main.d \
./timer_program.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


