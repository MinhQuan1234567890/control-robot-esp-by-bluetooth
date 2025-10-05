#define IN1 12
#define IN2 13
#define IN3 15
#define IN4 17
#include <BluetoothSerial.h>
#include"BluetoothSerial.h"
BluetoothSerial BT;
void setup() {
  BT.begin("Clanker");
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // in 1+2 = motor1     in 3+4 = motor 2
  if(BT.available()) {
    char read = BT.read();

    if(read == '1') {
      forward();
    } 
    else if(read =='2') {
      backward();
    }
    else if(read =='3') {
      right();
    }
    else if(read =='4') {
      left();
    }
    else {
    stop();
  }
}
}
void forward() {
  analogWrite(IN1, 255);
  analogWrite(IN2, 0);
  analogWrite(IN3, 255);
  analogWrite(IN4, 0);
}

void backward() {
  analogWrite(IN1, 0);
  analogWrite(IN2, 255);
  analogWrite(IN3, 0);
  analogWrite(IN4, 255);
}

void left() {
  analogWrite(IN1, 0);
  analogWrite(IN2, 0);
  analogWrite(IN3, 255);
  analogWrite(IN4, 0);
}

void right() {
  analogWrite(IN1, 255);
  analogWrite(IN2, 0);
  analogWrite(IN3, 0);
  analogWrite(IN4, 0);
}
void stop() {
  analogWrite(IN1, 0);
  analogWrite(IN2, 0);
  analogWrite(IN3, 0);
  analogWrite(IN4, 0);
}