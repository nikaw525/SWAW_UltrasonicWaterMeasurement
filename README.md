# Intelligent bottle based on an ultrasonic sensor

The project is based on two microcontrollers from the stm32 family, exchanging information with each other via a radio module. The first microcontroller uses the HC-SR04 ultrasonic sensor to measure the water level in the bottle and sends the collected data to the second device. The second device is equipped with a TFT touch display, which displays the bottle status, the amount of water consumed during the day and the user's daily water demand.

# Hardware

- STM32 NUCLEO-L432KC
- STM32 NUCLEO-F429ZI
- Ultrasonic distance sensor HC-SR04
- Radio module FS100A transmitter + 433 MHz receiver
- TFT4.3 "EVB.DIS.D002.TFT4.3"
