#include "SystemController.h"


SystemController::SystemController() {
  for(uint8_t i = 0; i < 4; ++i) {
      buttons[i] = Button(i+6);
  }
}


void SystemController::loop() {
  while(1){
    for (uint8_t i = 0; i < 4; ++i) {
      buttons[i].checkIfPushed();
    }
    if(buttons[0].isPushed()) {
      view.mainMenu.accept();
    }
    if(buttons[1].isPushed()) {
      view.mainMenu.decrease();
    }
    if(buttons[2].isPushed()) {
      view.mainMenu.increase();
    }
  }
}
