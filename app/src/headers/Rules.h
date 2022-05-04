#ifndef RULES_H
#define RULES_H
#include "Graphics.h"
#include "Button.h"

class Rules : public Graphics {
public:
    enum EventTypes{
    Nothing,
    Exit
};

private:
    TTF_Font *font_change;

    Texture texture;
    char *buf;
    SDL_Color color, unselectedColor, selectedColor, pressedColor;
    Button *buttonExit;

public:
    explicit Rules(SDL_Renderer *const &);
    ~Rules();
    void Show();
    EventTypes EventInfo(SDL_Event &);
};

#endif // RULES_H
