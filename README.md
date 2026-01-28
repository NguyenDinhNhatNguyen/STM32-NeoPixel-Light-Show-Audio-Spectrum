# RGB LED Light Show (NeoPixel) Controller - STM32F103

![Status](https://img.shields.io/badge/Status-Completed-success)
![Microcontroller](https://img.shields.io/badge/MCU-STM32F103C8T6-blue)
![Hardware](https://img.shields.io/badge/Hardware-WS2812B%20%7C%20LCD1602-orange)
![Language](https://img.shields.io/badge/Language-C&C++-green)

**Course:** Microprocessors - Microcontrollers (CE103.P24)

**Institution:** University of Information Technology (UIT) - VNU-HCM

**Instructor:** Mr. Tran Ngoc Duc

---

## 🔗 Links 

* 📺 **Video Demo:** [https://youtube.com/shorts/84vIITykyJk]
* 📄 **Report:** [https://drive.google.com/drive/folders/1BntpAL8AeExDC5WBS9ySOS41wpnje4mY?usp=sharing]

---

## 📖 Introduction

This project builds a light show control system for a strip of **60 WS2812B LEDs** (NeoPixel). It utilizes the **STM32F103C8T6** microcontroller with **DMA+PWM** techniques for high-performance LED control. The system also features a real-time music-reactive mode using **FFT** algorithms.

---

## ✨ Features 

### 🚀 High Performance
* **Non-blocking Driver:** Uses Timer PWM combined with DMA to generate 800kHz signals for WS2812B LEDs, freeing up the CPU for other tasks.

### 🎨 6 Effect Modes 
1. **Fade:** Smooth fading in/out.
2. **Rainbow:** Moving rainbow colors. 
3. **Run:** Single pixel running effect.
4. **Flashing:** Strobe effect.
5. **Music Reactive:** Reacts to audio frequencies using **128-point FFT**.
6. **Off:** Turn off system.

### 🎛️ Customization
* **Color:** 9 preset color.
* **Speed:** 10 speed levels.
* **Brightness:** Adjustable from 1% to 100%%.

---

## 🛠️ Hardware
| Component | Specification | Note |
| :--- | :--- | :--- |
| **MCU** | STM32F103C8T6 (Bluepill) | Cortex-M3, 72MHz |
| **LED** | WS2812B Strip | 60 LEDs |
| **Display** | LCD 16x2 | HD44780 Driver |
| **Input** | Keypad 4x4 | Matrix Keypad |
| **Sensor** | MAX4466 Microphone | Adjustable Gain |
| **Power** | 5V - 3A | External PSU recommended |

---

## 🔌 Pinout

| Device | Function | STM32 Pin  |
| :--- | :--- | :--- |
| **LCD 16x2** | RS | PB0 |
| | E | PB1 |
| | Data (D4-D7) | PB12, PB13, PB14, PB15 |
| **Keypad** | Rows | PA4, PA5, PA6, PA7 |
| | Columns | PA1, PA2, PA3, PC15* |
| **LED Strip** | Data Input (DIN) | PA8 (via Resistor) |
| **Microphone** | Analog Out | PA0 (ADC1) |

> * Note: PC15 is used for the last column due to hardware constraints.

---

## 🎮 Controls 

Use the 4x4 Keypad to control the system:

### Mode Selection 
* `1` : **Fade Mode**
* `5` : **Rainbow Mode**
* `9` : **Run Mode**
* `D` : **Flashing Mode**
* `E` : **Music Mode (FFT)**
* `F` : **OFF**

### Adjustments
* `2` / `3` : Decrease / Increase Speed
* `6` / `7` : Decrease / Increase Brightness 
* `A` : Change Color (*Except Rainbow mode*)

---

## 👥 Authors

**Team: Trình Hẹ Hẹ**

* **Phan Chí Kiên** (23520804): Core Processing & FFT Algorithms.
* **Hồ Nhật Khanh** (23520716): Application Logic.
* **Trịnh Long Nhật** (23521103): Hardware Implementation.
* **Nguyễn Đình Nhật Nguyên** (23521043): Drivers & System Logic.

---
*Ho Chi Minh City, June 2025*
