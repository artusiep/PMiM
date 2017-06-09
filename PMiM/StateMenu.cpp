#include "StateMenu.h"

void StateMenu::refreshScreenRekuperator() {
    guiprint(0,0,"   Rekuperator  ");

}

void StateMenu::refreshScreenWoda() {
    guiprint(0,0,"      Woda      ");
}

void StateMenu::refreshScreenSerce() {
    guiprint(0,0,"    Wymiennik   ");

}

void StateMenu::refreshScreenZrodlo() {
    guiprint(0,0,"      Grunt     ");
}

StateMenu::StateMenu() {
  refreshScreen();
}

StateMenu::~StateMenu() {}

void StateMenu::refreshScreen() {
  switch(currentMenu) {
    case 0:
      refreshScreenRekuperator();
      break;
    case 1:
      refreshScreenWoda();
      break;
    case 2:
      refreshScreenSerce();
      break;
    case 3:
      refreshScreenZrodlo();
      break;

  }
}

void StateMenu::decrease() {
  currentMenu = (currentMenu + numberOfMenu - 1) % numberOfMenu;
  refreshScreen();
}

void StateMenu::increase() {
   currentMenu = (currentMenu + 1) % numberOfMenu;
   refreshScreen();
}

int8_t StateMenu::accept() {
  return currentMenu;
  refreshScreen();
}

int8_t StateMenu::undo() {
  return 0;
}

int8_t StateMenu::getMenuID() {
  return menuID;
}
