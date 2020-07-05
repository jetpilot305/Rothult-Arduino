# Rothult-Arduino
Arduino code to repurpose Ikea Rothult lock for serial control

**STM32L051K86 UFQFPN32**

![Pinout](/Images/Pinout.JPG)

Pin | IO | Connection
-|-|-
PA14  | O   | SWCLK (Pin 1 Header)
PA13  | IO  | SWDIO (Pin 2 Header)
PA10  | I   | USART1 RX (Pin 5 Header)
PA9   | O   | USART1 TX (Pin 6 Header)
PA15  | O   | Buzzer
PB4   | I   | Switch (extended)
PB5   | I   | Switch (restracted)
PB7   | O   | Motor CW
PB8   | O   | Motor CCW
PC14  | I   | Battery Kill
PA1   | O   | set to 0 for battery ref
PA2   | I   | Battery Volt/2
PA4   | O   | ~SS to RFID
PA5   | O   | SCLK to RFID
PA6   | I   | MISO from RFID
PA7   | O   | MOSI to RFID
PB0   | I   | IRQ from RFID
