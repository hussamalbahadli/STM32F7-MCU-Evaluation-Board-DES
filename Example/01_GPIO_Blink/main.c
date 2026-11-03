/****************************************************************/
/* Author   : Hussam Ali                                        */
/* Example  : 01_GPIO_Blink                                     */
/* Target   : STM32F746ZG  (NUCLEO-F746ZG)                      */
/*                                                              */
/* هذا الملف هو "الاختبار" مالي.                                 */
/* ما أغيّره. أكتب RCC و GPIO حتى هذا الملف يشتغل مثل ما هو.      */
/* إذا اشتغل → الدرايفرين صحيحين.                                */
/****************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"

void Delay(void);

int main(void)
{
    /* 1 - شغّل الكلوك مال GPIOB  (LD1 على PB0) */
    RCC_voidInitSysClock();
    RCC_voidEnableClock(RCC_AHB1, RCC_AHB1_GPIOB);

    /* 2 - خلي PB0 خرج */
    GPIO_voidSetPinDirection(GPIO_PORTB, GPIO_PIN0, GPIO_OUTPUT_PUSHPULL);

    /* 3 - لمّع */
    while (1)
    {
        GPIO_voidSetPinValue(GPIO_PORTB, GPIO_PIN0, GPIO_HIGH);
        Delay();
        GPIO_voidSetPinValue(GPIO_PORTB, GPIO_PIN0, GPIO_LOW);
        Delay();
    }
}

/* تأخير فاضي — مؤقتاً، حتى نكتب STK */
void Delay(void)
{
    u32 Local_u32Counter = 0;
    for (Local_u32Counter = 0; Local_u32Counter < 1000000UL; Local_u32Counter++)
    {
        __asm("NOP");
    }
}
