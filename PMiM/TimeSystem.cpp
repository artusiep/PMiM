#include "TimeSystem.h"



TimeSystem::TimeSystem() {
  Serial.println("Time System Construktor");
}

static TimeSystem TimeSystem::getInstance() {
  return timeSystem;
}

String TimeSystem::getWholeDate() {
  return( String(day()) + ":" +
           String(month()) + ":" +
           String(year()) + " " +
           getTime());
}

String TimeSystem::getTime() {
  return( conv(hour()) + ":" +
          conv(minute()) + ":" +
          conv(second()));
}

String TimeSystem::conv(int timeUnit) {
  if (timeUnit / 10 == 0) {
    return "0" + String(timeUnit);
  }
  return String(timeUnit);
}

/*void TimeSystem::modify() {
  setTime(int hr,int min,int sec,int day, int month, int yr);
}*/
