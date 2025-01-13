/*
 * lcd.h
 *
 *  Created on: Jan 13, 2025
 *      Author: marcostullio
 */

#ifndef LCD_H
#define LCD_H

#include "main.h"

void LCD_EnablePulse(void);

void LCD_Send4Bits(uint8_t data);

void LCD_SendCommand(uint8_t cmd);

void LCD_SendData(uint8_t data);

void LCD_Init(void);

void LCD_SetCursor(uint8_t row, uint8_t col);

void LCD_Print(char *str);

#endif /* LCD_H */
