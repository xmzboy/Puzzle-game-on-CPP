#include "Game.h"

GameClass::GameClass(SDL_Renderer *const &renderer, SDL_Window *const &window) : texture(renderer), mainRenderer(renderer) {
    font = TTF_OpenFont("font.otf", 85);
    font_change = TTF_OpenFont("font.otf", 15);
    font_p = TTF_OpenFont("font.otf", 25);
    buttonExitGame = new Button(renderer, SDL_Color {255, 0, 0}, SDL_Color {8, 232, 222},  SDL_Color {120, 162, 183}, "Выход", font, SDL_Rect{745, 555, 52, 30});

   }

bool GameClass::load_image(const char* filename)
{
  texture1 = IMG_LoadTexture(mainRenderer, filename);
  if (texture1 == NULL) {
    SDL_Log("Error: texture not loaded");  /// не удалось загрузить картинку
    return false;
  }

  /// картики меньше 600х560 не обрабатываются
  SDL_QueryTexture(texture1, NULL, NULL, &image.w, &image.h); /// опрашиваем текстуру узнаем ее размеры
  if (image.w < 600 || image.h < 560) {
    SDL_Log("Error: small picture");
    return false;
  }

  /// инициализируем кусочки
  int counter = 0;
  for(int y = 0; y < 14; y++) {
    for(int x = 0; x < 15; x++) {
      board[counter].pix.x = x * 40;
      board[counter].pix.y = y * 40;
      board[counter].pix.h = 40;
      board[counter].pix.w = 40;
      board[counter].x = x;
      board[counter].y = y;
      board[counter].done = false;    /// элемент еще не угадан
      counter++;

    }
  }
  return true;
}

void GameClass::draw_board(){
SDL_SetRenderDrawColor( mainRenderer, 0xE0, 0xE0, 0xE0, 255 ); /// цвет заливки - светло серый

  int counter = 0;  /// счетчик так как массив board у нас одномерный
  for(int y = 0; y < 14; y++) {
    for(int x = 0; x < 15; x++) {
      SDL_Rect rect;
      rect.x = x*40 + 10 + x;
      rect.y = y*40 + 15 + y;
      rect.h = 40;
      rect.w = 40;
      SDL_RenderFillRect(mainRenderer, &rect);    /// заливаем квадратик
      if(board[counter].done)                 /// если кусочек угадан
        SDL_RenderCopy(mainRenderer, texture1, &board[counter].pix, &rect);  /// то отрисовываем его
      counter++;
    }
}
}

void GameClass::draw_preview()
{
  SDL_Rect src;   /// отрисовываемая часть текстуры
  src.x = 0;
  src.y = 0;
  src.w = 600;
  src.h = 560;

  SDL_Rect dst;   /// Размер и позиция превью в игровом окне
  dst.x = 640;
  dst.y = 15;
  dst.w = 150;
  dst.h = 140;

  SDL_RenderCopy(mainRenderer, texture1, &src, &dst); /// помещаем в очередь для отрисовки

  if(show_full) { /// если по превью кликнули...
    dst.x = 20;
    dst.y = 20;
    dst.w = 600;
    dst.h = 560;

    SDL_RenderCopy(mainRenderer, texture1, &src, &dst);  /// отправляем на отрисовку всю картинку
  }
}

int GameClass::randomize_feed()
{
  bool exist = true;         /// флаг. если он true значит такой элемент уже есть в списке
  srand(time(NULL));  /// инициализируем функцию rand, чтобы случайные числа были случайными
  if(first_seed) {    /// если это первая отрисовка списка с кусочками изображения
    int counter = 0;

    memset(feed, -1, sizeof(int)*24);   /// инициализируем feed числами -1

    do {
      int random = rand() % ITEMS_COUNT;    /// генерируем случайное число

      exist = false;   /// изначально считаем что полученного случайного числа в feed нет

      for(int i = 0; i < 24; i++) {     /// проверка, что сгенерированного числа нет в feed
        if(feed[i] == random) {
          exist = true;                 /// если такое число уже есть в feed, тогда завершаем цикл и ставим флаг в false
          break;
        }
      }
      if(!exist) {    /// а если такого числа нет в feed, то добавляем его туда
        feed[counter] = random;
        counter++;
      }
    }while(counter <= 23); /// и так до тех пор, пока не подберем номера 24 кусочков

    SDL_Log("Randomize done!");
    first_seed = false;   /// все, первая отрисовка готова
    return 0;
  }
  else {  /// если это не первая отрисовка...
    int random = rand() % ITEMS_COUNT;            /// генерируем случайное число
    if(board[random].done == false) {                /// ищем первый неотгаданный кусочек

        exist = false;    /// изначально считаем что номера этого кусочка в feed нет

        for(int z = 0; z < 24; z++) {  /// проверяем что правда нет такого числа
          if(feed[z] == random) {
            exist = true;             /// если есть, то начинаем по новой, это число отбрасываем
            break;
          }
        }
        if(!exist) {                  /// а если нет, то...
          feed[feed_selected] = random;    /// т.к. feed_selected хранит как раз только что угаданный элемент, то заменяем его на найденный
            goto M;
        }
      }
    for(int i = 0; i < ITEMS_COUNT; i++) {   /// пробегаемся по всем элементам доски, начиная со случайного
      if(board[i].done == false) {                /// ищем первый неотгаданный кусочек

        exist = false;    /// изначально считаем что номера этого кусочка в feed нет

        for(int z = 0; z < 24; z++) {  /// проверяем что правда нет такого числа
          if(feed[z] == i) {
            exist = true;             /// если есть, то начинаем по новой, это число отбрасываем
            break;
          }
        }
        if(!exist) {                  /// а если нет, то...
          feed[feed_selected] = i;    /// т.к. feed_selected хранит как раз только что угаданный элемент, то заменяем его на найденный
          break;
        }
      }
    }
  M:  return 0;

  }

}

int GameClass::Show(SDL_Renderer *const &renderer) {

   Stat *st = new Stat(renderer);

   while(!quit)
   {

   quit_game = false;

    std::string f(st->show());
    if(!load_image(f.c_str()))
      return 5;

    else
    {

      draw_board();
      randomize_feed();
    }
    SDL_Rect actual_pos;

    int seconds = 0;
    int previews = 0;

    Uint32 tick_time = SDL_GetTicks() + 1000;

    bool end = false;

    while (!quit_game && !end){
      SDL_RenderClear(renderer);
      draw_board();
      draw_preview();
      draw_feed();
      draw_timer(seconds, previews);
      if(selected){
        SDL_RenderCopy(renderer, texture1, &selected_item->pix, &actual_pos);


        }
      SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

      if (SDL_TICKS_PASSED(SDL_GetTicks(), tick_time)) {
        seconds++;
        tick_time = SDL_GetTicks() + 1000;
      }

      if( SDL_PollEvent( &event ) )
      {
        if (event.type == SDL_MOUSEMOTION) // событие перемещения мыши
        {
          if(selected)
          {
            actual_pos.x = event.motion.x - 20;
            actual_pos.y = event.motion.y - 20;
            actual_pos.h = 40;
            actual_pos.w = 40;
          }
          else
          {
            if((event.motion.x > 640) && (event.motion.x < 790) && (event.motion.y > 15) && (event.motion.y < 155))
            {
              show_full = true;
            }
            else
            {
              if(show_full)
                previews++;
              show_full = false;
            }
          }
        }

        if (event.type == SDL_MOUSEBUTTONDOWN) {
          if (event.button.button == SDL_BUTTON_LEFT) {
            int x = event.button.x;
            int y = event.button.y;

            for(int i = 0; i < 3; i++)
            {
              for(int j = 0; j < 8; j++){
                SDL_Rect pos;
                pos.y = j*40 + 180 + j*6;
                pos.x = i*40 + 640 + i*14;
                pos.w = 40;
                pos.h = 40;
                if ((x > pos.x) && (x < pos.x + pos.w) && (y > pos.y) && (y < pos.y + pos.h)) {
                  selected = true;
                  feed_selected = (i*8 ) + j;
                  selected_item = &board[feed[feed_selected]];
                }
              }
            }
          }
        }

        if (event.type == SDL_MOUSEBUTTONUP) {
          if (event.button.button == SDL_BUTTON_LEFT) {
            int x = event.button.x;
            int y = event.button.y;

            if ((x-20 > selected_item->x*40) && (x-20 < selected_item->x*40 + 40) && (y-20 > selected_item->y*40) && (y-20 < selected_item->y*40 + 40)) {
              SDL_Log("Yes!");
              selected_item->done = true;
              feed[feed_selected] = -1;
              end = true;
              for(int i = 0; i < ITEMS_COUNT; i++)
              {
                if(!board[i].done)
                {
                  end = false;
                  break;
                }
              }
              randomize_feed();
            }
            selected = false;
          }
        }
        if( event.type == SDL_KEYDOWN  && event.key.keysym.sym == SDLK_ESCAPE)
        {
            first_seed = true;
            quit_game = true;
            break;
        }
        if( event.type == SDL_QUIT ){
            first_seed = true;
            quit_game = true;
            break;
        }

      }
      SDL_RenderPresent(renderer);
    }
    if(end)
    {
    first_seed = true;
      Info * uinfo = new Info(f, seconds, previews, font);
      st->update(uinfo);
      st->save();
    }
  }
}

void GameClass::draw_feed()
{
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 8; j++) {
      SDL_Rect pos;
      pos.y = j*40 + 180 + j*6;
      pos.x = i*40 + 640 + i*14;
      pos.w = 40;
      pos.h = 40;
      SDL_RenderCopy(mainRenderer, texture1, &board[feed[(i*8 ) + j]].pix, &pos);
    }
  }
}

void GameClass::draw_timer(int seconds, int previews)
{
  char *str1 = new char[32];
  char *str2 = new char[32];
  memset(str1, 0, 32);
  memset(str2, 0, 32);
  sprintf(str1, "%02.0f:%02.0f:%02.0f", floor((1.0*seconds)/3600.0), floor(fmod(seconds*1.0,3600.0)/60.0), fmod(seconds*1.0,60.0));
  sprintf(str2, "%d", previews);
  std::string s1("Время: ");
  std::string s2(str1);
  std::string _strf1 = s1 + s2;
  std::string s3("Подсказок: ");
  std::string s4(str2);
  std::string _strf2 = s3 + s4;
  font_color.r = 0;
  font_color.g = 0;
  font_color.b = 0;
  font_color.a = 255;
  text_surface = TTF_RenderUTF8_Solid(font_change, _strf2.c_str(), font_color);
  text_texture = SDL_CreateTextureFromSurface(mainRenderer, text_surface);
  SDL_Rect text_pos;
  text_pos.x = 630;
  text_pos.y = 550;
  SDL_QueryTexture(text_texture, NULL, NULL, &text_pos.w, &text_pos.h);
  SDL_RenderCopy(mainRenderer, text_texture, NULL, &text_pos);
  SDL_FreeSurface(text_surface);
  SDL_DestroyTexture(text_texture);
  text_surface = TTF_RenderUTF8_Solid(font_change, _strf1.c_str(), font_color);
  text_texture = SDL_CreateTextureFromSurface(mainRenderer, text_surface);
  text_pos.x = 630;
  text_pos.y = 575;
  SDL_QueryTexture(text_texture, NULL, NULL, &text_pos.w, &text_pos.h);
  SDL_RenderCopy(mainRenderer, text_texture, NULL, &text_pos);
  SDL_FreeSurface(text_surface);
  SDL_DestroyTexture(text_texture);
  delete[] str1;
  delete[] str2;
}
GameClass::EventTypes GameClass::EventGame(SDL_Event &event) {
if (buttonExitGame->eventHandlerGame(event)) return Exit;
    return Nothing;
}
GameClass::~GameClass() {
    if (buttonExitGame) {
        delete buttonExitGame;
        buttonExitGame = nullptr;
    }
}
