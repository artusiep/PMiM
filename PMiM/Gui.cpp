#include "Gui.h"

Gui::Gui(TimeSystem* timeSystem) {
  m_timeSystem = timeSystem;
/*  m_enterButton = Button(6);
  m_leftButton = Button(7);
  m_rightButton = Button(8);
  m_returnButton = Button(9);*/
  lcd.init();
  lcd.clear();
  lcd.backlight();
  m_mainMenu = MainMenu(lcd);
  m_mainMenu.refreshScreen();
  Serial.println("Gui Construktor");
}

Gui::~Gui() {}

void Gui::loop() {
  m_leftButton.checkIfPushed();
  m_rightButton.checkIfPushed();
  m_enterButton.checkIfPushed();
  m_returnButton.checkIfPushed();
  if(m_leftButton.isPushed()) {
    m_mainMenu.decrease();
  }
  if(m_rightButton.isPushed()) {
    m_mainMenu.increase();
  }
  if(m_enterButton.isPushed()) {
    m_mainMenu.zaakceptuj();
  }
}
