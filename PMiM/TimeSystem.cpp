#include "TimeSystem.h"



#define MAX_SIZE 20

TimeSystem::TimeSystem() {}

String TimeSystem::getWholeDate() {
  return( String(day()) + ":" +
           String(month()) + ":" +
           String(year()) + " " +
           getTime());
}

String TimeSystem::getTime() {
  return( String(hour()) + ":" +
          String(minute()) + ":" +
          String(second()));
}
