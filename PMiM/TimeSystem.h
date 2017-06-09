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
    TimeSystem();
  public:
    static TimeSystem & getInstance();
    String getWholeDate();
    String getTime();
    String conv(int timeUnit);
    void modify(int flag, bool increase);
};

#endif
