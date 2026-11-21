/****************************************************************/
/* Author   : Hussam Ali                                        */
/* Layer    : MCAL                                              */
/* File     : RCC_interface.h                                   */
/* Target   : STM32F746ZG                                       */
/* Ref      : RM0385 - Section 5.3                              */
/****************************************************************/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

/*------------------ 01. Bus IDs ------------------*/
#define RCC_AHB1 0
#define RCC_AHB2 1
#define RCC_APB1 2
#define RCC_APB2 3

/*------------------ 02. AHB1 Peripherals ------------------*/
#define RCC_AHB1_GPIOA 0
#define RCC_AHB1_GPIOB 1
#define RCC_AHB1_GPIOC 2
#define RCC_AHB1_GPIOD 3
#define RCC_AHB1_GPIOE 4
#define RCC_AHB1_GPIOF 5
#define RCC_AHB1_GPIOG 6
#define RCC_AHB1_GPIOH 7
#define RCC_AHB1_GPIOI 8
#define RCC_AHB1_GPIOJ 9
#define RCC_AHB1_GPIOK 10

/*------------------ 03. Function Prototypes ------------------*/
void RCC_voidInitSysClock(void);
void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PeripheralId);
void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PeripheralId);

#endif
