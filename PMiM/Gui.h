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
    void guiprint(int8_t col, int8_t row, String text);
    void guiBlink(int8_t col, int8_t row);
    TimeSystem* getTimeSystem();
    virtual int8_t getMenuID() = 0;
    virtual void increase() = 0;
    virtual void decrease() = 0;
    virtual int8_t accept() = 0;
    virtual int8_t undo() = 0;
    virtual void refreshScreen() = 0;
};

#endif
