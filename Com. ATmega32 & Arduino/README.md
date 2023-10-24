# Communication Protocols
Welcome to the Communication Protocols repository! This repository contains a project that demonstrates the use of different communication protocols to facilitate data exchange between two microcontrollers: an ATmega32 as the master and an Arduino. The project showcases the utilization of I2C and UART communication protocols to read time from an RTC DS1307 module and display it on LCD screens connected to both microcontrollers.

# Project Overview
In this project, two key communication protocols are implemented:

- I2C (Inter-Integrated Circuit): The ATmega32 acts as the master microcontroller, using the I2C protocol to communicate with the RTC DS1307 module. It reads the real-time clock data from the RTC and displays it on an LCD screen.

- UART (Universal Asynchronous Receiver/Transmitter): After acquiring the time data, the ATmega32 sends this information to an Arduino microcontroller using UART communication. The Arduino receives the data and displays the time on another LCD screen.

This project exemplifies the integration of multiple communication protocols to enable data transfer between microcontrollers and peripherals.

![Simulation picture](https://github.com/moekhodry11/AVR-Projects/assets/86708003/77ec3089-321a-4385-bc8a-2807935f7a18)
![image](https://github.com/moekhodry11/AVR-Projects/assets/86708003/1276942f-cad2-4dd7-870e-7352e2cfb530)


#### You can watch HW video [here](https://drive.google.com/file/d/18xMdNU_5WgsJFeswIda6HptepBNdNLRS/view?usp=sharing)
