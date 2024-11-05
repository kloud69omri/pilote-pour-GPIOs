# pilote-pour-GPIOs
This project focuses on creating a custom driver to control and interact with General Purpose Input/Output (GPIO) pins. The driver provides essential functionalities, including initializing GPIO registers, managing the GPIO clock, configuring GPIO modes, and performing read/write operations.

# Table of Contents
1 Overview  
2 Features  
3 Project Structure  
4 Setup and Usage  
5 Configuration  
6 License  
# Overview
GPIO (General Purpose Input/Output) pins are essential for microcontroller applications as they allow interfacing with a variety of peripheral devices, sensors, and more. This project implements a driver in C for GPIOs, enabling control over the initialization, configuration, and operation of GPIOs on a given microcontroller platform.  

# Features
The GPIO driver provides the following core features:  

GPIO Initialization: Initializes all the registers of a specified GPIO to default values.  
Clock Control: Activates the clock for the GPIO to enable its usage.  
Mode Configuration: Allows setting the GPIO mode, specifying whether it will function as an input, output, or other supported modes.  
Read/Write Operations:  
Bit-wise: Read or write individual bits on the GPIO port.  
Port-wise: Read or write the entire GPIO port in one operation.  
# Project Structure
The project is organized as follows:  


# Setup and Usage
Prerequisites  
A microcontroller development environment compatible with the target microcontroller.  
A toolchain for compiling C code for embedded systems (e.g., GCC for ARM).  
Instructions  
Clone the repository:  

  
git clone (https://github.com/kloud69omri/pilote-pour-GPIOs.git)  
cd GPIO-Driver  
Build the project:  

Use the provided Makefile or your development environment’s tools to compile the code.  
Integrate the GPIO driver:  

Include gpio_driver.h in your application code to access the GPIO driver functions.  
Refer to the examples/gpio_example.c file to understand basic usage.  
Example Usage:  

To initialize a GPIO pin, activate the clock, configure it as output, and set it high:  


GPIO_Init(GPIOA);               // Initialize GPIOA to default values  
GPIO_EnableClock(GPIOA);        // Enable clock for GPIOA  
GPIO_SetMode(GPIOA, PIN0, OUTPUT); // Set GPIOA Pin 0 as output  
GPIO_WritePin(GPIOA, PIN0, HIGH);  // Set GPIOA Pin 0 high  
# Configuration
Configure GPIO settings by modifying the relevant macros in gpio_driver.h or by calling driver functions with the appropriate parameters:  

GPIO Modes: Set the mode (Input, Output, etc.) by using GPIO_SetMode().    
Pin Read/Write: Use GPIO_ReadPin() and GPIO_WritePin() for bit-wise operations,   and GPIO_WritePort() for port-wise operations.  
# License
This project is licensed under the MIT License. See the LICENSE file for more information.  
