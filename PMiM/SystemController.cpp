#include "SystemController.h"

SystemController::SystemController() {
  for(uint8_t i = 0; i < 4; ++i) {
      buttons[i] = Button(i+6);
  }
  view = new MainMenu;
  view->refreshScreen();
  setTime(16,30,00,02, 06, 2017);
}

SystemController::~SystemController() {
  delete view;
}


void SystemController::loop() {
  while(1){
    for (uint8_t i = 0; i < 4; ++i) {
      buttons[i].checkIfPushed();
    }
    if(buttons[0].isPushed()) {
      switch (view->accept()) {
        case 0:
          delete view;
          view = new StateMenu;
        }
    }
    if(buttons[1].isPushed()) {
      view->decrease();
    }
    if(buttons[2].isPushed()) {
      view->increase();
    }
    if(buttons[3].isPushed()) {
      switch (view->undo()) {
        case 0:
          delete view;
          view = new MainMenu;
      }
    }
    if(m_timeSystem.getTime() != time) {
      time = m_timeSystem.getTime();
      view->refreshScreen();
    }
  }
}
