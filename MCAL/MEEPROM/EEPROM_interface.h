/*
 * EEPROM_interface.h
 *
 *  Created on: Sep 23, 2026
 *      Author: mohamed
 */

#ifndef MCAL_MEEPROM_EEPROM_INTERFACE_H_
#define MCAL_MEEPROM_EEPROM_INTERFACE_H_

void MEEPROM_voidWriteByte(u16 A_u16Address, u8 A_u8Data);
u8   MEEPROM_u8ReadByte(u16 A_u16Address);

#endif /* MCAL_MEEPROM_EEPROM_INTERFACE_H_ */
