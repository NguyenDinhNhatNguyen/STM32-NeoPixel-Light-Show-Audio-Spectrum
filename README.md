# Bảng LED RGB (NeoPixel) với hiệu ứng "Light Show" - STM32F103

![Status](https://img.shields.io/badge/Status-Completed-success)
![Microcontroller](https://img.shields.io/badge/MCU-STM32F103C8T6-blue)
![Hardware](https://img.shields.io/badge/Hardware-WS2812B%20%7C%20LCD1602-orange)
![Language](https://img.shields.io/badge/Language-C&C++-green)

**Đồ án môn học:** Vi xử lý - Vi điều khiển (CE103.P24)

**Trường:** Đại học Công nghệ Thông tin (UIT) - ĐHQG-HCM

**Giảng viên hướng dẫn:** Trần Ngọc Đức

## 🔗 Tài liệu & Demo (Links)

* 📺 **Video Demo sản phẩm:** https://youtube.com/shorts/84vIITykyJk
* 📄 **Báo cáo:** https://drive.google.com/drive/folders/1BntpAL8AeExDC5WBS9ySOS41wpnje4mY?usp=sharing

## Giới thiệu (Overview)

Dự án xây dựng hệ thống điều khiển trình diễn ánh sáng cho dải 60 LED RGB WS2812B. Hệ thống sử dụng vi điều khiển STM32F103C8T6 kết hợp kỹ thuật DMA+PWM để điều khiển LED và thuật toán FFT để thực hiện hiệu ứng nháy theo nhạc thời gian thực.

## Tính năng nổi bật (Features)

* **Hiệu năng cao:** Sử dụng Timer PWM kết hợp DMA để điều khiển LED WS2812B (800kHz), giúp tiết kiệm tài nguyên CPU.
* **6 Chế độ hiển thị:**
  1. **Fade:** Hiệu ứng mờ dần/sáng dần.
  2. **Rainbow:** Hiệu ứng cầu vồng chuyển động.
  3. **Run:** Hiệu ứng chạy điểm sáng (Pixel Run).
  4. **Flashing:** Hiệu ứng chớp tắt.
  5. **Music Reactive:** Nháy theo nhạc dựa trên phân tích phổ tần số (FFT 128 điểm).
  6. **Off:** Tắt hệ thống.
* **Tùy chỉnh thông số:**
  * Thay đổi 9 màu sắc khác nhau.
  * Điều chỉnh 10 mức tốc độ.
  * Điều chỉnh độ sáng từ 1% đến 100%.

## Phần cứng (Hardware)

* **MCU:** STM32F103C8T6 (Bluepill).
* **LED:** LED dây WS2812B (60 bóng).
* **Hiển thị:** Màn hình LCD 16x2 (Chip HD44780).
* **Nhập liệu:** Bàn phím ma trận 4x4 (Keypad).
* **Cảm biến:** Module Microphone MAX4466.
* **Nguồn:** Adapter 5V-3A.

## Sơ đồ chân (Pinout)

| Thiết bị | Chân chức năng | Chân STM32 | Ghi chú |
| :--- | :--- | :--- | :--- |
| **LCD 16x2** | RS | PB0 | |
| | E | PB1 | |
| | D4 - D7 | PB12, PB13, PB14, PB15 | Chế độ 4-bit |
| **Keypad 4x4** | Hàng (Rows) | PA4, PA5, PA6, PA7 | |
| | Cột (Cols) | PA1, PA2, PA3, PC15 | *PC15 thay thế cột 4* |
| **LED WS2812B** | DIN | PA8 | Qua trở 220 Ohm |
| **Microphone** | OUT | PA0 | Analog Input (ADC1) |

## Cài đặt & Phát triển

* **IDE:** STM32CubeIDE v1.18.1.
* **Thư viện:** STM32 HAL Driver.
* **Công cụ nạp:** STM32 ST-LINK Utility.

## Hướng dẫn sử dụng (User Manual)

Điều khiển hệ thống thông qua bàn phím ma trận:

* **Chọn Chế độ (Mode):**
  * `1`: Fade (Mờ dần)
  * `5`: Rainbow (Cầu vồng)
  * `9`: Run (Chạy điểm)
  * `D`: Flashing (Chớp tắt)
  * `E`: Music (Nháy theo nhạc FFT)
  * `F`: Tắt đèn (OFF)

* **Điều chỉnh:**
  * `2` / `3`: Giảm / Tăng tốc độ.
  * `6` / `7`: Giảm / Tăng độ sáng.
  * `A`: Đổi màu (xoay vòng 9 màu).

## Nhóm thực hiện (Authors)

Nhóm: **Trình Hẹ Hẹ**

1. **Phan Chí Kiên** (23520804) - Xử lý lõi & Thuật toán FFT.
2. **Hồ Nhật Khanh** (23520716) - Triển khai ứng dụng.
3. **Trịnh Long Nhật** (23521103) - Triển khai phần cứng.
4. **Nguyễn Đình Nhật Nguyên** (23521043) - Xử lý Logic và Driver.

---
*Thành phố Hồ Chí Minh, Tháng 06 năm 2025*
