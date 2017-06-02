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
    int m_iloscMenu = 4;
    int m_currentMenu = 0;
  public:
    StateMenu();
    ~StateMenu();
    virtual void refreshScreen() override;
    virtual void increase() override;
    virtual void decrease() override;
    virtual int accept() override;
    virtual int undo() override;
    void refreshScreenRekuperator();
    void refreshScreenWoda();
    void refreshScreenSerce();
    void refreshScreenZrodlo();
};

#endif
