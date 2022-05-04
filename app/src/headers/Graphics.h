#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <iostream>
#include <cmath>
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_image.h"

// Графические элементы
class Graphics {
protected:
    TTF_Font *font;
    SDL_Rect coordinates; // Координаты поверхности
    SDL_Texture *texture;
public:
    Graphics();
    ~Graphics();
};

#endif // GRAPHICS_H
