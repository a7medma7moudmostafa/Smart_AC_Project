/*
 * Motor_program.c
 *
 *  Created on: Sep 23, 2026
 *      Author: mohamed
 */

#include "../../LIB/BitMath.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/MDIO/DIO_interface.h"
#include "../../MCAL/MTIMER0/Timer0_interface.h"

#include "Motor_interface.h"
#include "Motor_config.h"

void HMOTOR_voidInit(void)
{
    MDIO_voidInitPin(MOTOR_PORT, MOTOR_PIN_IN1, DIO_OUTPUT);
    MDIO_voidInitPin(MOTOR_PORT, MOTOR_PIN_IN2, DIO_OUTPUT);
    MTIMER0_voidInitFastPWM();
}

void HMOTOR_voidSetDirection(u8 A_u8Direction)
{
    switch (A_u8Direction)
    {
    case MOTOR_CW:
        MDIO_voidSetPinValue(MOTOR_PORT, MOTOR_PIN_IN1, DIO_HIGH);
        MDIO_voidSetPinValue(MOTOR_PORT, MOTOR_PIN_IN2, DIO_LOW);
        break;
    case MOTOR_CCW:
        MDIO_voidSetPinValue(MOTOR_PORT, MOTOR_PIN_IN1, DIO_LOW);
        MDIO_voidSetPinValue(MOTOR_PORT, MOTOR_PIN_IN2, DIO_HIGH);
        break;
    case MOTOR_STOP:
    default:
        MDIO_voidSetPinValue(MOTOR_PORT, MOTOR_PIN_IN1, DIO_LOW);
        MDIO_voidSetPinValue(MOTOR_PORT, MOTOR_PIN_IN2, DIO_LOW);
        break;
    }
}

void HMOTOR_voidSetSpeed(u8 A_u8Speed)
{
    MTIMER0_voidSetDutyCycle(A_u8Speed);
}
