#include "MainMenu.h"
#if ARDUINO >= 100
    #include "Arduino.h"
#else
extern "C" {
    #include "WConstants.h"
}
#endif

//Tworze obiekt

MainMenu::MainMenu(LiquidCrystal_I2C lcd ) {
  m_currentMenu = 0;
  m_lcd  = lcd ;
}

MainMenu::~MainMenu() {}

void MainMenu::refreshTopLine() {
  m_lcd .setCursor(0,0);
  switch(m_currentMenu){
    case 0:
      m_lcd .print("[Stan]Temp Log  ");
      Serial.println("[Stan]Temp Log  ");
      break;
    case 1:
      m_lcd .print(" Stan[Temp]Log  ");
      Serial.println(" Stan[Temp]Log  ");
      break;
    case 2:
      m_lcd .print(" Stan Temp[Log] ");
      Serial.println(" Stan Temp Log  ");
      break;
  }
  return;
}

void MainMenu::refreshScreen() {
  refreshTopLine();
}

void MainMenu::decrease() {
  Serial.println("Left");
  m_currentMenu = (m_currentMenu + 2) % 3;
  refreshScreen();
}

void MainMenu::increase() {
  Serial.println("Right");
  m_currentMenu = (m_currentMenu + 1) % 3;
  refreshScreen();
}

int MainMenu::accept() {
  Serial.println("Enter");
  return m_currentMenu;
}
