/*
 *            0  1  2
 *            3  4  5
 *            6  7  8
 *  9 10 11  18 19 20  27 28 29  36 37 38
 * 12 13 14  21 22 23  30 31 32  39 40 41
 * 15 16 17  24 25 26  33 34 35  42 43 44
 *           45 46 47
 *           48 49 50
 *           51 52 53
 */

#include "connections.h"
#include "cubeHigh.h"
#include "cubeLow.h"
#include "status.h"
#include "mech.h"
#include <ShiftRegLCD123.h>
#include <Bounce2.h>
#include <VarSpeedServo.h>
  
const char inputColors[6] = {'W', 'O', 'G', 'R', 'B', 'Y'};
const int lcdOffset = 2;

int inputFace    = 0;
int inputPiece   = 0;
int currentColor = 0;

int inputCube[54];
int inputPiecePos = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
    
  lcd.begin(16, 2);  
  lcd.backlightOn();  
  lcd.print("Hello Reddit! (:");
  
  // Setup the buttons with an internal pull-up:
  pinMode(BUT_NEXT, INPUT_PULLUP);
  pinMode(BUT_OK,   INPUT_PULLUP);
  pinMode(BUT_BACK, INPUT_PULLUP);
  // After setting up the buttons, setup the Bounce instances:
  butNext.attach(BUT_NEXT);
  butNext.interval(5); // interval in ms
  butOk.  attach(BUT_OK);
  butOk.  interval(5); // interval in ms
  butBack.attach(BUT_BACK);
  butBack.interval(5); // interval in ms

  servoPush.  attach(  SERVO_PUSH);
  servoRotate.attach(SERVO_ROTATE);
  
  mech::release();
  mech::rotateToC();
  status::logicState = status::ready; 
}

void loop() {
  // put your main code here, to run repeatedly:
  // unsigned long start = millis();

  butNext.update();
  butOk  .update();
  butBack.update();

  if (status::logicState == status::ready) {
    if (butOk.fell()) {
      lcd.clear();
      lcd.print("   FACCIA U:");
      lcd.setCursor(lcdOffset, 1);
      lcd.print(inputColors[0]);
      inputPiece    = 0;
      inputFace     = 0;
      currentColor  = 1;
      inputPiecePos = 0;
      status::logicState = status::input;
    }
  } else if (status::logicState == status::input) {
    if (butNext.fell()) {
      if (currentColor > 5)
        currentColor = 0;     
      lcd.setCursor(inputPiece + lcdOffset, 1);
      lcd.print(inputColors[currentColor++]);
    } if (butOk.fell()) {
      inputCube[inputPiecePos++] = currentColor + 5;
      ++inputPiece;
      if (inputPiece ==  3)
        ++inputPiece;
      if (inputPiece ==  7)
        ++inputPiece;
      if (inputPiece >= 11) {
        if (++inputFace > 5) {
          lcd.clear();
          lcd.print("  Premi OK per");
          lcd.setCursor(0, 1);
          lcd.print("  risolvere.  ");
          status::logicState = status::computing;
        }
        else {
          switch (inputFace) {
            case 1:
            lcd.clear();
            lcd.print("   FACCIA L:");
            break;
            case 2:
            lcd.clear();
            lcd.print("   FACCIA F:");
            break;
            case 3:
            lcd.clear();
            lcd.print("   FACCIA R:");
            break;
            case 4:
            lcd.clear();
            lcd.print("   FACCIA B:");
            break;
            case 5:
            lcd.clear();
            lcd.print("   FACCIA D:");
            break;
            default:
            return;
          }
          lcd.setCursor(lcdOffset, 1);
          lcd.print(inputColors[0]);
          inputPiece   = 0;
          currentColor = 1;
        }
      } else {
        lcd.setCursor(inputPiece + lcdOffset, 1);
        lcd.print(inputColors[0]);
        currentColor = 1;
      }
    }
  } else if (status::logicState == status::computing) {
    if (butOk.fell()) {
      lcd.clear();      
      solve(inputCube);
      lcd.print(" CUBO RISOLTO!! ");
      status::logicState = status::ready;
    }
  }
  
  if (butBack.fell() && status::logicState == status::ready) {
    // test y perm    
    cube::rotateFace(2,  true);
    cube::rotateFace(3,  true);
    cube::rotateFace(0, false);
    cube::rotateFace(3, false);
    cube::rotateFace(0, false);
    cube::rotateFace(3,  true);
    cube::rotateFace(0,  true);
    cube::rotateFace(3, false);
    cube::rotateFace(2, false);
    cube::rotateFace(3,  true);
    cube::rotateFace(0,  true);
    cube::rotateFace(3, false);
    cube::rotateFace(0, false);
    cube::rotateFace(3, false);
    cube::rotateFace(2,  true);
    cube::rotateFace(3,  true);
    cube::rotateFace(2, false);
  }
}

void solve(int myCube[54]) {
  // F2 D' L' D' U' L2 D U B' R D2 L2 R' D U' F2 D2 U F2 D2 L B' R U' R D' U' B' F L2
  /*int myCube[54] = {3, 5, 0, 3, 0, 0, 2, 3, 4,
                    2, 5, 1, 0, 1, 1, 2, 1, 5,
                    5, 2, 0, 5, 2, 0, 4, 0, 3,
                    3, 1, 4, 4, 3, 3, 4, 4, 3,
                    1, 2, 0, 4, 4, 3, 5, 5, 0,
                    1, 2, 5, 2, 5, 1, 1, 4, 2};*/
                    
  // F2 D' L' D' U' L2 D U B' R D2 L2 R' D U' F2 D2 U F2 D2 L B' R U' R D' U' B' F L2 D'                  
  /*int myCube[54] = {3, 5, 0, 3, 0, 0, 2, 3, 4,
                    2, 5, 1, 0, 1, 1, 4, 0, 3,
                    5, 2, 0, 5, 2, 0, 4, 4, 3,
                    3, 1, 4, 4, 3, 3, 5, 5, 0,
                    1, 2, 0, 4, 4, 3, 2, 1, 5,
                    5, 1, 2, 2, 5, 4, 1, 2, 1};*/
                    
  // L2 U' R2 B2 R2 D2 L2 U L2 B2 L' B D2 L' D2 R B' L' U'
  /*int myCube[54] = {2, 2, 3, 1, 0, 0, 1, 0, 5,
                    1, 4, 0, 1, 1, 3, 2, 4, 1,
                    4, 1, 4, 4, 2, 2, 5, 3, 2,
                    3, 2, 4, 5, 3, 3, 3, 5, 2,
                    0, 1, 0, 2, 4, 5, 0, 5, 1,
                    4, 0, 5, 0, 5, 3, 5, 4, 3};*/
 
  cube::parse(myCube);

  int  edgesToSwap[30];
  int nEdgesToSwap;
  int  edgesToFlip[11];
  int nEdgesToFlip;
  int  cornersToSwap[30];
  int nCornersToSwap;
  
  cube::solveEdges(myCube, edgesToSwap, nEdgesToSwap, edgesToFlip, nEdgesToFlip);
  cube::solveCorners(myCube, cornersToSwap, nCornersToSwap);

  if (nEdgesToSwap > 0)
    Serial.print("Edges swap sequence: ");
  for (int i = 0; i < nEdgesToSwap - 1; ++i) {
    Serial.print(edgesToSwap[i]);
    Serial.print(", ");
  }
  if (nEdgesToSwap > 0)
    Serial.println(edgesToSwap[nEdgesToSwap - 1]);
    
  if (nEdgesToSwap % 2 != 0)
    Serial.println("Parity fix needed.");
  
  if (nEdgesToFlip > 0)
    Serial.print("Edges to flip: ");
  for (int i = 0; i < nEdgesToFlip - 1; ++i) {
    Serial.print(edgesToFlip[i]);
    Serial.print(", ");
  }
  if (nEdgesToFlip > 0)
    Serial.println(edgesToFlip[nEdgesToFlip - 1]);
  
  if (nCornersToSwap > 0)
    Serial.print("Corners swap sequence: ");
  for (int i = 0; i < nCornersToSwap - 1; ++i) {
    Serial.print(cornersToSwap[i]);
    Serial.print(", ");
  }
  if (nCornersToSwap > 0)
    Serial.println(cornersToSwap[nCornersToSwap - 1]);
  
  Serial.println("Moves to fix edges, part 1:");
  cube::swapEdges(edgesToSwap, nEdgesToSwap);
  Serial.println("");
  
  if (nEdgesToSwap % 2 != 0) {
    Serial.println("Moves to fix parity:");
    cube::fixParity(edgesToFlip, nEdgesToFlip);
    Serial.println("");
  }
  
  Serial.println("Moves to fix edges, part 2:");
  cube::flipEdges(edgesToFlip, nEdgesToFlip);
  Serial.println("");
  
  Serial.println("Moves to fix corners:");
  cube::swapCorners(cornersToSwap, nCornersToSwap);
  Serial.println("");
}
