#ifndef MainMenu_H
#define MainMenu_H
#define M_KOLUMNY 16
#define M_WIERSZE 2
#include <LiquidCrystal_I2C.h>

class MainMenu  {
  private:
    int m_iloscMenu = 3;
    int m_currentMenu;
    LiquidCrystal_I2C m_lcd {0x27, M_KOLUMNY, M_WIERSZE};
    void refreshTopLine();
    //void odswierzDolnaLinie();
  public:
    MainMenu(LiquidCrystal_I2C lcd );
    ~MainMenu();
    void refreshScreen();
    void increase();
    void decrease();
    int accept();
};

#endif
