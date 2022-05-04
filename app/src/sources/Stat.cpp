#include "Stat.h"
Stat::Stat(SDL_Renderer *_renderer): texture(_renderer)
{
  this->first = NULL;
  mainRenderer = _renderer;
  font = TTF_OpenFont("font.otf", 15);
  load_from_directory();
  load_from_file();
  font_p = TTF_OpenFont("font.otf", 25);
}

void Stat::add_info(Info *info)
{
  if(this->first == NULL)
    this->first = info;
  else
  {
    Info * ptr = first;
    while(ptr->next != NULL)
    {
      ptr = ptr->next;
    }
    ptr->next = info;
  }
}

void Stat::load_from_directory()
{
  DIR *dir;
  struct dirent *ent;

  if ((dir = opendir (".")) != NULL)
  {
    while ((ent = readdir (dir)) != NULL)
    {
      std::string filename(ent->d_name);
      if(filename.substr(filename.find_last_of(".") + 1) == "png")
      {
        SDL_Log("Found image %s", filename.c_str());
        Info *info = new Info(filename, 3599, 99, font);
        info->logo = IMG_LoadTexture(mainRenderer, filename.c_str());
        if (info->logo == NULL) {
          SDL_Log("Error: texture not loaded");  /// не удалось загрузить картинку
        }
        add_info(info);
      }
    }
    closedir (dir);
  }
}

void Stat::load_from_file()
{
  std::string line;
  std::ifstream sfile ("stat.txt");
  if (sfile.is_open())
  {
    while (getline (sfile,line))
    {
      Info *info = new Info(line, font);
      update(info);
    }
    sfile.close();
  }

}

void Stat::save()
{
  std::ofstream sfile ("stat.txt");
  if (sfile.is_open())
  {
    Info * ptr = this->first;
    while(ptr != NULL)
    {
      sfile << ptr->get_string() << std::endl;
      ptr = ptr->next;
    }
    sfile.close();
  }

}

void Stat::update(Info * info)
{
  Info * ptr = this->first;
  while(ptr != NULL)
  {

  if(ptr->filename == info->filename && (atoi(ptr->time.c_str()) >= atoi(info->time.c_str())))
        {
            ptr->time = info->time;
            ptr->previews = info->previews;
            break;
        }
    if(ptr->next!=NULL)
      ptr = ptr->next;
    else
      ptr = info;
  }
}

void Stat::draw_items()
{
  int i = 0;
  Info * ptr = this->first;
bool quit = false;

  while(ptr != NULL && !quit)
  {

    SDL_Rect img;
    img.x = 0;
    img.y = 0;
    SDL_QueryTexture(ptr->logo, NULL, NULL, &img.w, &img.h);

    ptr->pos = new SDL_Rect;
    ptr->pos->x = 20;
    ptr->pos->y = 50 + (i*110);
    ptr->pos->h = 100;
    ptr->pos->w = 120;

    SDL_Surface* text_surface = TTF_RenderUTF8_Blended(ptr->font, ptr->get_text().c_str(), ptr->font_color);            /// получаем поверхность в виде текста
    ptr->text = SDL_CreateTextureFromSurface(mainRenderer, text_surface);    /// прогоняем поверхность через рендер и получаем текстуру
    SDL_Rect text_pos;
    text_pos.x = ptr->pos->x + 140;
    text_pos.y = ptr->pos->y + 30;
    SDL_QueryTexture(ptr->text, NULL, NULL, &text_pos.w, &text_pos.h);
    SDL_FreeSurface(text_surface);



    if(ptr->selected)
    {
      SDL_Rect sel_position;
      sel_position.x = 0;
      sel_position.y = 50 + (i*110);
      sel_position.w = 800;
      sel_position.h = 100;
      SDL_SetRenderDrawColor(mainRenderer, 0xE0, 0xE0, 0xE0, 255 ); /// кнопка меню, цвет тулбара - светло серый
      SDL_RenderFillRect(mainRenderer, &sel_position);
      SDL_SetRenderDrawColor(mainRenderer, 0xFF, 0xFF, 0xFF, 255 ); /// кнопка меню, цвет тулбара - светло серый
    }
    SDL_RenderCopy(mainRenderer, ptr->logo, &img, ptr->pos);
    SDL_RenderCopy(mainRenderer, ptr->text, NULL, &text_pos);
    SDL_DestroyTexture(ptr->text);
    i++;
    ptr = ptr->next;
  }
    SDL_Texture *text1;
    SDL_Rect position={200,550,150,100};
    SDL_Surface* tsurface = TTF_RenderUTF8_Blended(font_p, "Для выхода нажмите кнопку Esc", first->font_color);
    text1 = SDL_CreateTextureFromSurface(mainRenderer, tsurface);    /// прогоняем поверхность через рендер и получаем текстуру
    SDL_QueryTexture(text1, NULL, NULL, &position.w, &position.h);
    SDL_FreeSurface(tsurface);
    SDL_RenderCopy(mainRenderer, text1, NULL, &position);
    SDL_DestroyTexture(text1);
}

std::string Stat::handle_event(SDL_Event * event)
{
  std::string result("");

  Info * ptr = this->first;
  while(ptr != NULL)
  {

  if (event->type == SDL_MOUSEBUTTONUP || event->type == SDL_MOUSEBUTTONDOWN) {

      if (event->button.button == SDL_BUTTON_LEFT) {
        int y = event->button.y;

        if((y > ptr->pos->y) && (y < ptr->pos->y + ptr->pos->h))
        {
          SDL_Log("Clicked: %s", ptr->filename.c_str());
          return ptr->filename;
        }
      }
    }
    if (event->type == SDL_MOUSEMOTION) // событие перемещения мыши
    {
      int y = event->motion.y;
      if((y > ptr->pos->y) && (y < ptr->pos->y + ptr->pos->h))
      {
        if(!ptr->selected)
          SDL_Log("selected: %s", ptr->filename.c_str());
        ptr->selected = true;
      }
      else
      {
        if(ptr->selected)
          SDL_Log("deselected: %s", ptr->filename.c_str());
        ptr->selected = false;
      }

    }
    if( event->type == SDL_KEYDOWN  && event->key.keysym.sym == SDLK_ESCAPE ){
            std::string result2("1");
            return result2;
        }
    ptr = ptr->next;
  }
  return result;
}

const char* Stat::show()
{
  std::string result("");
  bool quit = false;
  bool image_selected = false;
  SDL_Event event1;

  while (!image_selected && !quit )
  {

    SDL_RenderClear(mainRenderer);
    SDL_SetRenderDrawColor(mainRenderer, 255, 255, 255, 255);
    draw_items();
    if( SDL_PollEvent( &event1 ) ){
        result = handle_event(&event1);
        if(result != ""){
            break;
        }
    if( event1.type == SDL_QUIT )
            quit = true;

      }
    SDL_RenderPresent(mainRenderer);
  }
  return result.c_str();
}

