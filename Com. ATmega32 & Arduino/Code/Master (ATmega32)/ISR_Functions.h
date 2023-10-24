#ifndef ISR_FUNCTIONS_H
#define ISR_FUNCTIONS_H

#define ISR(vect)         void vect (void) __attribute__((signal));\
                          void vect (void)

#define  EXTI_INT0             __vector_1
#define  EXTI_INT1             __vector_2
#define  EXTI_INT2             __vector_3
#define  TIMER2_COMP           __vector_4
#define  TIMER2_OVF            __vector_5
#define  TIMER1_CAPT           __vector_6
#define  TIMER1_COMPA          __vector_7
#define  TIMER1_COMPB          __vector_8
#define  TIMER1_OVF            __vector_9
#define  TIMER0_COMP           __vector_10
#define  TIMER0_OVF            __vector_11
#define  SPI_STC               __vector_12
#define  UART_RX               __vector_13
#define  UART_UDRE             __vector_14
#define  UART_TX               __vector_15
#define  ADC                   __vector_16

#endif 