# 🌡️ Smart HVAC Control System

## 📌 Project Overview
The **Smart HVAC Control System** is an embedded application designed to dynamically regulate temperature using an **ATmega32 Microcontroller**. The project is developed applying a **Layered Software Architecture (MCAL, HAL, APP)** to ensure code modularity, reusability, and hardware abstraction.

This system intelligentely adjusts a cooling/heating mechanism based on real-time temperature readings, utilizing dynamic PWM for speed control and EEPROM for non-volatile state retention.

---

## 🏗️ Software Architecture
The firmware is built using a strict layered architecture to separate hardware-specific drivers from the application logic:

*   **MCAL (Microcontroller Abstraction Layer):** 
    *   `ADC`: Reads raw analog signals from sensors.
    *   `PWM`: Generates duty cycles via Timer0 for motor speed control.
    *   `EEPROM`: Handles non-volatile memory read/write operations.
*   **HAL (Hardware Abstraction Layer):**
    *   `LM35`: Converts raw ADC values into accurate Celsius readings.
    *   `Motor (L293D)`: Controls rotational direction and applies PWM signals.
    *   `LCD 16x2`: Manages the interactive user interface (4-bit mode).
*   **APP (Application Layer):** 
    *   `main.c`: Contains the core logic, threshold processing, and state management.

---

## ⚙️ Hardware Components
*   **Microcontroller:** ATmega32 (8MHz)
*   **Temperature Sensor:** LM35
*   **Motor Driver:** L293D
*   **Actuator:** DC Motor
*   **Display:** 16x2 LCD Display (4-bit mode)
*   **Indicators:** Green LED (Cooling Mode), Yellow LED (Heating Mode)
*   **Inputs:** Push buttons for dynamic Set-Temperature adjustment.

---

## ✨ Key Features
1.  **Dynamic PWM Speed Control:** The DC motor's speed is directly proportional to the delta between the current temperature and the set temperature. The higher the difference, the faster the motor spins to reach the desired state.
2.  **EEPROM State Retention:** The system saves the user's defined "Set Temperature" and the last operational mode (Heating/Cooling) to the internal EEPROM. Upon system reset or power failure, the system automatically restores its previous state seamlessly.
3.  **Interactive UI:** Real-time display of current temperature, set temperature, and system mode on the LCD.
4.  **Hardware Abstraction:** The codebase can be easily ported to different AVR microcontrollers with minimal modifications due to the modular architecture.

---

## 📸 Simulation & Demo

### Circuit Schematic
*(Replace this text and the link below with the path to your actual screenshot)*
![Circuit Schematic](Path_to_your_screenshot_image.png)

### Video Demonstration
*(You can add a link to your LinkedIn video or a YouTube demo here)*
[Watch the system in action on LinkedIn](Link_to_your_video)

---

## 📂 Repository Structure
```text
├── Firmware/
│   ├── APP/             # Application Logic (main.c)
│   ├── HAL/             # Hardware Abstraction Layer (LM35, Motor, LCD)
│   ├── MCAL/            # Microcontroller Abstraction Layer (ADC, PWM, EEPROM)
│   └── Debug/           # Contains the .elf and .hex executable files
├── Simulation/
│   └── Smart_AC.pdsprj  # Proteus Simulation File
└── README.md
```
---

🚀 How to Run
Simulation: Open the Smart_AC.pdsprj file using Proteus.

Double-click the ATmega32 microcontroller in the schematic.

Load the .elf or .hex file located in the Firmware/Debug/ directory.

Set the clock frequency to 8MHz.

Run the simulation. Use the interactive push buttons to adjust the set temperature and observe the dynamic response of the motor and LEDs.

Developed as a portfolio project showcasing embedded systems principles and C programming.

