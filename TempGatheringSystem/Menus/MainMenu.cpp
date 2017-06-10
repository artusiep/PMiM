#include "MainMenu.h"

MainMenu::MainMenu( ) {
  refreshScreen();
}

MainMenu::~MainMenu() {}

void MainMenu::refreshTopLine() {
  switch(currentMenu){
    case 0:
      guiprint(0,0,"[Stan]Temp Czas ");
      break;
    case 1:
      guiprint(0,0," Stan[Temp]Czas ");
      break;
    case 2:
      guiprint(0,0," Stan Temp[Czas]");
      break;
  }
  return;
}

void MainMenu::refreshBottomLine() {
  guiprint(1,1,getTimeSystem()->getWholeDate());
}

void MainMenu::refreshScreen() {
  refreshTopLine();
  refreshBottomLine();
}

int8_t MainMenu::getMenuID() {
  return menuID;
}

void MainMenu::decrease() {
  Serial.println("Left");
  currentMenu = (currentMenu + 2) % numberOfMenu;
  refreshScreen();
}

void MainMenu::increase() {
  Serial.println("Right");
  currentMenu = (currentMenu + 1) % numberOfMenu;
  refreshScreen();
}

int8_t MainMenu::accept() {
  Serial.println("Enter");
  return currentMenu;
}

int8_t MainMenu::undo() {return -1;}
