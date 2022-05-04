#ifndef STAT_H_INCLUDED
#define STAT_H_INCLUDED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "SDL2/SDL_ttf.h"
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <dirent.h>
#include "Button.h"
#include "menu.h"
#include "Graphics.h"
class Stat: public Graphics {
public:
    enum EventTypes{
    Nothing,
    Exit
};
    Texture texture;
  SDL_Rect pos;
  SDL_Renderer *mainRenderer;
public:
  Stat(SDL_Renderer *_renderer);
  std::string handle_event(SDL_Event * event);
  void add_info(Info *info);
  void update(Info *info);
  void load_from_directory();
  void load_from_file();
  void save();
  void draw_items();
  const char* show();
  Info *first;
  TTF_Font *font_p;
  TTF_Font *font;
  EventTypes EventMenu(SDL_Event &);
};

#endif // STAT_H_INCLUDED
