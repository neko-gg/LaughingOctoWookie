#ifndef CUBELOW_H
#define CUBELOW_H

#include <Arduino.h> // byte

namespace cube {
  void moveEdgeToBufferTargetSwap(int edge);
  void removeEdgeFromBufferTargetSwap(int edge);
  void moveEdgeToBufferTargetFlip(int edge);
  void removeEdgeFromBufferTargetFlip(int edge);
  void moveCornerToBufferTarget(int corner);
  void removeCornerFromBufferTarget(int corner);
  void rotateFace(int face, bool cw);
  void rotateCube(int axis, bool cw);
  int getEdgeFromColors(int c1, int c2);
  int getMatchingEdge(int edge);
  int getCornerFromColors(int c1, int c2, int c3);
  int getMatchingCornerCW(int corner);
  int getMatchingCornerCCW(int corner);
  void deleteFromArray(int *array, int &n, int elem);
  int indexOfInArray(int *array, int n, int elem);
  void replaceInArray(int *array, int n, int from, int to);
}

#endif
