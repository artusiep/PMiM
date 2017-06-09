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

void Gui::guiprint(int8_t col, int8_t row, String text) {
  lcd.setCursor(col,row);
  lcd.print(text);
}

void Gui::guiBlink(int8_t col, int8_t row) {
  lcd.setCursor(col,row);
  lcd.blink();
}

TimeSystem* Gui::getTimeSystem() {
  return this->timeSystem;
}
