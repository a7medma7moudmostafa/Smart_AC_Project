/*
 * ADC_program.c
 *
 *  Created on: Sep 23, 2026
 *      Author: mohamed
 */


#include "../../LIB/BitMath.h"
#include "../../LIB/BiTMath.h"
#include "../../LIB/STD_TYPES.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"

void MADC_voidInit(void)
{
#if ADC_VREF_MODE == ADC_VREF_AVCC
	SET_BIT(ADMUX, 6);
	CLR_BIT(ADMUX, 7);
#elif ADC_VREF_MODE == ADC_VREF_AREF
	CLR_BIT(ADMUX, 6);
	CLR_BIT(ADMUX, 7);
#elif ADC_VREF_MODE == ADC_VREF_INTERNAL_2_56
	SET_BIT(ADMUX, 6);
	SET_BIT(ADMUX, 7);
#endif

	CLR_BIT(ADMUX, 5);

	ADCSRA = (ADCSRA & 0xF8) | (ADC_PRESCALER_MODE & 0x07);

	SET_BIT(ADCSRA, 7);
}

u16 MADC_u16ReadChannel(u8 A_u8ChannelNum)
{
	ADMUX = (ADMUX & 0xE0) | (A_u8ChannelNum & 0x1F);

	SET_BIT(ADCSRA, 6);

	while (READ_BIT(ADCSRA, 4) == 0);

	SET_BIT(ADCSRA, 4);

	return ADC_DATA;
}
