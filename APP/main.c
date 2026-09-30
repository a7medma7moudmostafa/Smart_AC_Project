#include "../LIB/BitMath.h"
#include "../LIB/STD_TYPES.h"

#include "../MCAL/MDIO/DIO_interface.h"
#include "../MCAL/MEEPROM/EEPROM_interface.h"

#include "../HAL/HLCD/LCD_interface.h"
#include "../HAL/HLM35/LM35_interface.h"
#include "../HAL/HMOTOR/Motor_interface.h"

#include <util/delay.h>

#define LED_YELLOW_PORT    DIO_PORTC
#define LED_YELLOW_PIN     DIO_PIN2

#define LED_GREEN_PORT     DIO_PORTC
#define LED_GREEN_PIN      DIO_PIN3

#define BTN_PORT           DIO_PORTB
#define BTN_INC_PIN        DIO_PIN0
#define BTN_DEC_PIN        DIO_PIN1

#define EEPROM_SET_TEMP_ADDR   0x0020
#define EEPROM_INIT_FLAG_ADDR  0x0030

#define MAX_TEMP           28
#define MIN_TEMP           0

int main(void)
{
    u8 L_u8CurrentTemp = 0;
    u8 L_u8SetTemp = 25;
    u8 L_u8Diff = 0;
    u8 L_u8MotorSpeed = 0;

    HLM35_voidInit();
    HLCD_voidInit();
    HMOTOR_voidInit();

    MDIO_voidInitPin(LED_YELLOW_PORT, LED_YELLOW_PIN, DIO_OUTPUT);
    MDIO_voidInitPin(LED_GREEN_PORT, LED_GREEN_PIN, DIO_OUTPUT);

    MDIO_voidInitPin(BTN_PORT, BTN_INC_PIN, DIO_INPUT);
    MDIO_voidSetPinValue(BTN_PORT, BTN_INC_PIN, DIO_HIGH);

    MDIO_voidInitPin(BTN_PORT, BTN_DEC_PIN, DIO_INPUT);
    MDIO_voidSetPinValue(BTN_PORT, BTN_DEC_PIN, DIO_HIGH);

    if (MEEPROM_u8ReadByte(EEPROM_INIT_FLAG_ADDR) != 0xAA)
    {
        MEEPROM_voidWriteByte(EEPROM_SET_TEMP_ADDR, 25);
        MEEPROM_voidWriteByte(EEPROM_INIT_FLAG_ADDR, 0xAA);
        L_u8SetTemp = 25;
    }
    else
    {
        L_u8SetTemp = MEEPROM_u8ReadByte(EEPROM_SET_TEMP_ADDR);
        if (L_u8SetTemp > MAX_TEMP)
        {
            L_u8SetTemp = MAX_TEMP;
        }
    }

    while (1)
    {
        L_u8CurrentTemp = HLM35_u8GetTemp();

        if (MDIO_u8ReadPin(BTN_PORT, BTN_INC_PIN) == DIO_LOW)
        {
            _delay_ms(30);
            if (MDIO_u8ReadPin(BTN_PORT, BTN_INC_PIN) == DIO_LOW)
            {
                if (L_u8SetTemp < MAX_TEMP)
                {
                    L_u8SetTemp++;
                    MEEPROM_voidWriteByte(EEPROM_SET_TEMP_ADDR, L_u8SetTemp);
                }
                while (MDIO_u8ReadPin(BTN_PORT, BTN_INC_PIN) == DIO_LOW);
            }
        }

        if (MDIO_u8ReadPin(BTN_PORT, BTN_DEC_PIN) == DIO_LOW)
        {
            _delay_ms(30);
            if (MDIO_u8ReadPin(BTN_PORT, BTN_DEC_PIN) == DIO_LOW)
            {
                if (L_u8SetTemp > MIN_TEMP)
                {
                    L_u8SetTemp--;
                    MEEPROM_voidWriteByte(EEPROM_SET_TEMP_ADDR, L_u8SetTemp);
                }
                while (MDIO_u8ReadPin(BTN_PORT, BTN_DEC_PIN) == DIO_LOW);
            }
        }

        HLCD_voidGoTo(0, 0);
        HLCD_voidSendString((u8*)"T:");
        HLCD_voidSendNumber(L_u8CurrentTemp);
        HLCD_voidSendString((u8*)"C  Set:");
        HLCD_voidSendNumber(L_u8SetTemp);
        HLCD_voidSendString((u8*)"C   ");

        HLCD_voidGoTo(1, 0);

        if (L_u8CurrentTemp == L_u8SetTemp)
        {
            HLCD_voidSendString((u8*)"Mode: OFF       ");
            MDIO_voidSetPinValue(LED_YELLOW_PORT, LED_YELLOW_PIN, DIO_LOW);
            MDIO_voidSetPinValue(LED_GREEN_PORT, LED_GREEN_PIN, DIO_LOW);

            HMOTOR_voidSetDirection(MOTOR_STOP);
            HMOTOR_voidSetSpeed(0);
        }
        else if (L_u8CurrentTemp > L_u8SetTemp)
        {
            HLCD_voidSendString((u8*)"Mode: COOLING   ");
            MDIO_voidSetPinValue(LED_YELLOW_PORT, LED_YELLOW_PIN, DIO_LOW);
            MDIO_voidSetPinValue(LED_GREEN_PORT, LED_GREEN_PIN, DIO_HIGH);

            L_u8Diff = L_u8CurrentTemp - L_u8SetTemp;
            L_u8MotorSpeed = (L_u8Diff >= 10) ? 255 : (u8)(L_u8Diff * 25.5);

            HMOTOR_voidSetDirection(MOTOR_CCW);
            HMOTOR_voidSetSpeed(L_u8MotorSpeed);
        }
        else
        {
            HLCD_voidSendString((u8*)"Mode: HEATING   ");
            MDIO_voidSetPinValue(LED_YELLOW_PORT, LED_YELLOW_PIN, DIO_HIGH);
            MDIO_voidSetPinValue(LED_GREEN_PORT, LED_GREEN_PIN, DIO_LOW);

            L_u8Diff = L_u8SetTemp - L_u8CurrentTemp;
            L_u8MotorSpeed = (L_u8Diff >= 10) ? 255 : (u8)(L_u8Diff * 25.5);

            HMOTOR_voidSetDirection(MOTOR_CW);
            HMOTOR_voidSetSpeed(L_u8MotorSpeed);
        }

        _delay_ms(150);
    }

    return 0;
}
