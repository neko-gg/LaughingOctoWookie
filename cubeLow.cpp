#include "cubeLow.h"
#include "mech.h"
#include <Arduino.h> // Serial

namespace cube {
  void moveEdgeToBufferTargetSwap(int edge) {
    switch (edge) {
      case 1:
      break; // 1 is where the magic happens
      case 3:
      rotateFace(1,  true);
      rotateFace(0, false);
      rotateFace(1, false);
      rotateFace(0,  true);
      break;
      case 5:
      rotateFace(3, false);
      rotateFace(0,  true);
      rotateFace(3,  true);
      rotateFace(0, false);
      break;
      case 7:
      break; // Special case: handle with care!
      case 10:
      rotateFace(4,  true);
      rotateFace(1, false);
      rotateFace(4, false);
      break;
      case 12:
      rotateFace(1, false);
      rotateFace(4,  true);
      rotateFace(1,  true);
      rotateFace(4, false);
      break;
      case 14:
      rotateFace(4,  true);
      rotateFace(1,  true);
      rotateFace(1,  true);
      rotateFace(4, false);
      break;
      case 16:
      rotateFace(4,  true);
      rotateFace(1,  true);
      rotateFace(4, false);
      break;
      case 21:
      rotateFace(0, false);
      rotateFace(1, false);
      rotateFace(0,  true);
      break;
      case 23:
      rotateFace(0,  true);
      rotateFace(3,  true);
      rotateFace(0, false);
      break;
      case 28:
      rotateFace(4, false);
      rotateFace(3,  true);
      rotateFace(4,  true);
      break;
      case 30:
      rotateFace(4, false);
      rotateFace(3,  true);
      rotateFace(3,  true);
      rotateFace(4,  true);
      break;
      case 32:
      rotateFace(3,  true);
      rotateFace(4, false);
      rotateFace(3, false);
      rotateFace(4,  true);
      break;
      case 34:
      rotateFace(4, false);
      rotateFace(3, false);
      rotateFace(4,  true);
      break;
      case 37:
      rotateFace(4, false);
      rotateFace(3,  true);
      rotateFace(3,  true);
      rotateFace(4,  true);
      rotateFace(0,  true);
      rotateFace(3,  true);
      rotateFace(0, false);
      break;
      case 39:
      rotateFace(0,  true);
      rotateFace(3, false);
      rotateFace(0, false);
      break;
      case 41:
      rotateFace(0, false);
      rotateFace(1,  true);
      rotateFace(0,  true);
      break;
      case 48:
      rotateFace(0, false);
      rotateFace(1,  true);
      rotateFace(1,  true);
      rotateFace(0,  true);
      break;
      case 50:
      rotateFace(0,  true);
      rotateFace(3,  true);
      rotateFace(3,  true);
      rotateFace(0, false);
      case 52:
      break; // Special case: handle with care!
      default:
      // TODO: ERROR - trying to swap an unswappable piece (not an edge, the buffer...)
      break;
    }
  }

  void removeEdgeFromBufferTargetSwap(int edge) {
    switch (edge) {
      case 1:
      break; // 1 is where the magic happens
      case 3:
      rotateFace(0, false);
      rotateFace(1,  true);
      rotateFace(0,  true);
      rotateFace(1, false);
      break;
      case 5:
      rotateFace(0,  true);
      rotateFace(3, false);
      rotateFace(0, false);
      rotateFace(3,  true);
      break;
      case 7:
      break; // Special case: handle with care!
      case 10:
      rotateFace(4,  true);
      rotateFace(1,  true);
      rotateFace(4, false);
      break;
      case 12:
      rotateFace(4,  true);
      rotateFace(1, false);
      rotateFace(4, false);
      rotateFace(1,  true);
      break;
      case 14:
      rotateFace(4,  true);
      rotateFace(1, false);
      rotateFace(1, false);
      rotateFace(4, false);
      break;
      case 16:
      rotateFace(4,  true);
      rotateFace(1, false);
      rotateFace(4, false);
      break;
      case 21:
      rotateFace(0, false);
      rotateFace(1,  true);
      rotateFace(0,  true);
      break;
      case 23:
      rotateFace(0,  true);
      rotateFace(3, false);
      rotateFace(0, false);
      break;
      case 28:
      rotateFace(4, false);
      rotateFace(3, false);
      rotateFace(4,  true);
      break;
      case 30:
      rotateFace(4, false);
      rotateFace(3, false);
      rotateFace(3, false);
      rotateFace(4,  true);
      break;
      case 32:
      rotateFace(4, false);
      rotateFace(3,  true);
      rotateFace(4,  true);
      rotateFace(3, false);
      break;
      case 34:
      rotateFace(4, false);
      rotateFace(3,  true);
      rotateFace(4,  true);
      break;
      case 37:
      rotateFace(0,  true);
      rotateFace(3, false);
      rotateFace(0, false);
      rotateFace(4, false);
      rotateFace(3, false);
      rotateFace(3, false);
      rotateFace(4,  true);
      break;
      case 39:
      rotateFace(0,  true);
      rotateFace(3,  true);
      rotateFace(0, false);
      break;
      case 41:
      rotateFace(0, false);
      rotateFace(1, false);
      rotateFace(0,  true);
      break;
      case 48:
      rotateFace(0, false);
      rotateFace(1, false);
      rotateFace(1, false);
      rotateFace(0,  true);
      break;
      case 50:
      rotateFace(0,  true);
      rotateFace(3, false);
      rotateFace(3, false);
      rotateFace(0, false);
      case 52:
      break; // Special case: handle with care!
      default:
      // TODO: ERROR - trying to unswap an unswappable piece (not an edge, the buffer...)
      break;
    }
  }

  void moveEdgeToBufferTargetFlip(int edge) {
    switch (edge) {
      case  1:
      case 37:
      rotateFace(4,  true);
      rotateFace(4,  true);
      break;
      case  3:
      case 10:
      rotateFace(0,  true);
      rotateFace(4,  true);
      rotateFace(4,  true);
      break;
      case  5:
      case 28:
      rotateFace(0, false);
      rotateFace(4,  true);
      rotateFace(4,  true);
      break;
      case  7:
      case 19:
      rotateFace(0,  true);
      rotateFace(0,  true);
      rotateFace(4,  true);
      rotateFace(4,  true);
      break;
      case 14:
      case 21:
      rotateFace(1,  true);
      rotateFace(1,  true);
      rotateFace(4,  true);
      break;
      case 23:
      case 30:
      rotateFace(3,  true);
      rotateFace(3,  true);
      rotateFace(4, false);
      break;
      case 32:
      case 39:
      rotateFace(4, false);
      break;
      case 12:
      case 41:
      rotateFace(4,  true);
      break;
      case 34:
      case 50:
      rotateFace(3, false);
      rotateFace(4, false);
      break;
      case 43:
      case 52:
      break; // 43 and 52 are where the magic happens
      case 16:
      case 48:
      rotateFace(1,  true);
      rotateFace(4,  true);
      break;
      default:
      // TODO: ERROR - trying to flip an unflippable piece (not an edge, the buffer...)
      break;
    }
  }

  void removeEdgeFromBufferTargetFlip(int edge) {
    switch (edge) {
      case  1:
      case 37:
      rotateFace(4, false);
      rotateFace(4, false);
      break;
      case  3:
      case 10:
      rotateFace(4, false);
      rotateFace(4, false);
      rotateFace(0, false);
      break;
      case  5:
      case 28:
      rotateFace(4, false);
      rotateFace(4, false);
      rotateFace(0,  true);
      break;
      case  7:
      case 19:
      rotateFace(4, false);
      rotateFace(4, false);
      rotateFace(0, false);
      rotateFace(0, false);
      break;
      case 14:
      case 21:
      rotateFace(4, false);
      rotateFace(1, false);
      rotateFace(1, false);
      break;
      case 23:
      case 30:
      rotateFace(4,  true);
      rotateFace(3, false);
      rotateFace(3, false);
      break;
      case 32:
      case 39:
      rotateFace(4,  true);
      break;
      case 12:
      case 41:
      rotateFace(4, false);
      break;
      case 34:
      case 50:
      rotateFace(4,  true);
      rotateFace(3,  true);
      break;
      case 43:
      case 52:
      break; // 43 and 52 are where the magic happens
      case 16:
      case 48:
      rotateFace(4, false);
      rotateFace(1, false);
      break;
      default:
      // TODO: ERROR - trying to unflip an unflippable piece (not an edge, the buffer...)
      break;
    }
  }

  void moveCornerToBufferTarget(int corner) {
    switch (corner) {
      case  2:
      rotateFace(3,  true);
      rotateFace(5, false);
      break;
      case  6:
      rotateFace(2,  true);
      rotateFace(3, false);
      break;
      case  8:
      rotateFace(2,  true);    
      break;
      case 11:
      rotateFace(2,  true);
      rotateFace(2,  true);
      break;
      case 15:
      rotateFace(5,  true);
      rotateFace(5,  true);
      break;
      case 17:
      rotateFace(2,  true);
      rotateFace(2,  true);
      rotateFace(3, false);
      break;
      case 18:
      rotateFace(2, false);
      rotateFace(5,  true);
      break;
      case 20:
      rotateFace(2,  true);
      rotateFace(2,  true);
      rotateFace(5,  true);
      break;
      case 24:
      rotateFace(5,  true);
      break;
      case 26:
      rotateFace(3,  true);
      rotateFace(2,  true);
      break;
      case 27:
      rotateFace(3, false);
      break;
      case 29:
      rotateFace(3,  true);
      rotateFace(3,  true);
      break;
      case 33:
      break; // 33 is where the magic happens
      case 35:
      rotateFace(3,  true);
      break;
      case 36:
      rotateFace(3, false);
      rotateFace(2,  true);
      break;
      case 42:
      rotateFace(5, false);
      break;
      case 44:
      rotateFace(5, false);
      rotateFace(3,  true);
      break;
      case 45:
      rotateFace(2, false);
      break;
      case 47:
      rotateFace(2, false);
      rotateFace(3, false);
      break;
      case 51:
      rotateFace(5,  true);
      rotateFace(2, false);
      break;
      case 53:
      rotateFace(3,  true);
      rotateFace(3,  true);
      rotateFace(2,  true);
      break;
      default:
      // TODO: ERROR - trying to swap an unswappable piece (not a corner, the buffer...)
      break;
    }
  }

  void removeCornerFromBufferTarget(int corner) {
    switch (corner) {
      case  2:
      rotateFace(5,  true);
      rotateFace(3, false);
      break;
      case  6:
      rotateFace(3,  true);
      rotateFace(2, false);
      break;
      case  8:
      rotateFace(2, false);    
      break;
      case 11:
      rotateFace(2, false);
      rotateFace(2, false);
      break;
      case 15:
      rotateFace(5, false);
      rotateFace(5, false);
      break;
      case 17:
      rotateFace(3,  true);
      rotateFace(2, false);
      rotateFace(2, false);
      break;
      case 18:
      rotateFace(5, false);
      rotateFace(2,  true);
      break;
      case 20:
      rotateFace(5, false);
      rotateFace(2, false);
      rotateFace(2, false);
      break;
      case 24:
      rotateFace(5, false);
      break;
      case 26:
      rotateFace(2, false);
      rotateFace(3, false);
      break;
      case 27:
      rotateFace(3,  true);
      break;
      case 29:
      rotateFace(3, false);
      rotateFace(3, false);
      break;
      case 33:
      break; // 33 is where the magic happens
      case 35:
      rotateFace(3, false);
      break;
      case 36:
      rotateFace(2, false);
      rotateFace(3,  true);
      break;
      case 42:
      rotateFace(5,  true);
      break;
      case 44:
      rotateFace(3, false);
      rotateFace(5,  true);
      break;
      case 45:
      rotateFace(2,  true);
      break;
      case 47:
      rotateFace(3,  true);
      rotateFace(2,  true);
      break;
      case 51:
      rotateFace(2,  true);
      rotateFace(5, false);
      break;
      case 53:
      rotateFace(2, false);
      rotateFace(3, false);
      rotateFace(3, false);
      break;
      default:
      // TODO: ERROR - trying to unswap an unswappable piece (not a corner, the buffer...)
      break;
    }
  }

  void rotateFace(int face, bool cw) {
    //  0 UP
    //  1 LEFT
    //  2 FRONT
    //  3 RIGHT
    //  4 BACK
    //  5 DOWN
    // 10 MIDDLE
    // 20 STANDING
    // 50 EQUATOR
    switch (face) {
      case 0:
      if(cw) {
        Serial.print("U");
        mech::push();
        mech::push();
        mech::hold();
        mech::rotateToCW();
        mech::release();
        mech::rotateToC();
        mech::push();
        mech::rotateToCW();
        mech::push();
        mech::rotateToC();
        mech::push();
      } else {
        Serial.print("U'");
        mech::push();
        mech::push();
        mech::hold();
        mech::rotateToCCW();
        mech::release();
        mech::rotateToC();
        mech::push();
        mech::rotateToCCW();
        mech::push();
        mech::rotateToC();
        mech::push();
      }
      break;
      case 1:
      if(cw) {
        Serial.print("L");
        mech::rotateToCCW();
        mech::push();
        mech::hold();
        mech::rotateToC();
        mech::release();
        mech::rotateToCW();
        mech::push();
        mech::rotateToC();
        mech::push();
        mech::push();
        mech::push();
      } else {
        Serial.print("L'");
        mech::rotateToCCW();
        mech::push();
        mech::rotateToC();
        mech::hold();
        mech::rotateToCCW();
        mech::release();
        mech::rotateToCW();
        mech::push();
        mech::rotateToC();
        mech::push();
      }
      break;
      case 2:
      if(cw) {
        Serial.print("F");
        mech::push();
        mech::push();
        mech::push();
        mech::hold();
        mech::rotateToCW();
        mech::release();
        mech::rotateToC();
        mech::push();
        mech::rotateToCW();
        mech::push();
        mech::rotateToC();
      } else {
        Serial.print("F'");
        mech::push();
        mech::push();
        mech::push();
        mech::hold();
        mech::rotateToCCW();
        mech::release();
        mech::rotateToC();
        mech::push();
        mech::rotateToCCW();
        mech::push();
        mech::rotateToC();
      }
      break;
      case 3:
      if(cw) {
        Serial.print("R");
        mech::rotateToCW();
        mech::push();
        mech::rotateToC();
        mech::hold();
        mech::rotateToCW();
        mech::release();
        mech::rotateToCCW();
        mech::push();
        mech::rotateToC();
        mech::push();
      } else {
        Serial.print("R'");
        mech::rotateToCW();
        mech::push();
        mech::hold();
        mech::rotateToC();
        mech::release();
        mech::rotateToCCW();
        mech::push();
        mech::rotateToC();
        mech::push();
        mech::push();
        mech::push();
      }
      break;
      case 4:
      if(cw) {
        Serial.print("B");
        mech::push();
        mech::hold();
        mech::rotateToCW();
        mech::release();
        mech::rotateToC();
        mech::push();
        mech::push();
        mech::push();
        mech::rotateToCCW();
        mech::push();
        mech::rotateToC();
      } else {
        Serial.print("B'");
        mech::push();
        mech::hold();
        mech::rotateToCCW();
        mech::release();
        mech::rotateToC();
        mech::push();
        mech::push();
        mech::push();
        mech::rotateToCW();
        mech::push();
        mech::rotateToC();
      }
      break;
      case 5:
      if(cw) {
        Serial.print("D");
        mech::hold();
        mech::rotateToCW();
        mech::release();
        mech::rotateToC();
        mech::push();
        mech::rotateToCW();
        mech::push();
        mech::rotateToC();
        mech::push();
        mech::push();
        mech::push();
      } else {
        Serial.print("D'");
        mech::hold();
        mech::rotateToCCW();
        mech::release();
        mech::rotateToC();
        mech::push();
        mech::rotateToCCW();
        mech::push();
        mech::rotateToC();
        mech::push();
        mech::push();
        mech::push();
      }
      break;
      case 10:
      if(cw) {
        Serial.print("M");
        cube::rotateFace(1, false);
        cube::rotateFace(3,  true);
        cube::rotateCube(1,  true);
      } else {
        Serial.print("M'");
        cube::rotateFace(1,  true);
        cube::rotateFace(3, false);
        cube::rotateCube(1, false);
      }
      break;
      case 20:
      if(cw) {
        Serial.print("S");
      } else {
        Serial.print("S'");
      }
      break;
      case 50:
      if(cw) {
        Serial.print("E");
      } else {
        Serial.print("E'");
      }
      break;
      default:
      // TODO: ERROR - face not recognized
      break;      
    }
  }

  void rotateCube(int axis, bool cw) {
    switch (axis) {
      case 0:
      if(cw) {
        Serial.print("Y");
        mech::push();
        mech::rotateToCW();
        mech::push();
        mech::rotateToC();
        mech::push();
        mech::push();
        mech::push();
      } else {
        Serial.print("Y'");
        mech::push();
        mech::rotateToCCW();
        mech::push();
        mech::rotateToC();
        mech::push();
        mech::push();
        mech::push();
      }
      break;
      case 1:
      if(cw) {
        Serial.print("X'");
        mech::push();
        mech::push();
        mech::push();
      } else {
        Serial.print("X");
        mech::push();
      }
      break;
      case 2:
      if(cw) {
        Serial.print("Z");
        mech::rotateToCW();
        mech::push();
        mech::rotateToC();
      } else {
        Serial.print("Z'");
        mech::rotateToCCW();
        mech::push();
        mech::rotateToC();
      }
      break;
      default:
      // TODO: ERROR - axis not recognized
      break;
    }
  }

  int getEdgeFromColors(int c1, int c2) {
    switch (c1) {
      case 0:
      switch (c2) {
        case 1:
        return 3;
        case 2:
        return 7;
        case 3:
        return 5;
        case 4:
        return 1;
        default:
        return -1;
      } break;
      case 1:
      switch (c2) {
        case 0:
        return 10;
        case 2:
        return 14;
        case 5:
        return 16;
        case 4:
        return 12;
        default:
        return -1;
      } break;
      case 2:
      switch (c2) {
        case 0:
        return 19;
        case 1:
        return 21;
        case 3:
        return 23;
        case 5:
        return 25;
        default:
        return -1;
      } break;
      case 3:
      switch (c2) {
        case 0:
        return 28;
        case 2:
        return 30;
        case 4:
        return 32;
        case 5:
        return 34;
        default:
        return -1;
      } break;
      case 4:
      switch (c2) {
        case 0:
        return 37;
        case 3:
        return 39;
        case 1:
        return 41;
        case 5:
        return 43;
        default:
        return -1;
      } break;
      case 5:
      switch (c2) {
        case 2:
        return 46;
        case 1:
        return 48;
        case 3:
        return 50;
        case 4:
        return 52;
        default:
        return -1;
      } break;
      default:
      return -1;
    }
  }

  int getMatchingEdge(int edge) {
    switch (edge) {
      case 1:
      return 37;
      case 3:
      return 10;
      case 5:
      return 28;
      case 7:
      return 19;
      case 10:
      return 3;
      case 12:
      return 41;
      case 14:
      return 21;
      case 16:
      return 48;
      case 19:
      return 7;
      case 21:
      return 14;
      case 23:
      return 30;
      case 25:
      return 46;
      case 28:
      return 5;
      case 30:
      return 23;
      case 32:
      return 39;
      case 34:
      return 50;
      case 37:
      return 1;
      case 39:
      return 32;
      case 41:
      return 12;
      case 43:
      return 52;
      case 46:
      return 25;
      case 48:
      return 16;
      case 50:
      return 34;
      case 52:
      return 43;
      default:
      return -1;
    }
  }

  int getCornerFromColors(int c1, int c2, int c3) {
    switch (c1) {
      case 0:
      switch (c2) {
        case 1:
        switch (c3) {
          case 2:
          return 6;
          case 4:
          return 0;
          default:
          return -1;
        } break;
        case 2:
        switch (c3) {
          case 1:
          return 6;
          case 3:
          return 8;
          default:
          return -1;
        } break;
        case 3:
        switch (c3) {
          case 2:
          return 8;
          case 4:
          return 2;
          default:
          return -1;
        } break;
        case 4:
        switch (c3) {
          case 1:
          return 0;
          case 3:
          return 2;
          default:
          return -1;
        } break;
        default:
        return -1;
      } break;
      case 1:
      switch (c2) {
        case 0:
        switch (c3) {
          case 2:
          return 11;
          case 4:
          return 9;
          default:
          return -1;
        } break;
        case 2:
        switch (c3) {
          case 0:
          return 11;
          case 5:
          return 17;
          default:
          return -1;
        } break;
        case 4:
        switch (c3) {
          case 0:
          return 9;
          case 5:
          return 15;
          default:
          return -1;
        } break;
        case 5:
        switch (c3) {
          case 2:
          return 17;
          case 4:
          return 15;
          default:
          return -1;
        } break;
        default:
        return -1;
      } break;
      case 2:
      switch (c2) {
        case 0:
        switch (c3) {
          case 1:
          return 18;
          case 3:
          return 20;
          default:
          return -1;
        } break;
        case 1:
        switch (c3) {
          case 0:
          return 18;
          case 5:
          return 24;
          default:
          return -1;
        } break;
        case 3:
        switch (c3) {
          case 0:
          return 20;
          case 5:
          return 26;
          default:
          return -1;
        } break;
        case 5:
        switch (c3) {
          case 1:
          return 24;
          case 3:
          return 26;
          default:
          return -1;
        } break;
        default:
        return -1;
      } break;
      case 3:
      switch (c2) {
        case 0:
        switch (c3) {
          case 2:
          return 27;
          case 4:
          return 29;
          default:
          return -1;
        } break;
        case 2:
        switch (c3) {
          case 0:
          return 27;
          case 5:
          return 33;
          default:
          return -1;
        } break;
        case 4:
        switch (c3) {
          case 0:
          return 29;
          case 5:
          return 35;
          default:
          return -1;
        } break;
        case 5:
        switch (c3) {
          case 2:
          return 33;
          case 4:
          return 35;
          default:
          return -1;
        } break;
        default:
        return -1;
      } break;
      case 4:
      switch (c2) {
        case 0:
        switch (c3) {
          case 1:
          return 38;
          case 3:
          return 36;
          default:
          return -1;
        } break;
        case 1:
        switch (c3) {
          case 0:
          return 38;
          case 5:
          return 44;
          default:
          return -1;
        } break;
        case 3:
        switch (c3) {
          case 0:
          return 36;
          case 5:
          return 42;
          default:
          return -1;
        } break;
        case 5:
        switch (c3) {
          case 1:
          return 44;
          case 3:
          return 42;
          default:
          return -1;
        } break;
        default:
        return -1;
      } break;
      case 5:
      switch (c2) {
        case 1:
        switch (c3) {
          case 2:
          return 45;
          case 4:
          return 51;
          default:
          return -1;
        } break;
        case 2:
        switch (c3) {
          case 1:
          return 45;
          case 3:
          return 47;
          default:
          return -1;
        } break;
        case 3:
        switch (c3) {
          case 2:
          return 47;
          case 4:
          return 53;
          default:
          return -1;
        } break;
        case 4:
        switch (c3) {
          case 1:
          return 51;
          case 3:
          return 53;
          default:
          return -1;
        } break;
        default:
        return -1;
      } break;
      default:
      return -1;
    }
  }

  int getMatchingCornerCW(int corner) {
    switch (corner) {
      case 0:
      return 9;
      case 2:
      return 36;
      case 6:
      return 18;
      case 8:
      return 27;
      case 9:
      return 38;
      case 11:
      return 6;
      case 15:
      return 51;
      case 17:
      return 24;
      case 18:
      return 11;
      case 20:
      return 8;
      case 24:
      return 45;
      case 26:
      return 33;
      case 27:
      return 20;
      case 29:
      return 2;
      case 33:
      return 47;
      case 35:
      return 42;
      case 36:
      return 29;
      case 38:
      return 0;
      case 42:
      return 53;
      case 44:
      return 15;
      case 45:
      return 17;
      case 47:
      return 26;
      case 51:
      return 44;
      case 53:
      return 35;
      default:
      return -1;
    }
  }

  int getMatchingCornerCCW(int corner) {
    switch (corner) {
      case 0:
      return 38;
      case 2:
      return 29;
      case 6:
      return 11;
      case 8:
      return 20;
      case 9:
      return 0;
      case 11:
      return 18;
      case 15:
      return 44;
      case 17:
      return 45;
      case 18:
      return 6;
      case 20:
      return 27;
      case 24:
      return 17;
      case 26:
      return 47;
      case 27:
      return 8;
      case 29:
      return 36;
      case 33:
      return 26;
      case 35:
      return 53;
      case 36:
      return 2;
      case 38:
      return 9;
      case 42:
      return 35;
      case 44:
      return 51;
      case 45:
      return 24;
      case 47:
      return 33;
      case 51:
      return 15;
      case 53:
      return 42;
      default:
      return -1;
    }
  }

  void deleteFromArray(int *array, int &n, int elem) {
    int index = -1;
    for (int i = 0; i < n; ++i) {
      if(array[i] == elem) {
        index = i;
        break;
      }
    }
    if(index != -1) {
      for (int i = index; i < n - 1; ++i) {
        array[i] = array[i+1];
      }
      --n;
    }
  }

  int indexOfInArray(int *array, int n, int elem) {
    for (int i = 0; i < n; ++i)
      if(array[i] == elem)
        return i;
    return -1;
  }

  void replaceInArray(int *array, int n, int from, int to) {
    for (int i = 0; i < n; ++i)
      if(array[i] == from)
        array[i] = to;
  }
}
