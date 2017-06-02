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
    static TimeSystem timeSystem;
    TimeSystem();
  public:
    static TimeSystem getInstance();
    String getWholeDate();
    String getTime();
    String conv(int timeUnit);

};

#endif
