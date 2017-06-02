#ifndef SYSTEMCONTROLLER_H
#define SYSTEMCONTROLLER_H

#if ARDUINO >= 100
    #include "Arduino.h"
#else
extern "C" {
    #include "WConstants.h"
}
#endif

#include "MainMenu.h"
#include "StateMenu.h"
#include <Button.h>
#include "TimeSystem.h"

class SystemController {
  private:
    Gui* view;
    Button buttons[4];
    TimeSystem m_timeSystem = TimeSystem::getInstance();
    String time;
  public:
    SystemController();
    ~SystemController();
    void loop();
};

#endif
