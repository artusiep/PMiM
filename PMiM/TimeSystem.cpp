#include "TimeSystem.h"



TimeSystem::TimeSystem() {
  Serial.println("Time System Construktor");
}

TimeSystem & TimeSystem::getInstance() {
  static TimeSystem singleton;
  return singleton;
}

String TimeSystem::getWholeDate() {
  return( conv(day()) + ":" +
           conv(month()) + ":" +
           conv(year()%100) + " " +
           getTime());
}

String TimeSystem::getTime() {
  return( conv(hour()) + ":" +
          conv(minute()));
}

String TimeSystem::conv(int timeUnit) {
  if (timeUnit / 10 == 0) {
    return "0" + String(timeUnit);
  }
  return String(timeUnit);
}

void TimeSystem::modify(int flag, bool increase) {
  int temp[5] = {0,0,0,0,0};
  int unit = 0;
  if(increase){
    unit = 1;
  } else {
    unit = -1;
  }
  temp[flag] = unit;
  setTime((24+hour()+temp[0])%24, (60+minute()+temp[1])%60, second(), day()+temp[2], (13+month()+temp[3])%13, year()+temp[4]);
}
