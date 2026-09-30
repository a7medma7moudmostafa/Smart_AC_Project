/*
 * LM35_program.c
 *
 *  Created on: Sep 23, 2026
 *      Author: mohamed
 */


#include "../../LIB/BitMath.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/MADC/ADC_interface.h"

#include "LM35_interface.h"
#include "LM35_config.h"

void HLM35_voidInit(void)
{
	MADC_voidInit();
}

u8 HLM35_u8GetTemp(void)
{
    u16 L_u16AdcVal = MADC_u16ReadChannel(LM35_ADC_CHANNEL);
    return (u8)((((u32)L_u16AdcVal * 500UL) + 512UL) / 1024UL);
}
