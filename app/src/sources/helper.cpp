#include "helper.h"
#include <iostream>
/* Инициализация SDL */
bool init()
{
  bool result = false;
  if(SDL_Init(SDL_INIT_VIDEO) == 0)
    result = true;
  if(DEBUG)
    SDL_Log("SDL_Init: %s", result ? "true" : "false");
  return result;
}
/* Создание окна */
bool create_window(SDL_Window **window)
{
  bool result = false;
  *window = SDL_CreateWindow("Паззл", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
  if (*window != 0x0)
    result = true;
  if(DEBUG)
    SDL_Log("SDL_CreateWindow: %s (%p)", result ? "true" : "false", *window);
  return result;
}
/* Инициализация рендера */
bool create_renderer( SDL_Renderer **renderer, SDL_Window *window)
{
  bool result = false;
  *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if(*renderer != 0x0)
    result = true;
  if(DEBUG)
    SDL_Log("SDL_CreateRenderer: %s (%p)", result ? "true" : "false", *renderer);
  return result;
}
/* Инициализация библиотеки работы со шрифтами */
bool init_ttf()
{
  bool result = false;
  if(TTF_Init() == 0)
    result = true;
  if(DEBUG)
    SDL_Log("TTF_Init: %s", result ? "true" : "false");
  return result;
}
/* Инициализация всех компонентов */
bool init_all(SDL_Window *_window, SDL_Renderer **_renderer)
{
  bool result = true;
  if (!init())
		result = false;
  if (!create_window(&_window))
		result = false;
  if (!create_renderer(_renderer, _window))
    result = false;
  if (!init_ttf())
    result = false;
  return result;
}


