/*
 * lcd.c
 *
 *  Created on: Jan 13, 2025
 *      Author: marcostullio
 */

#include "main.h"


/*Função ativa o pulso no pino EN. É necessário para validar os dados enviados ao LCD*/

void LCD_EnablePulse(void){
	HAL_GPIO_WritePin(EN_GPIO_Port, EN_Pin, GPIO_PIN_SET); //EN = 1
	HAL_Delay(1);
	HAL_GPIO_WritePin(EN_GPIO_Port, EN_Pin, GPIO_PIN_RESET); // EN = 0
	HAL_Delay(1);
}

/*O LCD usa o modo de comunicação 4 bits, então os comandos e dados precisam ser enviados em duas partes (nibble alto e baixo)*/
void LCD_Send4Bits(uint8_t data){
	HAL_GPIO_WritePin(DB4_GPIO_Port, DB4_Pin, (data >> 0) & 0x01);
	HAL_GPIO_WritePin(DB5_GPIO_Port, DB5_Pin, (data >> 1) & 0x01);
	HAL_GPIO_WritePin(DB6_GPIO_Port, DB6_Pin, (data >> 2) & 0x01);
	HAL_GPIO_WritePin(DB7_GPIO_Port, DB7_Pin, (data >> 3) & 0x01);

	LCD_EnablePulse();
}

/*Essa função define o RS como 0 (modo comando) e envia o dado*/
void LCD_SendCommand(uint8_t cmd){
	HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, GPIO_PIN_RESET);

	LCD_Send4Bits(cmd >> 4); // Envia o nibble alto
	LCD_Send4Bits(cmd); // Envia o nibble baixo
}

/*Essa Função define o RS como 1 (modo dados) e envia o dado*/
void LCD_SendData(uint8_t data){
	HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, GPIO_PIN_SET);

	LCD_Send4Bits(data >> 4); // Envia o niblle alto
	LCD_Send4Bits(data); // Envia o nibble baixo
}

/*Inicializar o LCD*/
void LCD_Init(void){
	HAL_Delay(15); // 15ms após ligar o LCD

	LCD_Send4Bits(0x03); // Comando para inicialização em 8 bits
	HAL_Delay(5);
	LCD_Send4Bits(0x03);
	HAL_Delay(1);
	LCD_Send4Bits(0x03);
	LCD_Send4Bits(0x04); // Configuração para 4 bits

	LCD_SendCommand(0x28); // Modo 4 bits, 2 linhas, 5x8
	LCD_SendCommand(0x0c); // Dilspay on, cursor off
	LCD_SendCommand(0x06); // Incrementa cursor
	LCD_SendCommand(0x01); // Limpa display
	HAL_Delay(2);
}

/*Essa função é para posicionar cursor*/
void LCD_SetCursor(uint8_t row, uint8_t col){
	uint8_t address = (row == 0) ? 0x80: 0xc0;
	address += col;
	LCD_SendCommand(address);
}

/*Essa função é para escrever string*/
void LCD_Print(char *str){
	while (*str){
		LCD_SendData(*str++);
	}
}
