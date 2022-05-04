#include "menu.h"
Info::Info(std::string line, TTF_Font * _font)
{
  filename = line.substr(0, line.find_first_of(";"));
  SDL_Log("filename: %s", filename.c_str());
  time = line.substr(line.find_first_of(";") + 1, line.find_last_of(";") - line.find_first_of(";") - 1);
  SDL_Log("time: %s", time.c_str());
  previews = line.substr(line.find_last_of(";") + 1);
  SDL_Log("previews: %s", previews.c_str());
  next = NULL;
  font = _font;
  /// проверяем успешно ли загрузился шрифт
  if (!font)
    SDL_Log("TTF_OpenFont: %s\n", TTF_GetError());
  /// Задаем цвет шрифта - черный
  font_color.r = 0;
  font_color.g = 0;
  font_color.b = 0;
  font_color.a = 255;
  selected = false;
}

Info::Info(std::string _filename, int _time, int _previews, TTF_Font * _font)
{
  std::ostringstream ss_previews, ss_time;

  filename = _filename;

  ss_previews << _previews;
  previews = ss_previews.str();

  ss_time << _time;
  time = ss_time.str();

  next = NULL;

  logo = NULL;
  text = NULL;

  font = _font; //TTF_OpenFont("arial.ttf", 16);  /// загружаем шрифт

  /// проверяем успешно ли загрузился шрифт
  if (!font)
    SDL_Log("TTF_OpenFont: %s\n", TTF_GetError());

  /// Задаем цвет шрифта - черный
  font_color.r = 0;
  font_color.g = 0;
  font_color.b = 0;
  font_color.a = 255;
  selected = false;
}

std::string Info::get_string()
{
  return filename + ";" + time + ";" + previews;
}

std::string Info::get_text()
{
  char buf[32];
  memset(buf, 0, 32);
  sprintf(buf, "%01.0f:%02.0f:%02.2f", floor(atof(time.c_str())/3600.0), floor(fmod(atof(time.c_str()),3600.0)/60.0), fmod(atof(time.c_str()),60.0));
  std::string time_str(buf);
  return std::string("Файл: ") + filename + std::string(", лучшее время: ") + time_str + std::string(", подсмотрено: ") + previews;
}


