/*
 * Timer0_program.c
 *
 *  Created on: Sep 23, 2026
 *      Author: mohamed
 */


#include "../../LIB/BitMath.h"
#include "../../LIB/STD_TYPES.h"
#include "../MDIO/DIO_interface.h"
#include "Timer0_interface.h"
#include "Timer0_private.h"
#include "Timer0_config.h"

void MTIMER0_voidInitFastPWM(void)
{
	MDIO_voidInitPin(DIO_PORTB, DIO_PIN3, DIO_OUTPUT);

	SET_BIT(TCCR0, 6);
	SET_BIT(TCCR0, 3);

	SET_BIT(TCCR0, 5);
	CLR_BIT(TCCR0, 4);

	SET_BIT(TCCR0, 0);
	SET_BIT(TCCR0, 1);
	CLR_BIT(TCCR0, 2);
}

void MTIMER0_voidSetDutyCycle(u8 A_u8Duty)
{
	OCR0 = A_u8Duty;
}
