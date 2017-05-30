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
#include <Button.h>
#include"MainMenu.h"
#include"TimeSystem.h"

class Gui{
  private:
    TimeSystem* m_timeSystem;
    Button m_enterButton{6};
    Button m_leftButton{7};
    Button m_rightButton{8};
    Button m_returnButton{9};
    MainMenu m_mainMenu{lcd};
    //MenuStanu* stan;
    //WyswietlanieTemperatury temp;
    //KontrolaBledow bledy;
  public:
    LiquidCrystal_I2C lcd{0x27,16,2};
    Gui(TimeSystem* timeSystem);
    ~Gui();
    void loop();
};

#endif
