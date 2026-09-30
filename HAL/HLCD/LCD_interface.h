/*
 * LCD_interface.h
 *
 *  Created on: Sep 23, 2026
 *      Author: mohamed
 */

#ifndef HAL_HLCD_LCD_INTERFACE_H_
#define HAL_HLCD_LCD_INTERFACE_H_

void HLCD_voidInit(void);
void HLCD_voidSendCommand(u8 A_u8Cmd);
void HLCD_voidSendData(u8 A_u8Data);
void HLCD_voidSendString(u8 *A_pu8String);
void HLCD_voidSendNumber(s32 A_s32Number);
void HLCD_voidClear(void);
void HLCD_voidGoTo(u8 A_u8Row, u8 A_u8Col);

#endif /* HAL_HLCD_LCD_INTERFACE_H_ */
