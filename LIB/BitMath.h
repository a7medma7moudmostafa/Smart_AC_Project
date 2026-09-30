/*
 * BitMath.h
 *
 *  Created on: Sep 15, 2026
 *      Author: win 10
 */

#ifndef LIB_BITMATH_H_
#define LIB_BITMATH_H_

#define SET_BIT(REG, BIT)   ((REG) |=  (1 << (BIT)))
#define CLR_BIT(REG, BIT)   ((REG) &= ~(1 << (BIT)))
#define TOG_BIT(REG, BIT)   ((REG) ^=  (1 << (BIT)))
#define READ_BIT(REG, BIT)  (((REG) >> (BIT)) & 1)

#endif /* LIB_BITMATH_H_ */
