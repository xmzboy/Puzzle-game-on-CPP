#ifndef GAME_H
#define GAME_H
#define ITEMS_COUNT 210		/// константа количества кусочков паззла (15х14)
#include <string>
#include <iostream>
#include "Graphics.h"
#include "Button.h"
#include "intro.h"
#include "Stat.h"
class GameClass : public Graphics {
private:
    char buf[256];
    TTF_Font *font_change;
    TTF_Font *font_p;
    Button *buttonExitGame;
    SDL_Renderer *mainRenderer;
    SDL_Texture * text_texture;
    SDL_Surface * text_surface;
    SDL_Color font_color;
    Texture texture;
    SDL_Texture *texture1 = NULL;	  /// указатель на текстуру
    SDL_Rect image;					        /// структура хранящая размеры и положение картинки
    bool quit = false;
    bool quit_game = false;
    bool quit_show = false;
/* Структура хранящая кусочки нарезанного изображения */
    struct item{
      SDL_Rect pix;   // размеры и положение кусочка
      int x;			    // положение по x на доске
      int y;			    // положение по y на доске
      bool done;		  // признак что кусочек уже угадан и размещен на доске
    };
    item board[ITEMS_COUNT];	// массив, хранящий все кусочки паззла
    bool selected = false;		// признак, что выбран мышью какой-то кусочек
    item *selected_item;		  // выбранный мышью элемент
    int feed[24];				      // лента с кусочками
    int feed_selected;			  // номер выбранного элемента в ленте
    bool first_seed = true;		// признак что лента кусочков заполняется впервые
    bool show_full = false;		// признак, что надо показать подсказку в оригинальном размере
    SDL_Event event;
public:
    enum EventTypes {
        Nothing,
        Exit   // Пользователь нажал на выход в главное меню
    };
    bool load_image(const char* filename);
    void draw_board();
    void draw_preview();
    int randomize_feed();
    void draw_feed();
    void draw_timer(int seconds, int previews);
    GameClass(SDL_Renderer *const &, SDL_Window *const &);
    ~GameClass();
    int Show(SDL_Renderer *const &);
    EventTypes EventGame(SDL_Event &);
    SDL_Rect pos;
};

#endif // GAME_H
