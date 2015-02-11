#ifndef CUBEHIGH_H
#define CUBEHIGH_H

#include <Arduino.h> // byte

namespace cube {
  void parse(int *cubeArray);
  void solveEdges(const int *cubeArray, int *edgesToSwap, int &nEdgesToSwap, int *edgesToFlip, int &nEdgesToFlip);
  void solveCorners(const int *cubeArray, int *cornersToSwap, int &nCornersToSwap);  
  void swapEdges(const int *edgesToSwap, int nEdgesToSwap);
  void fixParity(int *edgesToFlip, int nEdgesToFlip);
  void flipEdges(const int *edgesToFlip, int nEdgesToFlip);
  void swapCorners(const int *cornersToSwap, int nCornersToSwap);
}

#endif
