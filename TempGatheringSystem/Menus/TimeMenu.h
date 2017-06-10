#ifndef TIMEMENU_H
#define TIMEMENU_H

#if ARDUINO >= 100
    #include "Arduino.h"
#else
extern "C" {
    #include "WConstants.h"
}
#endif

#include "Gui.h"

class TimeMenu : public Gui {
  private:
    int8_t numberOfMenu = 5;
    int8_t currentMenu = 0;
    int8_t menuID = 3;
    bool modifyTimeElem = false;
    void refreshTopLine();
    void refreshBottomLine();
  public:
    TimeMenu();
    ~TimeMenu();
    virtual void refreshScreen() override;
    virtual void increase() override;
    virtual void decrease() override;
    virtual int8_t getMenuID() override;
    virtual int8_t accept() override;
    virtual int8_t undo() override;
};

#endif
