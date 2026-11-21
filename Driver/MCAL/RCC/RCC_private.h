/****************************************************************/
/* Author   : Hussam Ali                                        */
/* Layer    : MCAL                                              */
/* File     : RCC_private.h                                     */
/* Target   : STM32F746ZG                                       */
/* Ref      : RM0385 - Section 5.3 (RCC register map)           */
/****************************************************************/
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/*------------------ Base Address ------------------*/
#define RCC_BASE_ADDRESS 0x40023800UL

/*------------------ Register Definitions --------------*/
#define RCC_CR      (*(volatile u32 *)(RCC_BASE_ADDRESS + 0x00))
#define RCC_CFGR    (*(volatile u32 *)(RCC_BASE_ADDRESS + 0x08))
#define RCC_AHB1ENR (*(volatile u32 *)(RCC_BASE_ADDRESS + 0x30))
#define RCC_AHB2ENR (*(volatile u32 *)(RCC_BASE_ADDRESS + 0x34))
#define RCC_APB1ENR (*(volatile u32 *)(RCC_BASE_ADDRESS + 0x40))
#define RCC_APB2ENR (*(volatile u32 *)(RCC_BASE_ADDRESS + 0x44))

/*------------------ Register RCC_CR Bit ------------------*/
#define RCC_CR_HSION  0
#define RCC_CR_HSIRDY 1

/*------------------ Register RCC_CFGR Bit ------------------*/
#define RCC_CFGR_SW0  0
#define RCC_CFGR_SW1  1
#define RCC_CFGR_SWS0 2
#define RCC_CFGR_SWS1 3

#endif