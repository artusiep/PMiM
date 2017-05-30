#include "Gui.h"

Gui::Gui() {
  lcd.init();
  lcd.clear();
  lcd.backlight();
  mainMenu = MainMenu(lcd);
  mainMenu.refreshScreen();
  Serial.println("Gui Construktor");
}

Gui::~Gui() {}

void Gui::print(int col, int row, String text) {
  lcd.setCursor(col,row);
  lcd.print(text);
}

/**MainMenu Gui::getMainMenu() {
  return m_mainMenu;
}*/
