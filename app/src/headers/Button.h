#ifndef BUTTON_H
#define BUTTON_H
#include "Texture.h"

class Button : public Texture
{
    public:
        explicit Button(SDL_Renderer* renderer, SDL_Color normalTextColor, SDL_Color pressedTextColor, SDL_Color highlightedTextColor, const char *, TTF_Font *font, SDL_Rect rect);  // Кнопка с текстом
        ~Button();
        bool eventHandler(SDL_Event& e);
        bool eventHandlerGame(SDL_Event& e);

        void render( int offcetX = 0, int offcetY = 0);
    private:
        enum buttonTypes {
            onlyText,
            onlyBackground,
            BackgroundText
        };
        void setText(const char* text, TTF_Font* font);
        void SetNormalColor();
        void SetHighlightedColor();
        void SetPressedColor();
        SDL_Color normalTextColor, pressedTextColor, highlightedTextColor;
        Texture *normalTextColorTexture, *pressedTextColorTexture, *highlightedTextColorTexture;
        Texture *curTexture, *curBackTexture;
        buttonTypes btnTypes;
};

#endif // BUTTON_H
