#ifndef SYSTEMCONTROLLER_H
#define SYSTEMCONTROLLER_H

#if ARDUINO >= 100
    #include "Arduino.h"
#else
extern "C" {
    #include "WConstants.h"
}
#endif

#include <Button.h>
#include "MainMenu.h"
#include "StateMenu.h"
#include "TimeSystem.h"
#include "TempSystem.h"

class SystemController {
  private:
    Gui* view;
    Button buttons[4];
    TimeSystem m_timeSystem = TimeSystem::getInstance();
    TempSystem m_tempSystem = TempSystem::getInstance();
    String time;
    uint8_t TempCounter;
  public:
    SystemController();
    ~SystemController();
    void loop();
};

#endif
