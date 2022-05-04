#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "SDL2/SDL_ttf.h"
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <dirent.h>
class Info{
public:
  Info(std::string line, TTF_Font * _font);
  Info(std::string _filename, int _time, int _previews, TTF_Font * _font);
  std::string get_string();
  std::string get_text();
  std::string filename;
  std::string time;
  std::string previews;
  Info *next;
  SDL_Texture *logo;
  SDL_Texture *text;
  SDL_Color font_color;
  TTF_Font *font;
  SDL_Rect *pos;
  bool selected;
};
#endif // MENU_H_INCLUDED
