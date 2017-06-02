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
  int menuType = 1;
}

StateMenu::~StateMenu() {}

void StateMenu::refreshScreen() {
  switch(m_currentMenu) {
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
  m_currentMenu = (m_currentMenu + 3) % 4;
}

void StateMenu::increase() {
   m_currentMenu = (m_currentMenu + 1) % 4;
}

int StateMenu::accept() {
  return m_currentMenu;
}


int StateMenu::undo() {
  return 0;
}
