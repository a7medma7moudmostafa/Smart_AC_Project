/*
 * Motor_interface.h
 *
 *  Created on: Sep 23, 2026
 *      Author: mohamed
 */

#ifndef HAL_HMOTOR_MOTOR_INTERFACE_H_
#define HAL_HMOTOR_MOTOR_INTERFACE_H_

#define MOTOR_STOP      0
#define MOTOR_CW        1
#define MOTOR_CCW       2

void HMOTOR_voidInit(void);
void HMOTOR_voidSetDirection(u8 A_u8Direction);
void HMOTOR_voidSetSpeed(u8 A_u8Speed);

#endif /* HAL_HMOTOR_MOTOR_INTERFACE_H_ */
