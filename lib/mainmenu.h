// mainmenu.h
#ifndef MAINMENU_H
#define MAINMENU_H

#include "N5110.h"

enum class MenuState {
    MAIN_MENU,
    HOW_TO_PLAY,
    START_GAME,
    OPTIONS,
    CREDITS,
    QUIT
};

class MainMenu {
public:
    explicit MainMenu(N5110 &display);
    void render();
    void update(int buttonPressed);

private:
    N5110 &lcd;
    MenuState currentMenu;
};

#endif // MAINMENU_H
