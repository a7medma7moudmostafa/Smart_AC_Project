/*
 * EEPROM_program.c
 *
 *  Created on: Sep 23, 2026
 *      Author: mohamed
 */


#include "../../LIB/BitMath.h"
#include "../../LIB/STD_TYPES.h"

#include "EEPROM_interface.h"
#include "EEPROM_private.h"

void MEEPROM_voidWriteByte(u16 A_u16Address, u8 A_u8Data)
{
    while (EECR & (1 << 1));

    EEAR = A_u16Address;
    EEDR = A_u8Data;

    asm volatile (
        "sbi 0x1C, 2 \n\t"
        "sbi 0x1C, 1 \n\t"
        : : : "memory"
    );
}

u8 MEEPROM_u8ReadByte(u16 A_u16Address)
{
	while (READ_BIT(EECR, 1) == 1);

	EEAR = A_u16Address;
	SET_BIT(EECR, 0);

	return EEDR;
}
