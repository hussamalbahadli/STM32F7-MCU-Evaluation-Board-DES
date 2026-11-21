/****************************************************************/
/* Author   : Hussam Ali                                        */
/* Layer    : MCAL                                              */
/* File     : RCC_private.h                                     */
/* Target   : STM32F746ZG                                       */
/* Ref      : RM0385 - Section 5.3 (RCC register map)           */
/****************************************************************/
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/*------------------ 01. Base Address ------------------*/
#define RCC_BASE_ADDRESS 0x40023800UL

/*------------------ 02. Register Definitions ------------------*/
#define RCC_CR      (*(volatile u32 *)(RCC_BASE_ADDRESS + 0x00))
#define RCC_CFGR    (*(volatile u32 *)(RCC_BASE_ADDRESS + 0x08))
#define RCC_AHB1ENR (*(volatile u32 *)(RCC_BASE_ADDRESS + 0x30))
#define RCC_AHB2ENR (*(volatile u32 *)(RCC_BASE_ADDRESS + 0x34))
#define RCC_APB1ENR (*(volatile u32 *)(RCC_BASE_ADDRESS + 0x40))
#define RCC_APB2ENR (*(volatile u32 *)(RCC_BASE_ADDRESS + 0x44))

/*------------------ 03. RCC_CR Bits ------------------*/
#define RCC_CR_HSION  0
#define RCC_CR_HSIRDY 1

/*------------------ 04. RCC_CFGR Bits ------------------*/
#define RCC_CFGR_SW0  0
#define RCC_CFGR_SW1  1
#define RCC_CFGR_SWS0 2
#define RCC_CFGR_SWS1 3

/*------------------ 05. Field Values ------------------*/
#define RCC_SW_HSI 0x0 /* 00 */
#define RCC_SW_HSE 0x1 /* 01 */
#define RCC_SW_PLL 0x2 /* 10 */

/*------------------ 06. Config Options ------------------*/
#define RCC_HSI 1
#define RCC_HSE 2
#define RCC_PLL 3

#endif
