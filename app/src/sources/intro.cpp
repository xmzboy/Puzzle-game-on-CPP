#include "intro.h"
SDL_Event event1;				        /// структура в которой сохраняется обрабатываемое событие
bool quit = false;

void Intro::LoadImage()
{
        intro = IMG_LoadTexture(renderer, "intro.jpg" );
        if (intro == NULL) {
          SDL_Log("Error: texture not loaded");  /// не удалось загрузить картинку
        }
}

void Intro::show()
{
bool image_selected = false, quit = false;
SDL_RenderClear(renderer);
SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
SDL_RenderCopy(renderer, intro, NULL, NULL);
SDL_Event event;
    while (!image_selected && !quit)
    {
        if( SDL_PollEvent( &event1 ) )
        {
            if (event1.type == SDL_KEYUP)
                quit = true;
            if (event1.type == SDL_MOUSEBUTTONUP)
                quit = true;
            if( event.type == SDL_QUIT )
                quit = true;
        }
    SDL_RenderPresent(renderer);
    }
    SDL_DestroyTexture(intro);
}
Intro::Intro(SDL_Renderer *_renderer)
{
  renderer = _renderer;
  LoadImage();
}
