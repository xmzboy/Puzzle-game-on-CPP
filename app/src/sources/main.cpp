#include <SDL2/SDL_image.h>
#include "helper.h"
#include "intro.h"
#include <time.h>
#include <cstdlib>
#include <cstring>
#include "MainWindow.h"

SDL_Window *window = NULL;		  /// указатель на создаваемое окно
SDL_Renderer *renderer = NULL;	/// указатель на рендерер
TTF_Font *font;
TTF_Font *font_change;
int main ( int argc, char** argv )
{
  if (!init_all(window, &renderer))
    return 6;
  if (!font) {
    SDL_Log("TTF_OpenFont: %s\n", TTF_GetError());
  }
  Intro *in = new Intro(renderer);
  in->show();
  MainWindow mwindow(window, renderer);
  mwindow.Execution(window, renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
