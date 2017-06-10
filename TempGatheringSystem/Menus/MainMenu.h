#ifndef MAINMENU_H
#define MAINMENU_H

#if ARDUINO >= 100
    #include "Arduino.h"
#else
extern "C" {
    #include "WConstants.h"
}
#endif

#include "Gui.h"


class MainMenu : public Gui {
  private:
    int8_t menuID = 0;
    int8_t numberOfMenu = 3;
    int8_t currentMenu = 0;
    void refreshTopLine();
    void refreshBottomLine();
  public:
    MainMenu();
    ~MainMenu();
    virtual int8_t getMenuID() override;
    virtual void refreshScreen() override;
    virtual void increase() override;
    virtual void decrease() override;
    virtual int8_t accept() override;
    virtual int8_t undo() override;
};

#endif
