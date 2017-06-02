#include "Gui.h"

Gui::Gui() {
  lcd.init();
  lcd.clear();
  lcd.backlight();
  Serial.println("Gui Construktor");
}

Gui::~Gui() {
  Serial.println("Gui destruktor");
}

void Gui::guiprint(int col, int row, String text) {
  lcd.setCursor(col,row);
  lcd.print(text);
}

TimeSystem* Gui::getTimeSystem() {
  return this->timeSystem;
}
