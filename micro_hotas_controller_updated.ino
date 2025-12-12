// Requires Arduino Joystick Library https://github.com/MHeironimus/ArduinoJoystickLibrary
#include <Joystick.h>
Joystick_ Joystick;
 
int JoystickX;
int JoystickY;
int JoystickZ;
int Throttle;
int JoystickRX;

int currentButtonState0;
int lastButtonState0;
int currentButtonState1;
int lastButtonState1;
int currentButtonState2;
int lastButtonState2;
int currentButtonState3;
int lastButtonState3;
int currentButtonState4;
int lastButtonState4;
int currentButtonState5;
int lastButtonState5;
int currentButtonState6;
int lastButtonState6;
int currentButtonState7;
int lastButtonState7;
int currentButtonState8;
int lastButtonState8;


int load=3; //pin 1
int clockEnable=7; //pin 15
int dataIn=5; //pin 9
int clockIn=2; //pin 2

byte myByte1;
byte myByte2;


void setup() {
  Serial.begin(9600);
  // pinMode(6, INPUT_PULLUP);
  // pinMode(7, INPUT_PULLUP);
  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);
  pinMode(A3, INPUT_PULLUP);
  // pinMode(A4, INPUT_PULLUP);
  // pinMode(A5, INPUT_PULLUP);
  // pinMode(A6, INPUT_PULLUP);
  // pinMode(A7, INPUT_PULLUP);
  // pinMode(A8, INPUT_PULLUP); 
  // pinMode(A9, INPUT_PULLUP);
  
  pinMode(load,OUTPUT);
pinMode(clockEnable,OUTPUT);
pinMode(clockIn,OUTPUT);
pinMode(dataIn,INPUT);

// Initialize Joystick Library
  Joystick.begin();
  Joystick.setXAxisRange(0, 1024); 
  Joystick.setYAxisRange(0, 1024);
  Joystick.setZAxisRange(0, 1024);
  Joystick.setThrottleRange(0, 1024);
  Joystick.setRxAxisRange(0, 1024);
}

void loop() {
digitalWrite(load,LOW);
delayMicroseconds(5);
digitalWrite(load,HIGH);
delayMicroseconds(5);

digitalWrite(clockIn,HIGH);
digitalWrite(clockEnable,LOW);
myByte1 = shiftIn(dataIn,clockIn,LSBFIRST);
myByte2=shiftIn(dataIn,clockIn,LSBFIRST);
digitalWrite(clockEnable,HIGH);

int button1=bitRead(myByte1,0);
Serial.print("button 1: ");
Serial.print(button1);

int button2=bitRead(myByte1,1);
Serial.print(" button 2: ");
Serial.print(button2);

int button3=bitRead(myByte1,2);
Serial.print(" button 3: ");
Serial.print(button3);

int button4=bitRead(myByte1,3);
Serial.print(" button 4: ");
Serial.print(button4);

int button5=bitRead(myByte1,4);
Serial.print(" button 5: ");
Serial.print(button5);

int button6=bitRead(myByte1,5);
Serial.print(" button 6: ");
Serial.print(button6);

int button7=bitRead(myByte1,6);
Serial.print(" button 7: ");
Serial.print(button7);

int button8=bitRead(myByte1,7);
Serial.print(" button 8: ");
Serial.println(button8);

// Read Joystick
  JoystickX = analogRead(A1); // Hall effect sensor connects to this analog pin
  JoystickY = analogRead(A2); // Hall effect sensor connects to this analog pin

// Read Rudder Pedals
  JoystickZ = analogRead(A3); // Hall effect sensor connects to this analog pin

// Read Throttle
  Throttle = analogRead(A4); // Potentiometer signal connects to this analog pin
  JoystickRX = analogRead(A5);

// Read Switches
int currentButtonState0 = !digitalRead(~button1); // Button 0
  if (currentButtonState0 != lastButtonState0)
  {
  Joystick.setButton(0, currentButtonState0);
  lastButtonState0 = currentButtonState0;
  }

int currentButtonState1 = !digitalRead(~button2); // Button 1
  if (currentButtonState1 != lastButtonState1)
  {
  Joystick.setButton(1, currentButtonState1);
  lastButtonState1 = currentButtonState1;
  }
  
int currentButtonState2 = !digitalRead(~button3); // Button 2
  if (currentButtonState2 != lastButtonState2)
  {
  Joystick.setButton(2, currentButtonState2);
  lastButtonState2 = currentButtonState2;
  }

int currentButtonState3 = !digitalRead(~button4); // Button 3
  if (currentButtonState3 != lastButtonState3)
  {
  Joystick.setButton(3, currentButtonState3);
  lastButtonState3 = currentButtonState3;
  }
  
int currentButtonState4 = !digitalRead(~button5); // Button 4
  if (currentButtonState4 != lastButtonState4)
  {
  Joystick.setButton(4, currentButtonState4);
  lastButtonState4 = currentButtonState4;
  } 

int currentButtonState5 = !digitalRead(~button6); // Button 5
  if (currentButtonState5 != lastButtonState5)
  {
  Joystick.setButton(5, currentButtonState5);
  lastButtonState5 = currentButtonState5;
  } 
  
int currentButtonState6 = !digitalRead(~button7); // Button 6
  if (currentButtonState6 != lastButtonState6)
  {
  Joystick.setButton(6, currentButtonState6);
  lastButtonState6 = currentButtonState6;
  }  

int currentButtonState7 = !digitalRead(~button8); // Button 7
  if (currentButtonState7 != lastButtonState7)
  {
  Joystick.setButton(7, currentButtonState7);
  lastButtonState7 = currentButtonState7;
  }  
      
// Output Controls
  Joystick.setXAxis(JoystickX);
  Joystick.setYAxis(JoystickY);
  Joystick.setZAxis(JoystickZ);
  Joystick.setThrottle(Throttle);
  Joystick.setRxAxis(JoystickRX);

  Joystick.sendState();

} 