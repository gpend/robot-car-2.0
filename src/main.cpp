#include <Arduino.h>
#include <Dabble.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();

Adafruit_DCMotor *motorFL = AFMS.getMotor(1);
Adafruit_DCMotor *motorFR = AFMS.getMotor(2);
Adafruit_DCMotor *motorRL = AFMS.getMotor(3);
Adafruit_DCMotor *motorRR = AFMS.getMotor(4);

void setup() {
  Serial.begin(9600);
  Dabble.begin(9600);

  if (!AFMS.begin())
  { // create with the default frequency 1.6KHz
    // if (!AFMS.begin(1000)) {  // OR with a different frequency, say 1KHz
    Serial.println("Could not find Motor Shield. Check wiring.");
    while (1)
      ;
  }
  Serial.println("Motor Shield found.");
}

void loop() {

  char read_char = Serial.read();
  switch (read_char)
  {
  case 'f':
    break;
  
  default:
    break;
  }


}
//
//  MPU6050
//

//
//  forward
//

void goForward(int speed)
{
  setMotorsLeft(speed, FORWARD);
  setMotorsLeft(speed, FORWARD);
};

void forwardForwardLeft(int speed)
{
setMotorsRight(speed, FORWARD);
setMotorsLeft((speed*.50), FORWARD);
}

void forwardLeft(int speed)
{
  setMotorsRight(speed, FORWARD);
  setMotorsLeft((speed * .25), BACKWARD);
}

void forwardLeftLeft(int speed)
{
  setMotorsRight(speed, FORWARD);
  setMotorsLeft((speed*.50), BACKWARD);
}


//
//  backwards
//

void goBackwards(int speed)
{
  setMotorsLeft(speed, BACKWARD);
  setMotorsLeft(speed, BACKWARD);
};

void setMotorsLeft (int speed, uint8_t direction){
  motorFL->setSpeed(speed);
  motorRL->setSpeed(speed);
  motorFL->run(direction);
  motorRL->run(direction);
}

void setMotorsRight(int speed, uint8_t direction){
  motorFR->setSpeed(speed);
  motorRR->setSpeed(speed);
  motorFR->run(direction);
  motorRR->run(direction);
}
