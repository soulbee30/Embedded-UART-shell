# Embedded-UART-shell
STM32 UART Command Interface (Bare-Metal)
A bare-metal UART driver and command parser built on STM32 (Cortex-M4), demonstrating low-level register programming, real-time data handling, and string-based command execution without using HAL libraries.

🚀 Features
📡 UART Communication (USART2)
Direct register-level configuration (CR1, BRR, SR, DR)
TX and RX implemented without HAL
🔁 Real-Time Echo
Receives data byte-by-byte using RXNE flag
Echoes back to terminal (Tera Term)
🧠 Command Parser (CLI)
Supports string commands like:
LEDON
LEDOFF
Uses strcmp() for command matching
💡 GPIO Control
Controls onboard LEDs via UART commands
Direct manipulation of ODR register
🧩 Modular Design
Separate drivers for GPIO and USART
Simple state_machine() for command handling
🧠 Key Learnings
Understanding UART as a byte-stream protocol
Handling RXNE, TXE, and overrun conditions
Importance of non-blocking design
Difference between:
char[] vs const char *
polling vs interrupt-based reception
Safe string handling using strcmp()
⚙️ Hardware Setup
🧠 MCU: STM32F407 Discovery Board
🔌 Interface: ST-LINK Virtual COM Port / USB-UART
🖥️ Terminal: Tera Term
UART Pins (USART2)
Pin	Function
PA2	TX
PA3	RX
🧪 How It Works
UART receives data one byte at a time
Data is buffered until delimiter (\r)
String is passed to state_machine()
Command is parsed and action is executed
🧾 Example
Input (Tera Term):
LEDON
Output:
LEDs ON
🛠️ Future Improvements
🔄 Interrupt-based UART RX
🔁 Ring buffer implementation
🧠 Command queue system
📟 CLI with multiple commands
⚡ DMA-based UART
📂 Project Structure
/src
  ├── main.c
  ├── gpio.c
  ├── usart.c
  ├── state_machine.c

/include
  ├── gpio.h
  ├── usart.h
🎯 Why This Project?

This project demonstrates how high-level APIs like HAL abstract complex hardware behavior. By implementing UART at the register level, it exposes:

Timing sensitivity of peripherals
Hardware flag synchronization
Real-world debugging challenges (e.g., RXNE, ORE)
