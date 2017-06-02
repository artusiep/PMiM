#ifndef GUI_H
#define GUI_H

#if ARDUINO >= 100
    #include "Arduino.h"
#else
extern "C" {
    #include "WConstants.h"
}
#endif

#include <LiquidCrystal_I2C.h>
#include "TimeSystem.h"

//enum MenuType { mainMenu, stateMenu, tempMenu, logMenu };

class Gui{
  private:
    LiquidCrystal_I2C lcd{0x27,16,2};
    TimeSystem* timeSystem;
  public:
    Gui();
    virtual ~Gui();
    //TimeSystem timeSystem;
    void guiprint(int col, int row, String text);
    TimeSystem* getTimeSystem();
    virtual void increase() = 0;
    virtual void decrease() = 0;
    virtual int accept() = 0;
    virtual int undo() = 0;
    virtual void refreshScreen() = 0;
};

#endif
