/*
 * LCD_program.c
 *
 *  Created on: Sep 23, 2026
 *      Author: mohamed
 */


#include "../../LIB/BitMath.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/MDIO/DIO_interface.h"

#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"

#include <util/delay.h>

static void HLCD_voidSendNibble(u8 A_u8Nibble)
{
	MDIO_voidSetPinValue(LCD_DATA_PORT, LCD_D4_PIN, READ_BIT(A_u8Nibble, 0));
	MDIO_voidSetPinValue(LCD_DATA_PORT, LCD_D5_PIN, READ_BIT(A_u8Nibble, 1));
	MDIO_voidSetPinValue(LCD_DATA_PORT, LCD_D6_PIN, READ_BIT(A_u8Nibble, 2));
	MDIO_voidSetPinValue(LCD_DATA_PORT, LCD_D7_PIN, READ_BIT(A_u8Nibble, 3));

	MDIO_voidSetPinValue(LCD_CTRL_PORT, LCD_E_PIN, DIO_HIGH);
	_delay_ms(2);
	MDIO_voidSetPinValue(LCD_CTRL_PORT, LCD_E_PIN, DIO_LOW);
	_delay_ms(2);
}

void HLCD_voidSendCommand(u8 A_u8Cmd)
{
	MDIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, DIO_LOW);
	HLCD_voidSendNibble(A_u8Cmd >> 4);
	HLCD_voidSendNibble(A_u8Cmd & 0x0F);
}

void HLCD_voidSendData(u8 A_u8Data)
{
	MDIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, DIO_HIGH);
	HLCD_voidSendNibble(A_u8Data >> 4);
	HLCD_voidSendNibble(A_u8Data & 0x0F);
}

void HLCD_voidInit(void)
{
	MDIO_voidInitPin(LCD_CTRL_PORT, LCD_RS_PIN, DIO_OUTPUT);
	MDIO_voidInitPin(LCD_CTRL_PORT, LCD_E_PIN, DIO_OUTPUT);

	MDIO_voidInitPin(LCD_DATA_PORT, LCD_D4_PIN, DIO_OUTPUT);
	MDIO_voidInitPin(LCD_DATA_PORT, LCD_D5_PIN, DIO_OUTPUT);
	MDIO_voidInitPin(LCD_DATA_PORT, LCD_D6_PIN, DIO_OUTPUT);
	MDIO_voidInitPin(LCD_DATA_PORT, LCD_D7_PIN, DIO_OUTPUT);

	_delay_ms(40);
	HLCD_voidSendNibble(0x02);
	HLCD_voidSendCommand(0x28);
	_delay_ms(1);
	HLCD_voidSendCommand(0x0C);
	_delay_ms(1);
	HLCD_voidClear();
}

void HLCD_voidSendString(u8 *A_pu8String)
{
	u8 L_u8Index = 0;
	while (A_pu8String[L_u8Index] != '\0')
	{
		HLCD_voidSendData(A_pu8String[L_u8Index]);
		L_u8Index++;
	}
}

void HLCD_voidSendNumber(s32 A_s32Number)
{
	u8 L_u8Arr[10];
	s8 L_s8Index = 0;

	if (A_s32Number == 0)
	{
		HLCD_voidSendData('0');
		return;
	}
	if (A_s32Number < 0)
	{
		HLCD_voidSendData('-');
		A_s32Number = -A_s32Number;
	}
	while (A_s32Number > 0)
	{
		L_u8Arr[L_s8Index] = (A_s32Number % 10) + '0';
		A_s32Number /= 10;
		L_s8Index++;
	}
	for (L_s8Index--; L_s8Index >= 0; L_s8Index--)
	{
		HLCD_voidSendData(L_u8Arr[L_s8Index]);
	}
}

void HLCD_voidClear(void)
{
	HLCD_voidSendCommand(0x01);
	_delay_ms(2);
}

void HLCD_voidGoTo(u8 A_u8Row, u8 A_u8Col)
{
	u8 L_u8Address = (A_u8Row == 0) ? (0x80 + A_u8Col) : (0xC0 + A_u8Col);
	HLCD_voidSendCommand(L_u8Address);
}
