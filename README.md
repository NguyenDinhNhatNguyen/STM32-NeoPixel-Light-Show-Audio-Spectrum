# RGB LED Light Show Controller - Hệ thống Điều khiển Trình diễn Ánh sáng LED RGB (STM32F103)

![Status](https://img.shields.io/badge/Status-Completed-success)
![Microcontroller](https://img.shields.io/badge/MCU-STM32F103C8T6-blue)
![Hardware](https://img.shields.io/badge/Hardware-WS2812B%20%7C%20LCD1602-orange)
![Language](https://img.shields.io/badge/Language-C&C++-green)

**Course:** Microprocessors - Microcontrollers (CE103.P24)

**Institution:** University of Information Technology (UIT) - VNU-HCM

**Instructor:** Mr. Tran Ngoc Duc

---

## 🔗 Links / Liên kết

* 📺 **Video Demo:** [https://youtube.com/shorts/84vIITykyJk]
* 📄 **Report / Báo cáo:** [https://drive.google.com/drive/folders/1BntpAL8AeExDC5WBS9ySOS41wpnje4mY?usp=sharing]

---

## 📖 Introduction / Giới thiệu

**[EN]**
This project builds a light show control system for a strip of **60 WS2812B LEDs** (NeoPixel). It utilizes the **STM32F103C8T6** microcontroller with **DMA+PWM** techniques for high-performance LED control. The system also features a real-time music-reactive mode using **FFT** algorithms.

**[VN]**
Dự án xây dựng hệ thống điều khiển trình diễn ánh sáng cho dải **60 LED WS2812B** (NeoPixel). Hệ thống sử dụng vi điều khiển **STM32F103C8T6** kết hợp kỹ thuật **DMA+PWM** để điều khiển LED hiệu suất cao. Hệ thống tích hợp chế độ nháy theo nhạc thời gian thực sử dụng thuật toán **FFT**.

---

## ✨ Features / Tính năng nổi bật

### 🚀 High Performance / Hiệu năng cao
* **[EN]** Uses Timer PWM combined with DMA to generate 800kHz signals for WS2812B LEDs, freeing up the CPU for other tasks.
* **[VN]** Sử dụng Timer PWM kết hợp DMA để tạo xung 800kHz điều khiển LED, giúp giải phóng CPU cho các tác vụ khác.

### 🎨 6 Effect Modes / 6 Chế độ Hiệu ứng
1. **Fade:** Smooth fading in/out / Hiệu ứng mờ dần và sáng dần.
2. **Rainbow:** Moving rainbow colors / Hiệu ứng cầu vồng chuyển động.
3. **Run:** Single pixel running effect / Hiệu ứng điểm sáng chạy.
4. **Flashing:** Strobe effect / Hiệu ứng chớp tắt.
5. **Music Reactive:** Reacts to audio frequencies using **128-point FFT** / Nháy theo nhạc dựa trên phân tích phổ tần số **FFT 128 điểm**.
6. **Off:** Turn off system / Tắt hệ thống.

### 🎛️ Customization / Tùy chỉnh
* **Color:** 9 preset colors / 9 màu sắc cài đặt sẵn.
* **Speed:** 10 speed levels / 10 cấp độ tốc độ.
* **Brightness:** Adjustable from 1% to 100% / Điều chỉnh độ sáng từ 1-100%.

---

## 🛠️ Hardware / Phần cứng

| Component / Linh kiện | Specification / Thông số | Note / Ghi chú |
| :--- | :--- | :--- |
| **MCU** | STM32F103C8T6 (Bluepill) | Cortex-M3, 72MHz |
| **LED** | WS2812B Strip | 60 LEDs |
| **Display** | LCD 16x2 | HD44780 Driver |
| **Input** | Keypad 4x4 | Matrix Keypad |
| **Sensor** | MAX4466 Microphone | Adjustable Gain |
| **Power** | 5V - 3A | External PSU recommended / Khuyên dùng nguồn ngoài |

---

## 🔌 Pinout / Sơ đồ kết nối

| Device / Thiết bị | Function / Chức năng | STM32 Pin / Chân |
| :--- | :--- | :--- |
| **LCD 16x2** | RS | PB0 |
| | E | PB1 |
| | Data (D4-D7) | PB12, PB13, PB14, PB15 |
| **Keypad** | Rows (Hàng) | PA4, PA5, PA6, PA7 |
| | Columns (Cột) | PA1, PA2, PA3, PC15* |
| **LED Strip** | Data Input (DIN) | PA8 (via Resistor) |
| **Microphone** | Analog Out | PA0 (ADC1) |

> **[EN]** * Note: PC15 is used for the last column due to hardware constraints.

> **[VN]** * Lưu ý: PC15 được dùng cho cột cuối cùng do giới hạn phần cứng.

---

## 🎮 Controls / Hướng dẫn sử dụng

Use the 4x4 Keypad to control the system / Sử dụng bàn phím ma trận để điều khiển:

### Mode Selection / Chọn Chế độ
* `1` : **Fade Mode**
* `5` : **Rainbow Mode**
* `9` : **Run Mode**
* `D` : **Flashing Mode**
* `E` : **Music Mode (FFT)**
* `F` : **OFF (Tắt)**

### Adjustments / Điều chỉnh
* `2` / `3` : Decrease / Increase Speed (**Giảm/Tăng Tốc độ**)
* `6` / `7` : Decrease / Increase Brightness (**Giảm/Tăng Độ sáng**)
* `A` : Change Color (**Đổi màu** - *Except Rainbow mode*)

---

## 👥 Authors / Nhóm tác giả

**Team: Trình Hẹ Hẹ**

* **Phan Chí Kiên** (23520804): Core Processing & FFT Algorithms / Xử lý lõi & Thuật toán FFT.
* **Hồ Nhật Khanh** (23520716): Application Logic / Triển khai ứng dụng.
* **Trịnh Long Nhật** (23521103): Hardware Implementation / Triển khai phần cứng.
* **Nguyễn Đình Nhật Nguyên** (23521043): Drivers & System Logic / Xử lý Logic và Driver.

---
*Ho Chi Minh City, June 2025*
