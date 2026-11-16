# STM32U575 Temperature Monitoring & Fault-Logging System

An embedded temperature monitoring and fault-logging system developed in C++ for the STM32U575Z-QI microcontroller. Built with FreeRTOS, the system combines real-time sensor monitoring, interrupt-driven fault detection, and persistent error logging.

## Features

- **Real-Time Task Management:** Uses FreeRTOS to organize sensor sampling, data processing, error handling, logging, and watchdog monitoring into separate tasks.
- **Multithreaded Architecture:** Coordinates concurrent tasks using mutexes and RTOS message queues.
- **Sensor Monitoring:** Uses the ADC to monitor temperature and battery voltage (VBAT).
- **Interrupt-Driven Fault Detection:** Uses GPIO interrupts to detect hardware fault events.
- **Fault Handling:** Transmits fault events through an error queue for processing by a dedicated error-handling task.
- **Persistent Logging:** Uses a separate logging queue to store error information in external EEPROM.
- **Serial Diagnostics:** Communicates through UART for debugging and real-time diagnostic output using PuTTY.

## Hardware & Communication

| Component | Purpose |
|---|---|
| STM32U575Z-QI | Main microcontroller |
| ADC | Temperature and VBAT monitoring |
| GPIO | Interrupt-driven fault detection |
| I2C | Communication with external EEPROM |
| SPI | Peripheral communication |
| UART | Serial diagnostics and logging |
| External EEPROM | Persistent fault storage |

## System Architecture

The firmware is organized around multiple FreeRTOS tasks, each responsible for a specific operation.

### Task Responsibilities

- **Sensor Sampling Task:** Acquires temperature and battery voltage measurements through the ADC.
- **Processing Task:** Processes the acquired sensor data.
- **Error Handling Task:** Receives and handles fault events from the error queue.
- **Logging Task:** Receives log messages and stores them in EEPROM while providing serial output through UART.
- **Watchdog Task:** Monitors system operation through the watchdog mechanism.

### Fault-Logging Pipeline

1. A hardware fault event triggers a GPIO interrupt.
2. The fault information is passed to the error-handling mechanism.
3. The error-handling task processes the event and sends logging information through a message queue.
4. The logging task receives the message.
5. The event is stored in external EEPROM and reported through UART.

## C++ Design

The C++ implementation organizes the firmware into modular components using object-oriented programming principles.

- **Encapsulation:** Groups related data and operations into classes.
- **Modularity:** Separates hardware interactions and system responsibilities into distinct components.
- **Constructors:** Initializes objects and their associated resources.
- **Singleton Pattern:** Provides a controlled instance for components that require shared access.

## Technologies

- **Language:** C++
- **RTOS:** FreeRTOS
- **Microcontroller:** STM32U575Z-QI
- **Hardware Interfaces:** ADC, GPIO, I2C, SPI, UART
- **Debugging:** ST-Link, PuTTY
- **External Storage:** EEPROM

## Project Goals

This project explores the development of real-time embedded systems, with an emphasis on:

- Concurrent task execution and synchronization.
- Inter-task communication using RTOS message queues.
- Hardware-level communication and peripheral integration.
- Interrupt-driven event handling.
- Persistent fault logging.
- Object-oriented firmware architecture in C++.
