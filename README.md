# Projeto de Controle LCD com STM32

Este é um projeto simples que utiliza o microcontrolador STM32F103C8T6 para controlar um display LCD 16x2 em modo de comunicação de 4 bits. O objetivo do projeto é demonstrar a integração do hardware (STM32 e LCD) com o software, usando o STM32CubeIDE para programar o microcontrolador.

## Funcionalidades Implementadas

- Inicialização do LCD.
- Configuração do cursor em diferentes posições.
- Impressão de textos no LCD.
- Controle de sinais de controle (RS, EN) para interação com o LCD.

## Estrutura do Projeto

- **/Core/Src/main.c**: Código principal que inicializa o sistema e o LCD.
- **/Core/Src/lcd.c**: Funções específicas para controle do LCD, como envio de comandos e dados.
- **/Core/Src/lcd.h**: Cabeçalhos das funções implementadas em lcd.c.
 
## Componentes Usados

- Microcontrolador: STM32F103C8T6
- Display: LCD 16x2

## Conexões

- RS - PB11
- RW - GND
- EN - PB10
- D4 - PB0
- D5 - PB1
- D6 - PC13
- D7 - PC14

## Funcionalidade

O LCD é controlado através de quatro pinos de dados e dois pinos de controle. A interface com o LCD é feita utilizando um protocolo de comunicação de 4 bits. A aplicação básica inclui:

1 - Inicialização do LCD.

2 - Envio de comandos para o LCD.

3 - Envio de dados (texto) para o LCD.

4 - Configuração do cursor e escrita no display.

## Passos para Configuração

Abra o STM32CubeIDE e crie um novo projeto para o STM32F103C8T6.

Configure os pinos GPIO no STM32CubeMX, mapeando os pinos de controle (RS, RW, EN) e os pinos de dados (D4, D5, D6, D7).

Gere o código e implemente a lógica de controle do LCD.

Compile o projeto e faça o upload para o microcontrolador.

## Funções Implementadas

- LCD_Init: Inicializa o LCD, configurando-o para o modo de 4 bits.
- LCD_EnablePulse: Envia o pulso para o pino EN, necessário para validar os dados no LCD.
- LCD_Send4Bits: Envia os 4 bits de dados para o LCD.
- LCD_SendCommand: Envia comandos para o LCD.
- LCD_SendData: Envia dados (caracteres) para o LCD.
- LCD_SetCursor: Posiciona o cursor no LCD.
- LCD_Print: Imprime uma string no LCD.
