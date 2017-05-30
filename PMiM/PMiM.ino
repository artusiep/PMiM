#include <Arduino.h>
#include <Wire.h>
#include"TimeSystem.h"
#include "Gui.h"


//----------------------------------

/*
class MenuStanu {
  private:
    int m_iloscMenu = 4;
    int m_currentMenu;
    bool warunki[4];
    LiquidCrystal_I2C m_screen;
  public:
    MenuStanu(LiquidCrystal_I2C screen);
    ~MenuStanu();
    void odswierz();
    void increase();
    void decrease();
    int zaakceptuj();
    void odswierzRekuperator();
    void odswierzWoda();
    void odswierzSerce();
    void odswierzZrodlo();
};



void MenuStanu::odswierzRekuperator() {
  if(warunki[0]) {
      m_screen.setCursor(0,0);
      m_screen.println("   Rekuperator  ");
      m_screen.println("   [ON]  OFF    ");
  } else {
      m_screen.setCursor(0,0);
      m_screen.println("   Rekuperator  ");
      m_screen.println("    ON  [OFF]   ");
  }
}

void MenuStanu::odswierzWoda() {
  if(warunki[1]) {
      m_screen.setCursor(0,0);
      m_screen.println("      Woda      ");
      m_screen.println("   [ON]  OFF    ");
  } else {
      m_screen.setCursor(0,0);
      m_screen.println("      Woda      ");
      m_screen.println("    ON  [OFF]   ");
  }
}

void MenuStanu::odswierzSerce() {
  if(warunki[2]) {
      m_screen.setCursor(0,0);
      m_screen.println("   [Wymiennik]  ");
      m_screen.println("     Bypass     ");
  } else {
      m_screen.setCursor(0,0);
      m_screen.println("    Wymiennik   ");
      m_screen.println("    [Bypass]    ");
  }
}

void MenuStanu::odswierzZrodlo() {
  if(warunki[3]) {
      m_screen.setCursor(0,0);
      m_screen.println("     [Grunt]    ");
      m_screen.println("  [Z Zewnatrz]  ");
  } else {
      m_screen.setCursor(0,0);
      m_screen.println("     [Grunt]    ");
      m_screen.println("  [Z Zewnatrz]  ");
  }
}

MenuStanu::MenuStanu(LiquidCrystal_I2C screen) {
  m_currentMenu = 0;
  m_screen = screen;
}

MenuStanu::~MenuStanu() {}

void MenuStanu::odswierz() {
  switch(m_currentMenu) {
    case 0:
      odswierzRekuperator();
      break;
    case 1:
      odswierzWoda();
      break;
    case 2:
      odswierzSerce();
      break;
    case 3:
      odswierzZrodlo();
      break;
    default:
      m_screen.setCursor(0,0);
      m_screen.println("      Blad      ");
      m_screen.println("                ");
  }
}

void MenuStanu::decrease() {
  m_currentMenu = (m_currentMenu + 3) % 4;
}

void MenuStanu::increase() {
   m_currentMenu = (m_currentMenu + 1) % 4;
}

int MenuStanu::zaakceptuj() {
  return m_currentMenu;
  Serial.println("Enter");
}
*/

//--------------------------







// ----------------------------------------

Gui* p_interface;
TimeSystem time;

void setup() {
  Serial.begin(9600);
  if(Serial) {
    Serial.println("--- Uruchomienie Systemu (setup)---");
  }
  Gui interface(&time);
  p_interface = &interface;
}

void loop() {
  p_interface->loop();
}
