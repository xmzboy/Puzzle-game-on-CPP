#ifndef MAINMENU_H
#define MAINMENU_H
#include "Graphics.h"
#include "Button.h"

class MainMenu : public Graphics {
public:
    enum EventTypes{
    Nothing,
    Exit,
    Game,
    Rule
};
private:
    Texture mainText;
    SDL_Color unselectedColor, selectedColor, pressedColor;
    Button *gameButton, *infoButton, *exitButton;
    int selectedItem;
public:
    void Show(SDL_Renderer *const &);
    explicit MainMenu(SDL_Window *const &, SDL_Renderer *const &);
    ~MainMenu();
    EventTypes EventMenu(SDL_Event &);
};

#endif // MAINMENU_H
