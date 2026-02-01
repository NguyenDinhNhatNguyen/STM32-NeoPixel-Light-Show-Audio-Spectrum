#ifndef LCD_PARALLEL_H
#define LCD_PARALLEL_H

#include "stm32f1xx_hal.h"
#include <stdint.h>

// LCD Configuration
#define LCD_ROWS         2
#define LCD_COLS         16

// GPIO Configuration - theo kết nối thực tế của user
#define LCD_RS_PORT      GPIOB
#define LCD_RS_PIN       GPIO_PIN_0

#define LCD_E_PORT       GPIOB
#define LCD_E_PIN        GPIO_PIN_1

#define LCD_D4_PORT      GPIOB
#define LCD_D4_PIN       GPIO_PIN_12

#define LCD_D5_PORT      GPIOB
#define LCD_D5_PIN       GPIO_PIN_13

#define LCD_D6_PORT      GPIOB
#define LCD_D6_PIN       GPIO_PIN_14

#define LCD_D7_PORT      GPIOB
#define LCD_D7_PIN       GPIO_PIN_15

// LCD Commands
#define LCD_CLEAR_DISPLAY   0x01
#define LCD_RETURN_HOME     0x02
#define LCD_ENTRY_MODE_SET  0x04
#define LCD_DISPLAY_CONTROL 0x08
#define LCD_CURSOR_SHIFT    0x10
#define LCD_FUNCTION_SET    0x20
#define LCD_SET_CGRAM_ADDR  0x40
#define LCD_SET_DDRAM_ADDR  0x80

// Entry Mode flags
#define LCD_ENTRY_RIGHT          0x00
#define LCD_ENTRY_LEFT           0x02
#define LCD_ENTRY_SHIFT_INCREMENT 0x01
#define LCD_ENTRY_SHIFT_DECREMENT 0x00

// Display Control flags  
#define LCD_DISPLAY_ON  0x04
#define LCD_DISPLAY_OFF 0x00
#define LCD_CURSOR_ON   0x02
#define LCD_CURSOR_OFF  0x00
#define LCD_BLINK_ON    0x01
#define LCD_BLINK_OFF   0x00

// Function Set flags
#define LCD_8BITMODE 0x10
#define LCD_4BITMODE 0x00
#define LCD_2LINE    0x08
#define LCD_1LINE    0x00
#define LCD_5x10DOTS 0x04
#define LCD_5x8DOTS  0x00

// Function prototypes
void LCD_Parallel_Init(void);
void LCD_Parallel_Clear(void);
void LCD_Parallel_SetCursor(uint8_t row, uint8_t col);
void LCD_Parallel_Print(char *str);
void LCD_Parallel_PrintChar(char c);

// Advanced functions
void LCD_Parallel_CreateChar(uint8_t location, uint8_t charmap[]);
void LCD_Parallel_WriteCustomChar(uint8_t location);

// Private functions
void LCD_Parallel_SendCommand(uint8_t cmd);
void LCD_Parallel_SendData(uint8_t data);
void LCD_Parallel_Send(uint8_t data, uint8_t rs);
void LCD_Parallel_Write4Bits(uint8_t data);
void LCD_Parallel_EnablePulse(void);
void LCD_Parallel_GPIO_Init(void);

// Utility functions for LED project
void LCD_Parallel_DisplayEffect(const char* effect_name);
void LCD_Parallel_DisplayStatus(const char* color, int speed, int brightness);

// Test function for LCD troubleshooting
void LCD_Parallel_Test_Simple(void);

#endif /* LCD_PARALLEL_H */ 