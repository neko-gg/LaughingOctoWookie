#include "cubeHigh.h"
#include "cubeLow.h"

namespace cube {
  void parse(int *cubeArray) {
    replaceInArray(cubeArray, 54, cubeArray[ 4], 0);
    replaceInArray(cubeArray, 54, cubeArray[13], 1);
    replaceInArray(cubeArray, 54, cubeArray[22], 2);
    replaceInArray(cubeArray, 54, cubeArray[31], 3);
    replaceInArray(cubeArray, 54, cubeArray[40], 4);
    replaceInArray(cubeArray, 54, cubeArray[49], 5);
  }
  
  void solveEdges(const int *cubeArray, int *edgesToSwap, int &nEdgesToSwap, int *edgesToFlip, int &nEdgesToFlip) {
    int edgesNotOK[11] = {1, 3, 5, 7, 12, 14, 30, 32, 48, 50, 52};
    int nEdgesNotOK = 11;
    nEdgesToSwap = 0;
    nEdgesToFlip = 0;
    
    int topEdge = 46;
    int lastEdge = getEdgeFromColors(cubeArray[topEdge], cubeArray[getMatchingEdge(topEdge)]);
    if(lastEdge != topEdge && lastEdge != getMatchingEdge(topEdge)) {
      if(lastEdge == 19 || lastEdge == 43) {
        edgesToFlip[nEdgesToFlip++] = lastEdge;
        lastEdge = getMatchingEdge(lastEdge);        
      }
      edgesToSwap[nEdgesToSwap++] = lastEdge;
      
      deleteFromArray(edgesNotOK, nEdgesNotOK, lastEdge);
      deleteFromArray(edgesNotOK, nEdgesNotOK, getMatchingEdge(lastEdge));
      
      while (lastEdge != topEdge && lastEdge != getMatchingEdge(topEdge)) {
        lastEdge = getEdgeFromColors(cubeArray[lastEdge], cubeArray[getMatchingEdge(lastEdge)]);
        if(lastEdge != topEdge && lastEdge != getMatchingEdge(topEdge)) {
          if (lastEdge == 19 || lastEdge == 43) {
            edgesToFlip[nEdgesToFlip++] = lastEdge;
            lastEdge = getMatchingEdge(lastEdge);        
          }
          edgesToSwap[nEdgesToSwap++] = lastEdge;
        }
        deleteFromArray(edgesNotOK, nEdgesNotOK, lastEdge);
        deleteFromArray(edgesNotOK, nEdgesNotOK, getMatchingEdge(lastEdge));
      }
    }
    
    while (nEdgesNotOK > 0) {
      topEdge = edgesNotOK[0];
      lastEdge = getEdgeFromColors(cubeArray[topEdge], cubeArray[getMatchingEdge(topEdge)]);
      deleteFromArray(edgesNotOK, nEdgesNotOK, lastEdge);
      deleteFromArray(edgesNotOK, nEdgesNotOK, getMatchingEdge(lastEdge));
        
      if(lastEdge != topEdge && lastEdge != getMatchingEdge(topEdge)) {
        edgesToSwap[nEdgesToSwap++] = topEdge;
        
        if(lastEdge == 19 || lastEdge == 43) {
          edgesToFlip[nEdgesToFlip++] = lastEdge;
          lastEdge = getMatchingEdge(lastEdge);        
        }
        edgesToSwap[nEdgesToSwap++] = lastEdge;
      
        deleteFromArray(edgesNotOK, nEdgesNotOK, lastEdge);
        deleteFromArray(edgesNotOK, nEdgesNotOK, getMatchingEdge(lastEdge));
        
        while (lastEdge != topEdge && lastEdge != getMatchingEdge(topEdge)) {
          lastEdge = getEdgeFromColors(cubeArray[lastEdge], cubeArray[getMatchingEdge(lastEdge)]);
          if(lastEdge == 19 || lastEdge == 43) {
            edgesToFlip[nEdgesToFlip++] = lastEdge;
            lastEdge = getMatchingEdge(lastEdge);            
          }
          edgesToSwap[nEdgesToSwap++] = lastEdge;    
          deleteFromArray(edgesNotOK, nEdgesNotOK, lastEdge);
          deleteFromArray(edgesNotOK, nEdgesNotOK, getMatchingEdge(lastEdge));
        }
      } else {
        if(lastEdge != topEdge) {
          edgesToFlip[nEdgesToFlip++] = topEdge;
        }
      }
    }
  }
  
  void solveCorners(const int *cubeArray, int *cornersToSwap, int &nCornersToSwap) {
    int cornersNotOK[7] = {2, 6, 8, 45, 47, 51, 53};
    int nCornersNotOK = 7;
    nCornersToSwap = 0;
    
    int topCorner = 0;
    int lastCorner = getCornerFromColors(cubeArray[topCorner], cubeArray[getMatchingCornerCW(topCorner)], cubeArray[getMatchingCornerCCW(topCorner)]);
    if(lastCorner != topCorner && lastCorner != getMatchingCornerCW(topCorner) && lastCorner != getMatchingCornerCCW(topCorner)) {
      cornersToSwap[nCornersToSwap++] = lastCorner;
      
      deleteFromArray(cornersNotOK, nCornersNotOK, lastCorner);
      deleteFromArray(cornersNotOK, nCornersNotOK, getMatchingCornerCW(lastCorner));
      deleteFromArray(cornersNotOK, nCornersNotOK, getMatchingCornerCCW(lastCorner));
      
      while (lastCorner != topCorner && lastCorner != getMatchingCornerCW(topCorner) && lastCorner != getMatchingCornerCCW(topCorner)) {
        lastCorner = getCornerFromColors(cubeArray[lastCorner], cubeArray[getMatchingCornerCW(lastCorner)], cubeArray[getMatchingCornerCCW(lastCorner)]);
        if(lastCorner != topCorner && lastCorner != getMatchingCornerCW(topCorner) && lastCorner != getMatchingCornerCCW(topCorner))
          cornersToSwap[nCornersToSwap++] = lastCorner;
        deleteFromArray(cornersNotOK, nCornersNotOK, lastCorner);
        deleteFromArray(cornersNotOK, nCornersNotOK, getMatchingCornerCW(lastCorner));
        deleteFromArray(cornersNotOK, nCornersNotOK, getMatchingCornerCCW(lastCorner));
      }
    }
    
    while (nCornersNotOK > 0) {
      topCorner = cornersNotOK[0];
      lastCorner = getCornerFromColors(cubeArray[topCorner], cubeArray[getMatchingCornerCW(topCorner)], cubeArray[getMatchingCornerCCW(topCorner)]);
      deleteFromArray(cornersNotOK, nCornersNotOK, lastCorner);
      deleteFromArray(cornersNotOK, nCornersNotOK, getMatchingCornerCW(lastCorner));
      deleteFromArray(cornersNotOK, nCornersNotOK, getMatchingCornerCCW(lastCorner));
        
      if(lastCorner != topCorner && lastCorner != getMatchingCornerCW(topCorner) && lastCorner != getMatchingCornerCCW(topCorner)) {
        cornersToSwap[nCornersToSwap++] = topCorner;
        cornersToSwap[nCornersToSwap++] = lastCorner;
      
        deleteFromArray(cornersNotOK, nCornersNotOK, lastCorner);
        deleteFromArray(cornersNotOK, nCornersNotOK, getMatchingCornerCW(lastCorner));
        deleteFromArray(cornersNotOK, nCornersNotOK, getMatchingCornerCCW(lastCorner));
      
        while (lastCorner != topCorner && lastCorner != getMatchingCornerCW(topCorner) && lastCorner != getMatchingCornerCCW(topCorner)) {
          lastCorner = getCornerFromColors(cubeArray[lastCorner], cubeArray[getMatchingCornerCW(lastCorner)], cubeArray[getMatchingCornerCCW(lastCorner)]);
          cornersToSwap[nCornersToSwap++] = lastCorner;
          deleteFromArray(cornersNotOK, nCornersNotOK, lastCorner);
          deleteFromArray(cornersNotOK, nCornersNotOK, getMatchingCornerCW(lastCorner));
          deleteFromArray(cornersNotOK, nCornersNotOK, getMatchingCornerCCW(lastCorner));
        }
      } else {
        if(lastCorner != topCorner) {
          cornersToSwap[nCornersToSwap++] = topCorner;
          cornersToSwap[nCornersToSwap++] = lastCorner;         
        }
      }
    }
  }
  
  void swapEdges(const int *edgesToSwap, int nEdgesToSwap) {
    for (int i = 0; i < nEdgesToSwap; ++i) {
      if((edgesToSwap[i] == 7 && i  % 2 == 0) || (edgesToSwap[i] == 52 && i % 2 != 0)) {
        rotateFace( 0,  true);
        rotateFace( 0,  true);
        rotateFace(10, false);
        rotateFace( 0,  true);
        rotateFace( 0,  true);
        rotateFace(10, false);
      } else if((edgesToSwap[i] == 7 && i % 2 != 0) || (edgesToSwap[i] == 52 && i % 2 == 0)) {
        rotateFace(10, true);
        rotateFace( 0, true);
        rotateFace( 0, true);
        rotateFace(10, true);
        rotateFace( 0, true);
        rotateFace( 0, true);
      } else {
        // M2
        moveEdgeToBufferTargetSwap(edgesToSwap[i]);
        rotateFace(10, true);
        rotateFace(10, true);
        removeEdgeFromBufferTargetSwap(edgesToSwap[i]);
      }
    }
  }
  
  void fixParity(int *edgesToFlip, int nEdgesToFlip) {
    bool UB = indexOfInArray(edgesToFlip, nEdgesToFlip, 1) >= 0 || indexOfInArray(edgesToFlip, nEdgesToFlip, 37) >= 0;
    bool UL = indexOfInArray(edgesToFlip, nEdgesToFlip, 3) >= 0 || indexOfInArray(edgesToFlip, nEdgesToFlip, 10) >= 0;
    
    if (UB && !UL) {
      replaceInArray(edgesToFlip, nEdgesToFlip, 1, 3);
      replaceInArray(edgesToFlip, nEdgesToFlip, 37, 10);
    } else if (UL && !UB) {
      replaceInArray(edgesToFlip, nEdgesToFlip, 3, 1);
      replaceInArray(edgesToFlip, nEdgesToFlip, 10, 37);
    }
    
    // D' L2 D M2 D' L2 D
    rotateFace( 5, false);
    rotateFace( 1,  true);
    rotateFace( 1,  true);
    rotateFace( 5,  true);
    rotateFace(10,  true);
    rotateFace(10,  true);
    rotateFace( 5, false);
    rotateFace( 1,  true);
    rotateFace( 1,  true);
    rotateFace( 5,  true);    
  }
  
  void flipEdges(const int *edgesToFlip, int nEdgesToFlip) {
    // M D' M D' M D2 M' D' M' D' M' D2
    for (int i = 0; i < nEdgesToFlip; ++i) {
      moveEdgeToBufferTargetFlip(edgesToFlip[i]);
      rotateFace(10,  true);
      rotateFace( 5, false);
      rotateFace(10,  true);
      rotateFace( 5, false);
      rotateFace(10,  true);
      rotateFace( 5, false);
      rotateFace( 5, false);
      rotateFace(10, false);
      rotateFace( 5, false);
      rotateFace(10, false);
      rotateFace( 5, false);
      rotateFace(10, false);
      rotateFace( 5, false);
      rotateFace( 5, false);
      removeEdgeFromBufferTargetFlip(edgesToFlip[i]);
    }
  }  

  void swapCorners(const int *cornersToSwap, int nCornersToSwap) {
    // (y perm)
    // R U' R' U' R U R' F' R U R' U' R' F R
    for (int i = 0; i < nCornersToSwap; ++i) {
      moveCornerToBufferTarget(cornersToSwap[i]);      
      rotateFace(3,  true);
      rotateFace(0, false);
      rotateFace(3, false);
      rotateFace(0, false);
      rotateFace(3,  true);
      rotateFace(0,  true);
      rotateFace(3, false);
      rotateFace(2, false);
      rotateFace(3,  true);
      rotateFace(0,  true);
      rotateFace(3, false);
      rotateFace(0, false);
      rotateFace(3, false);
      rotateFace(2,  true);
      rotateFace(3,  true);
      removeCornerFromBufferTarget(cornersToSwap[i]);
    }
  }
}
