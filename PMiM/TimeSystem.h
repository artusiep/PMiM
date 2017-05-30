#ifndef TIMESYSTEM_H
#define TIMESYSTEM_H

#if ARDUINO >= 100
    #include "Arduino.h"
#else
extern "C" {
    #include "WConstants.h"
}
#endif

#include <Time.h>

class TimeSystem {
  private:
  public:
    TimeSystem();
    String getWholeDate();
    String getTime();
};

#endif
