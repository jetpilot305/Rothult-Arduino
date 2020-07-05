/*
 Rothult
*/
#include <Arduino.h>

HardwareSerial Serial1(PA10, PA9);
static const uint8_t MotorCW = PB8;
static const uint8_t MotorCCW = PB7;
static const uint8_t Buzzer = PA15;
static const uint8_t LimitOpen = PB4;
static const uint8_t LimitClose = PB5;
static const uint8_t BatteryKill = PC14;

// the setup function runs once when you press reset or power the board
void setup() {
  // Motor Enables
  pinMode(MotorCW, OUTPUT);
  digitalWrite(MotorCW, LOW);
  pinMode(MotorCCW, OUTPUT);
  digitalWrite(MotorCCW, LOW);

  // Buzzer
  pinMode(Buzzer,OUTPUT);
  digitalWrite(Buzzer, LOW);

  // Battery Kill
  pinMode(BatteryKill, OUTPUT);
  digitalWrite(BatteryKill, LOW);

  // End Switches
  pinMode(LimitOpen, INPUT);
  pinMode(LimitClose, INPUT);

  // Serial port
  Serial1.begin(9600);
  Serial1.println("OpenROTHULT");
}

// the loop function runs over and over again forever
void loop() {
  unsigned int i;
  unsigned char c;

/*
  // Turn motor
  digitalWrite(MotorCCW, HIGH); 
  delay(500);             
  digitalWrite(MotorCCW, LOW);  
  delay(500);             

  // Turn motor
  digitalWrite(MotorCW, HIGH); 
  delay(500);             
  digitalWrite(MotorCW, LOW);  

  // Buzzer
  for (i=0; i<500; i++) {
    digitalWrite(PA15, HIGH);
    delay(1);                
    digitalWrite(PA15, LOW); 
    delay(1);                
  }

  delay (3000);

  Serial1.println("Hello World");
  delay (1000);

  if (digitalRead (LimitOpen)) {
    digitalWrite(Buzzer, HIGH);
    delay(1);                
    digitalWrite(Buzzer, LOW); 
    delay(1);                
  }
  if (digitalRead (LimitClose)) {
    digitalWrite(Buzzer, HIGH);
    delay(2);                
    digitalWrite(Buzzer, LOW); 
    delay(2);                
  }
*/

  if (Serial1.available() > 0) {
    c = Serial1.read();
    switch (c) {
      // 0 - Buzzer
      case '0': 
      case 'b': 
      case 'B': 
        for (i=0; i<500; i++) {
          digitalWrite(Buzzer, HIGH);
          delay(1);                
          digitalWrite(Buzzer, LOW); 
          delay(1);
        }    
        break;            
      
      // 1 - CW 
      case '1': 
        digitalWrite(MotorCW, HIGH);
        delay(50);                
        digitalWrite(MotorCW, LOW); 
        delay(50);
        break;

      // 2 - CCW 
      case '2': 
        digitalWrite(MotorCCW, HIGH);
        delay(50);                
        digitalWrite(MotorCCW, LOW); 
        delay(50);
        break;

      case 'o': 
      case 'O':
        if (!digitalRead (LimitOpen)) {
          digitalWrite(MotorCW, HIGH);
          while (!digitalRead (LimitOpen));
          digitalWrite(MotorCW, LOW);
          // brake
          digitalWrite(MotorCCW, HIGH);
          delay (10);
          digitalWrite(MotorCCW, LOW);
        }
        Serial1.println("Open");
        break;

      case 'c': 
      case 'C':
        if (!digitalRead (LimitClose)) {
          digitalWrite(MotorCCW, HIGH);
          while (!digitalRead (LimitClose));
          digitalWrite(MotorCCW, LOW);
          // brake
          digitalWrite(MotorCW, HIGH);
          delay (10);
          digitalWrite(MotorCW, LOW);
        }
        Serial1.println("Close");
        break;
    
    }
  }
}
