#ifndef HELPER_H_INCLUDED
#define HELPER_H_INCLUDED

#include <SDL2/SDL.h>
#include "SDL2/SDL_ttf.h"

#define DEBUG true

bool init();
bool create_window(SDL_Window **);
bool create_renderer(SDL_Renderer **, SDL_Window *);
bool init_ttf();
bool init_all(SDL_Window *, SDL_Renderer **);

#endif // HELPER_H_INCLUDED
