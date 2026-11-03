/****************************************************************/
/* Author   : Hussam Ali                                        */
/* Layer    : LIB                                               */
/* File     : BIT_MATH.h                                        */
/* Target   : STM32F746ZG  (Nucleo-144)                         */
/****************************************************************/
#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(VAR,BIT)    ( (VAR) |=  (1UL << (BIT)) )
#define CLR_BIT(VAR,BIT)    ( (VAR) &= ~(1UL << (BIT)) )
#define TOG_BIT(VAR,BIT)    ( (VAR) ^=  (1UL << (BIT)) )
#define GET_BIT(VAR,BIT)    ( ( (VAR) >> (BIT) ) & 0x01UL )

#endif
