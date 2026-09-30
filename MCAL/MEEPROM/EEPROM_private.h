/*
 * EEPROM_private.h
 *
 *  Created on: Sep 23, 2026
 *      Author: mohamed
 */

#ifndef MCAL_MEEPROM_EEPROM_PRIVATE_H_
#define MCAL_MEEPROM_EEPROM_PRIVATE_H_

#define EEARH   (*((volatile u8*)(0x3F)))
#define EEARL   (*((volatile u8*)(0x3E)))
#define EEAR    (*((volatile u16*)(0x3E)))
#define EEDR    (*((volatile u8*)(0x3D)))
#define EECR    (*((volatile u8*)(0x3C)))

#endif /* MCAL_MEEPROM_EEPROM_PRIVATE_H_ */
