#include "SystemController.h"

SystemController::SystemController() {
  for(uint8_t i = 0; i < 4; ++i) {
      buttons[i] = Button(i+6);
  }
  view = new MainMenu;
  view->refreshScreen();
  setTime(16,30,00,8, 06, 2017);
  TempCounter = 0;
}

SystemController::~SystemController() {
  delete view;
}

void SystemController::creteMenuFromMainMenu() {
  switch (view->accept()) {
    case 0:
      delete view;
      view = new StateMenu;
      break;
    case 2:
      delete view;
      view = new TimeMenu;
      break;
    }
}



void SystemController::loop() {
  while(1){
    for (uint8_t i = 0; i < 4; ++i) {
      buttons[i].checkIfPushed();
    }
    if(buttons[0].isPushed()) {
      switch (view->getMenuID()) {
          case 0:
            creteMenuFromMainMenu();
            break;
          case 3:
            view->accept();
            break;
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
      ++TempCounter;
      if(TempCounter == 10){
        TempCounter = 0;
        Serial.print("Temperatura: ");
        Serial.print(m_tempSystem.getDTH11Temp());
        Serial.print(" C\t");
        Serial.print("Wilgotnosc: ");
        Serial.print(m_tempSystem.getDTH11Humi());
        Serial.print(" %\n");
        //m_tempSystem.getThermomethersTemp();
      }
    }

  }
}
