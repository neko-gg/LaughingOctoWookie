#include "connections.h"

ShiftRegLCD123 lcd(LCD_DATA, LCD_CLOCK, SRLCD123);
Bounce butNext = Bounce();
Bounce butOk   = Bounce();
Bounce butBack = Bounce();
VarSpeedServo servoPush;
VarSpeedServo servoRotate;
