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

**Based on the work from Brian McEvoy & Allmänt Grinande**

(https://blognamn.wordpress.com/2018/11/01/teardown-of-the-ikea-rothult-rfid-lock/)

(https://hackaday.com/2019/05/05/ripping-up-a-rothult/)

(http://www.24hourengineer.com/2019/04/2019-04-09-tu-ikea-rothult-teardown.html)

**1) Install Arduino**

**2) Add STM32duino to Arduino**

![Arduino STM](/Images/ArduinoSTM32.JPG)

**3) Create L051 variant**

L051 variant needs to be added to STM32Arduino package by adding/modifying files at
C:\Users\...\AppData\Local\Arduino15\packages\STM32\hardware with files from repository.

**4) Arduino Configuration**    
![Arduino Configuration](/Images/ArduinoConfig.JPG)

**5) Compile INO from repository using Arduino**

![Arduino Compile](/Images/ArduinoCompile.JPG)

**6) Connect ST-LINK to SWD interface using Rothult Header**

![ST-LINK Connection](/Images/SWDconnect.jpg)

**7) Program device using ST-Link**

![ST-LINK Program](/Images/StlinkProgram.JPG)


