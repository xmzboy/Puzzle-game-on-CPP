#include "Button.h"

Button::Button(SDL_Renderer* renderer, SDL_Color normalTextColor, SDL_Color pressedTextColor, SDL_Color highlightedTextColor, const char *text, TTF_Font *font, SDL_Rect rect) : Texture(renderer)
{
    normalTextColorTexture = new Texture(renderer);
    pressedTextColorTexture = new Texture(renderer);
    highlightedTextColorTexture = new Texture(renderer);
    xPos = rect.x;
    yPos = rect.y;
    mWidth = rect.w;
    mHeight = rect.h;
    curBackTexture = nullptr;
    this->normalTextColor = normalTextColor;
    this->pressedTextColor = pressedTextColor;
    this->highlightedTextColor = highlightedTextColor;
    btnTypes = onlyText;  // Тип кнопки - только текст
    setText(text, font);
    curTexture = normalTextColorTexture;
}


bool Button::eventHandler(SDL_Event& e) {
    bool retVal = false;
    if (e.button.x >= xPos && e.button.x <= xPos + mWidth &&
        e.button.y >= yPos && e.button.y <= yPos + mHeight) {
        if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT && e.type != SDL_MOUSEBUTTONUP){
            SetPressedColor();
        }
        else if (e.button.button == SDL_BUTTON_LEFT && e.type == SDL_MOUSEBUTTONUP) {
            SetNormalColor();
            retVal = true;
        }
        else if (e.button.button != SDL_BUTTON_LEFT){
            SetHighlightedColor();
        }
    }
    else {
        SetNormalColor();
    }

    return retVal;
}
bool Button::eventHandlerGame(SDL_Event& e) {
    bool retVal = false;
    if (e.key.keysym.sym == SDLK_ESCAPE){
            retVal = true;
        }
    if (e.button.x >= xPos && e.button.x <= xPos + mWidth &&
        e.button.y >= yPos && e.button.y <= yPos + mHeight) {
        if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT && e.type != SDL_MOUSEBUTTONUP){
            SetPressedColor();
        }
        else if (e.button.button == SDL_BUTTON_LEFT && e.type == SDL_MOUSEBUTTONUP) {
            SetNormalColor();
            retVal = true;
        }
        else if (e.button.button != SDL_BUTTON_LEFT){
            SetHighlightedColor();
        }
    }
    else {
        SetNormalColor();
    }

    return retVal;
}

void Button::SetNormalColor() {
    curTexture = normalTextColorTexture;
}

void Button::SetHighlightedColor() {
    curTexture = highlightedTextColorTexture;
}

void Button::SetPressedColor() {
    curTexture = pressedTextColorTexture;
}


void Button::setText(const char* text, TTF_Font* font) {
    normalTextColorTexture->loadFromRenderedText(text,normalTextColor,font);
    normalTextColorTexture->SetRenderParameters(xPos,yPos,mWidth,mHeight);
    pressedTextColorTexture->loadFromRenderedText(text,pressedTextColor,font);
    pressedTextColorTexture->SetRenderParameters(xPos,yPos,mWidth,mHeight);
    highlightedTextColorTexture->loadFromRenderedText(text,highlightedTextColor,font);
    highlightedTextColorTexture->SetRenderParameters(xPos,yPos,mWidth,mHeight);
}

void Button::render( int offcetX, int offcetY ) {
    if (curBackTexture) curBackTexture->render();
    if (curTexture) curTexture->render();
}

Button::~Button() {
    std::cout << "BUTTON DESTRUCTOR" << std::endl;

    if (normalTextColorTexture) {
        std::cout << "normalTextxColorTexture deleted" << std::endl;
        delete normalTextColorTexture;
        std::cout << "normalTextxColorTexture deleted" << std::endl;
        normalTextColorTexture = nullptr;
        std::cout << "normalTextxColorTexture deleted" << std::endl;
    }

    if (pressedTextColorTexture) {
        std::cout << "pressTextColorTexture deleted" << std::endl;
        delete pressedTextColorTexture;
        std::cout << "pressTextColorTexture deleted" << std::endl;
        pressedTextColorTexture = nullptr;
        std::cout << "pressTextColorTexture deleted" << std::endl;
    }

    if (highlightedTextColorTexture) {
        std::cout << "highlightedTextColorTexture deleted" << std::endl;
        delete highlightedTextColorTexture;
        std::cout << "highlightedTextColorTexture deleted" << std::endl;
        highlightedTextColorTexture = nullptr;
        std::cout << "highlightedTextColorTexture deleted" << std::endl;
    }

    if (curTexture) curTexture = nullptr;
    if (curBackTexture) curBackTexture = nullptr;
}

