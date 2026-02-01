#include "lcd_parallel.h"
#include <string.h>
#include <stdio.h>

void LCD_Parallel_Init(void) {
    // Initialize GPIO pins
    LCD_Parallel_GPIO_Init();
    
    // Wait for LCD to power up completely
    HAL_Delay(100);
    
    // Set RS = 0 (command mode)
    HAL_GPIO_WritePin(LCD_RS_PORT, LCD_RS_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LCD_E_PORT, LCD_E_PIN, GPIO_PIN_RESET);
    
    // Initialize LCD in 4-bit mode according to datasheet timing
    // First: Send 0x3 three times to establish 8-bit communication
    LCD_Parallel_Write4Bits(0x03);
    HAL_Delay(10);  // Wait > 4.1ms
    
    LCD_Parallel_Write4Bits(0x03);
    HAL_Delay(5);   // Wait > 100us
    
    LCD_Parallel_Write4Bits(0x03);
    HAL_Delay(5);   // Wait > 100us
    
    // Switch to 4-bit mode
    LCD_Parallel_Write4Bits(0x02);
    HAL_Delay(5);
    
    // Function set: 4-bit, 2 line, 5x8 dots
    LCD_Parallel_SendCommand(LCD_FUNCTION_SET | LCD_4BITMODE | LCD_2LINE | LCD_5x8DOTS);
    HAL_Delay(5);
    
    // Display control: display on, cursor off, blink off
    LCD_Parallel_SendCommand(LCD_DISPLAY_CONTROL | LCD_DISPLAY_ON | LCD_CURSOR_OFF | LCD_BLINK_OFF);
    HAL_Delay(5);
    
    // Clear display
    LCD_Parallel_Clear();
    HAL_Delay(5);
    
    // Entry mode: left to right, no shift
    LCD_Parallel_SendCommand(LCD_ENTRY_MODE_SET | LCD_ENTRY_LEFT | LCD_ENTRY_SHIFT_DECREMENT);
    HAL_Delay(5);
}

void LCD_Parallel_GPIO_Init(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    
    // Enable GPIOB clock
    __HAL_RCC_GPIOB_CLK_ENABLE();
    
    // Configure RS pin (PB0)
    GPIO_InitStruct.Pin = LCD_RS_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(LCD_RS_PORT, &GPIO_InitStruct);
    
    // Configure E pin (PB1)
    GPIO_InitStruct.Pin = LCD_E_PIN;
    HAL_GPIO_Init(LCD_E_PORT, &GPIO_InitStruct);
    
    // Configure Data pins (PB12, PB13, PB14, PB15)
    GPIO_InitStruct.Pin = LCD_D4_PIN | LCD_D5_PIN | LCD_D6_PIN | LCD_D7_PIN;
    HAL_GPIO_Init(LCD_D4_PORT, &GPIO_InitStruct);
    
    // Initialize all pins to LOW
    HAL_GPIO_WritePin(LCD_RS_PORT, LCD_RS_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LCD_E_PORT, LCD_E_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LCD_D4_PORT, LCD_D4_PIN | LCD_D5_PIN | LCD_D6_PIN | LCD_D7_PIN, GPIO_PIN_RESET);
}

void LCD_Parallel_Clear(void) {
    LCD_Parallel_SendCommand(LCD_CLEAR_DISPLAY);
    HAL_Delay(2);
}

void LCD_Parallel_SetCursor(uint8_t row, uint8_t col) {
    uint8_t row_offsets[] = {0x00, 0x40, 0x14, 0x54};
    if (row >= LCD_ROWS) {
        row = LCD_ROWS - 1;
    }
    if (col >= LCD_COLS) {
        col = LCD_COLS - 1;
    }
    LCD_Parallel_SendCommand(LCD_SET_DDRAM_ADDR | (col + row_offsets[row]));
}

void LCD_Parallel_Print(char *str) {
    while (*str) {
        LCD_Parallel_SendData(*str++);
    }
}

void LCD_Parallel_PrintChar(char c) {
    LCD_Parallel_SendData(c);
}

void LCD_Parallel_CreateChar(uint8_t location, uint8_t charmap[]) {
    location &= 0x7; // Chỉ có 8 vị trí
    LCD_Parallel_SendCommand(LCD_SET_CGRAM_ADDR | (location << 3));
    for (int i = 0; i < 8; i++) {
        LCD_Parallel_SendData(charmap[i]);
    }
}

void LCD_Parallel_WriteCustomChar(uint8_t location) {
    LCD_Parallel_SendData(location);
}

void LCD_Parallel_SendCommand(uint8_t cmd) {
    LCD_Parallel_Send(cmd, 0);
}

void LCD_Parallel_SendData(uint8_t data) {
    LCD_Parallel_Send(data, 1);
}

void LCD_Parallel_Send(uint8_t data, uint8_t rs) {
    // Set RS pin (0 = command, 1 = data)
    HAL_GPIO_WritePin(LCD_RS_PORT, LCD_RS_PIN, rs ? GPIO_PIN_SET : GPIO_PIN_RESET);
    
    // Send upper 4 bits
    LCD_Parallel_Write4Bits(data >> 4);
    
    // Send lower 4 bits
    LCD_Parallel_Write4Bits(data & 0x0F);
}

void LCD_Parallel_Write4Bits(uint8_t data) {
    // Set data on D4-D7 pins (PB12-PB15)
    HAL_GPIO_WritePin(LCD_D4_PORT, LCD_D4_PIN, (data & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LCD_D5_PORT, LCD_D5_PIN, (data & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LCD_D6_PORT, LCD_D6_PIN, (data & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LCD_D7_PORT, LCD_D7_PIN, (data & 0x08) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    
    // Pulse Enable pin
    LCD_Parallel_EnablePulse();
}

void LCD_Parallel_EnablePulse(void) {
    HAL_GPIO_WritePin(LCD_E_PORT, LCD_E_PIN, GPIO_PIN_SET);
    
    // Enable pulse width (minimum 450ns, dùng loop delay)
    for(volatile int i = 0; i < 50; i++);
    
    HAL_GPIO_WritePin(LCD_E_PORT, LCD_E_PIN, GPIO_PIN_RESET);
    
    // Commands need > 37us to settle  
    for(volatile int i = 0; i < 1000; i++);
}

// Utility functions for displaying LED status
void LCD_Parallel_DisplayEffect(const char* effect_name) {
    LCD_Parallel_SetCursor(0, 0);
    LCD_Parallel_Print("Mode: ");
    LCD_Parallel_Print((char*)effect_name);
    
    // Clear remaining characters on first line
    for(int i = strlen("Mode: ") + strlen(effect_name); i < LCD_COLS; i++) {
        LCD_Parallel_PrintChar(' ');
    }
}

void LCD_Parallel_DisplayStatus(const char* color, int speed, int brightness) {
    char buffer[17];
    
    LCD_Parallel_SetCursor(1, 0);
    snprintf(buffer, sizeof(buffer), "%s S:%d B:%d%%", color, speed, brightness);
    LCD_Parallel_Print(buffer);
    
    // Clear remaining characters on second line
    for(int i = strlen(buffer); i < LCD_COLS; i++) {
        LCD_Parallel_PrintChar(' ');
    }
}

// Simple test function to check LCD functionality
void LCD_Parallel_Test_Simple(void) {
    // Test 1: Clear and basic text
    LCD_Parallel_Clear();
    HAL_Delay(500);
    
    LCD_Parallel_SetCursor(0, 0);
    LCD_Parallel_Print("Test Line 1");
    HAL_Delay(1000);
    
    LCD_Parallel_SetCursor(1, 0);
    LCD_Parallel_Print("Test Line 2");
    HAL_Delay(1000);
    
    // Test 2: Numbers and special characters
    LCD_Parallel_Clear();
    HAL_Delay(500);
    
    LCD_Parallel_SetCursor(0, 0);
    LCD_Parallel_Print("0123456789ABCDEF");
    HAL_Delay(1000);
    
    LCD_Parallel_SetCursor(1, 0);
    LCD_Parallel_Print("!@#$%^&*()_+-=");
    HAL_Delay(2000);
    
    // Test 3: Character by character
    LCD_Parallel_Clear();
    HAL_Delay(500);
    
    LCD_Parallel_SetCursor(0, 0);
    char test_msg[] = "STM32 + LCD OK!";
    for(int i = 0; i < strlen(test_msg); i++) {
        LCD_Parallel_PrintChar(test_msg[i]);
        HAL_Delay(200);
    }
    
    HAL_Delay(2000);
} 