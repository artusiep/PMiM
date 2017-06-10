#ifndef STATEMENU_H
#define STATEMENU_H

#if ARDUINO >= 100
    #include "Arduino.h"
#else
extern "C" {
    #include "WConstants.h"
}
#endif

#include "Gui.h"

class StateMenu : public Gui {
  private:
    int8_t numberOfMenu = 4;
    int8_t menuID = 1;
    int8_t currentMenu = 0;
  public:
    StateMenu();
    ~StateMenu();
    virtual void refreshScreen() override;
    virtual void increase() override;
    virtual void decrease() override;
    virtual int8_t accept() override;
    virtual int8_t undo() override;
    virtual int8_t getMenuID() override;
    void refreshScreenRekuperator();
    void refreshScreenWoda();
    void refreshScreenSerce();
    void refreshScreenZrodlo();
};

#endif
