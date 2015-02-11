#ifndef STATUS_H
#define STATUS_H

namespace status {
  enum logicalState {
    ready,
    input,
    computing,
    solving 
  };
  
  enum holderState {
    holding,
    released
  };
  
  enum turnerState {
    clockWise,
    counterClockWise,
    central
  };
  
  extern logicalState logicState;
  extern holderState   holdState;
  extern turnerState   turnState;
}

#endif
