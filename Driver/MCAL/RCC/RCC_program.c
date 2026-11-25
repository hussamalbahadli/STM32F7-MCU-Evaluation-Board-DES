/****************************************************************/
/* Author   : Hussam Ali                                        */
/* Layer    : MCAL                                              */
/* File     : RCC_program.c                                     */
/* Target   : STM32F746ZG                                       */
/* Ref      : RM0385 - Section 5.3                              */
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

/*------------------ 01. System Clock Init ------------------*/
void RCC_voidInitSysClock(void)
{
#if RCC_CLOCK_TYPE == RCC_HSI

    SET_BIT(RCC_CR, RCC_CR_HSION);
    while (GET_BIT(RCC_CR, RCC_CR_HSIRDY) == 0)
        ; /* TODO: timeout */

    RCC_CFGR &= ~(0x3 << RCC_CFGR_SW0);
    RCC_CFGR |= (RCC_SW_HSI << RCC_CFGR_SW0);

    while (((RCC_CFGR >> RCC_CFGR_SWS0) & 0x3) != RCC_SW_HSI)
        ;

#else
#error "RCC: clock type not supported yet"
#endif
}

/*------------------ 02. Enable Peripheral Clock ------------------*/
void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PeripheralId)
{
    switch (Copy_u8BusId)
    {
        case RCC_AHB1: SET_BIT(RCC_AHB1ENR, Copy_u8PeripheralId); break;
        case RCC_AHB2: SET_BIT(RCC_AHB2ENR, Copy_u8PeripheralId); break;
        case RCC_APB1: SET_BIT(RCC_APB1ENR, Copy_u8PeripheralId); break;
        case RCC_APB2: SET_BIT(RCC_APB2ENR, Copy_u8PeripheralId); break;
        default: /* TODO: error */ break;
    }
}

/*------------------ 03. Disable Peripheral Clock ------------------*/
void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PeripheralId)
{
    switch (Copy_u8BusId)
    {
        case RCC_AHB1: CLR_BIT(RCC_AHB1ENR, Copy_u8PeripheralId); break;
        case RCC_AHB2: CLR_BIT(RCC_AHB2ENR, Copy_u8PeripheralId); break;
        case RCC_APB1: CLR_BIT(RCC_APB1ENR, Copy_u8PeripheralId); break;
        case RCC_APB2: CLR_BIT(RCC_APB2ENR, Copy_u8PeripheralId); break;
        default: /* TODO: error */ break;
    }
}
