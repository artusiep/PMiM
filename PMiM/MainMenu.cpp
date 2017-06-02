#include "MainMenu.h"

MainMenu::MainMenu( ) {
  int menuType = 10;
}

MainMenu::~MainMenu() {}

void MainMenu::refreshTopLine() {
  switch(m_currentMenu){
    case 0:
      guiprint(0,0,"[Stan]Temp Log  ");
      Serial.println("[Stan]Temp Log  ");
      break;
    case 1:
      guiprint(0,0," Stan[Temp]Log  ");
      Serial.println(" Stan[Temp]Log  ");
      break;
    case 2:
      guiprint(0,0," Stan Temp[Log] ");
      Serial.println(" Stan Temp[Log] ");
      break;
  }
  return;
}

void MainMenu::refreshBottomLine() {
  guiprint(8,1,getTimeSystem()->getTime());
}

void MainMenu::refreshScreen() {
  refreshTopLine();
  refreshBottomLine();
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

int MainMenu::undo() {return -1;}
