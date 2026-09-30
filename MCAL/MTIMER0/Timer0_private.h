/*
 * Timer0_private.h
 *
 *  Created on: Sep 23, 2026
 *      Author: mohamed
 */

#ifndef MCAL_MTIMER0_TIMER0_PRIVATE_H_
#define MCAL_MTIMER0_TIMER0_PRIVATE_H_

#define TCCR0   (*((volatile u8*)(0x53)))
#define TCNT0   (*((volatile u8*)(0x52)))
#define OCR0    (*((volatile u8*)(0x5C)))

#endif /* MCAL_MTIMER0_TIMER0_PRIVATE_H_ */
