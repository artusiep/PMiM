#include "TimeMenu.h"

TimeMenu::TimeMenu( ) {
  refreshScreen();
}

TimeMenu::~TimeMenu() {}

void TimeMenu::refreshTopLine() {
      guiprint(0,0," Stan Temp Czas ");
  return;
}

void TimeMenu::refreshBottomLine() {
    switch (currentMenu) {
      case 0:
        guiprint(1,1,getTimeSystem()->getWholeDate());
        guiBlink(11,1);
        break;
      case 1:
        guiprint(1,1,getTimeSystem()->getWholeDate());
        guiBlink(14,1);
        break;
      case 2:
        guiprint(1,1,getTimeSystem()->getWholeDate());
        guiBlink(2,1);
        break;
      case 3:
        guiprint(1,1,getTimeSystem()->getWholeDate());
        guiBlink(5,1);
        break;
      case 4:
        guiprint(1,1,getTimeSystem()->getWholeDate());
        guiBlink(8,1);
        break;
    }
}

void TimeMenu::refreshScreen() {
  refreshTopLine();
  refreshBottomLine();
}

int8_t TimeMenu::getMenuID() {
  return menuID;
}

void TimeMenu::decrease() {
  if(modifyTimeElem) {
    Serial.println(currentMenu);
    getTimeSystem()->modify(currentMenu, false);
  } else {
    currentMenu = (currentMenu + numberOfMenu - 1) % numberOfMenu;
  }

  refreshScreen();
}

void TimeMenu::increase() {
  if(modifyTimeElem) {
    Serial.println(currentMenu);
    getTimeSystem()->modify(currentMenu, true);
  } else {
    currentMenu = (currentMenu + 1) % numberOfMenu;
  }
  refreshScreen();
}

int8_t TimeMenu::accept() {
  Serial.println("TimeMenu::acceept");
  Serial.println(modifyTimeElem);
  // if( modifyTimeElem ) {
  //   modifyTimeElem = false;
  //   return -1;
  // }
  modifyTimeElem = true;
  return currentMenu;
}

int8_t TimeMenu::undo() {
  Serial.println("TimeMenu::undo");
  Serial.println(modifyTimeElem);
  if( modifyTimeElem ) {
    modifyTimeElem = false;
    return -1;
  } else {
    return 0;
  }
}
