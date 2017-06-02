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

    int m_iloscMenu = 3;
    int m_currentMenu = 0;
    void refreshTopLine();
    void refreshBottomLine();
  public:
    MainMenu();
    ~MainMenu();
    virtual void refreshScreen() override;
    virtual void increase() override;
    virtual void decrease() override;
    virtual int accept() override;
    virtual int undo() override;
};

#endif
