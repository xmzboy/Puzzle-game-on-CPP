#ifndef _INTRO_H_
#define _INTRO_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "SDL2/SDL_ttf.h"

/* Заставка */
class Intro{
    SDL_Texture *intro;
    SDL_Renderer *renderer;
public:
     Intro(SDL_Renderer *_renderer);
     void show();
     void LoadImage();
};

#endif

