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
#include"MainMenu.h"

class Gui{
  private:

    //MenuStanu* stan;
    //WyswietlanieTemperatury temp;
    //KontrolaBledow bledy;
  public:
    LiquidCrystal_I2C lcd{0x27,16,2};
    Gui();
    ~Gui();
    MainMenu mainMenu{lcd};
    void print(int col, int row, String text);
};

#endif
