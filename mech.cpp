#include "mech.h"
#include "connections.h"
#include "status.h"

namespace mech {
  void hold() {
    servoPush.write(SERVO_PUSH_HOLD_DEGREE, SERVO_PUSH_SPEED, true);
    status::holdState = status::holding;
    delay(SERVO_PUSH_DELAY);
  }

  void release() {
    servoPush.write(SERVO_PUSH_RELEASE_DEGREE, SERVO_PUSH_SPEED, true);
    status::holdState = status::released;
    delay(SERVO_PUSH_DELAY);
  }

  void push() {
    if (status::holdState == status::released) {
      if (status::turnState == status::central)
        servoPush.write(SERVO_PUSH_PUSH_C_DEGREE, SERVO_PUSH_SPEED, true);
      if (status::turnState == status::clockWise)
        servoPush.write(SERVO_PUSH_PUSH_CW_DEGREE, SERVO_PUSH_SPEED, true);
      if (status::turnState == status::counterClockWise)
        servoPush.write(SERVO_PUSH_PUSH_CCW_DEGREE, SERVO_PUSH_SPEED, true);
      delay(SERVO_PUSH_DELAY);
      servoPush.write(SERVO_PUSH_RELEASE_DEGREE, SERVO_PUSH_SPEED, true);
      delay(SERVO_PUSH_DELAY);
    } else {
      release();
      push();
      hold();
    }
  }
  
  void rotateToC() {
    if (status::holdState == status::released) {
      servoRotate.write(SERVO_ROTATE_C_DEGREE, SERVO_ROTATE_SPEED, true);
      delay(SERVO_ROTATE_DELAY);
    } else {
      if (status::turnState == status::clockWise) {
        servoRotate.write(SERVO_ROTATE_CW_TO_C_HOLD_DEGREE, SERVO_ROTATE_SPEED, true);
        delay(SERVO_ROTATE_DELAY);
        release();
        servoRotate.write(SERVO_ROTATE_C_DEGREE, SERVO_ROTATE_SPEED, true);
        delay(SERVO_ROTATE_DELAY);
        hold();
      } else if (status::turnState == status::counterClockWise) {
        servoRotate.write(SERVO_ROTATE_CCW_TO_C_HOLD_DEGREE, SERVO_ROTATE_SPEED, true);
        delay(SERVO_ROTATE_DELAY);
        release();
        servoRotate.write(SERVO_ROTATE_C_DEGREE, SERVO_ROTATE_SPEED, true);
        delay(SERVO_ROTATE_DELAY);
        hold();
      } else {
        servoRotate.write(SERVO_ROTATE_C_DEGREE, SERVO_ROTATE_SPEED, true);
        delay(SERVO_ROTATE_DELAY);        
      }
    }
    status::turnState = status::central;
  }
  
  void rotateToCW() {
    if (status::holdState == status::released) {
      servoRotate.write(SERVO_ROTATE_CW_DEGREE, SERVO_ROTATE_SPEED, true);
      if (status::turnState == status::counterClockWise)
        delay(SERVO_ROTATE_DELAY);
      delay(SERVO_ROTATE_DELAY);
    } else {
      if (status::turnState == status::central) {
        servoRotate.write(SERVO_ROTATE_TO_CW_HOLD_DEGREE, SERVO_ROTATE_SPEED, true);
        delay(SERVO_ROTATE_DELAY);
        release();
        servoRotate.write(SERVO_ROTATE_CW_DEGREE, SERVO_ROTATE_SPEED, true);
        delay(SERVO_ROTATE_DELAY);
        hold();
      } else if (status::turnState == status::counterClockWise) {
        servoRotate.write(SERVO_ROTATE_TO_CW_HOLD_DEGREE, SERVO_ROTATE_SPEED, true);
        delay(SERVO_ROTATE_DELAY * 2);
        release();
        servoRotate.write(SERVO_ROTATE_CW_DEGREE, SERVO_ROTATE_SPEED, true);
        delay(SERVO_ROTATE_DELAY);
        hold();
      } else {
        servoRotate.write(SERVO_ROTATE_CW_DEGREE, SERVO_ROTATE_SPEED, true);
        delay(SERVO_ROTATE_DELAY);
      }
    }
    status::turnState = status::clockWise;
  }

  void rotateToCCW() {
    if (status::holdState == status::released) {
      servoRotate.write(SERVO_ROTATE_CCW_DEGREE, SERVO_ROTATE_SPEED, true);
      if (status::turnState == status::clockWise)
        delay(SERVO_ROTATE_DELAY);
      delay(SERVO_ROTATE_DELAY);
    } else {
      if (status::turnState == status::central) {
        servoRotate.write(SERVO_ROTATE_TO_CCW_HOLD_DEGREE, SERVO_ROTATE_SPEED, true);
        delay(SERVO_ROTATE_DELAY);
        release();
        servoRotate.write(SERVO_ROTATE_TO_CCW_HOLD2_DEGREE, SERVO_ROTATE_SPEED, true);
        delay(SERVO_ROTATE_DELAY);
        hold();
        servoRotate.write(SERVO_ROTATE_TO_CCW_HOLD3_DEGREE, SERVO_ROTATE_SPEED, true);
        delay(SERVO_ROTATE_DELAY);
        release();
        servoRotate.write(SERVO_ROTATE_CCW_DEGREE, SERVO_ROTATE_SPEED, true);
        delay(SERVO_ROTATE_DELAY);
        hold();
      } else if (status::turnState == status::clockWise) {
        servoRotate.write(SERVO_ROTATE_TO_CCW_HOLD_DEGREE, SERVO_ROTATE_SPEED, true);
        delay(SERVO_ROTATE_DELAY * 2);
        release();
        servoRotate.write(SERVO_ROTATE_TO_CCW_HOLD2_DEGREE, SERVO_ROTATE_SPEED, true);
        delay(SERVO_ROTATE_DELAY);
        hold();
        servoRotate.write(SERVO_ROTATE_TO_CCW_HOLD3_DEGREE, SERVO_ROTATE_SPEED, true);
        delay(SERVO_ROTATE_DELAY);
        release();
        servoRotate.write(SERVO_ROTATE_CCW_DEGREE, SERVO_ROTATE_SPEED, true);
        delay(SERVO_ROTATE_DELAY);
        hold();
      }      
      else {
        servoRotate.write(SERVO_ROTATE_CCW_DEGREE, SERVO_ROTATE_SPEED, true);
        delay(SERVO_ROTATE_DELAY);
      }
    }
    status::turnState = status::counterClockWise;
  }
}
