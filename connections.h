#ifndef CONNECTIONS_H
#define CONNECTIONS_H

#include <Arduino.h> // A0, A1, ...
#include <ShiftRegLCD123.h>
#include <Bounce2.h>
#include <VarSpeedServo.h>

#define BUT_NEXT  7
#define BUT_OK    8
#define BUT_BACK  9

#define SERVO_PUSH   12
#define SERVO_ROTATE 13

#define LCD_DATA  10
#define LCD_CLOCK 11

extern ShiftRegLCD123 lcd;
extern Bounce butNext;
extern Bounce butOk;
extern Bounce butBack;
extern VarSpeedServo servoPush;
extern VarSpeedServo servoRotate;

#endif
