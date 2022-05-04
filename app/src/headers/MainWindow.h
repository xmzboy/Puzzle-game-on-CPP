#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "MainMenu.h"
#include "Rules.h"
#include "Game.h"
class MainWindow {
private:
    enum Status {
        MainMenuStatus,
        GameStatus,
        RuleStatus,
        StatStatus,
    };
    int windowID;
    bool quit;
    MainMenu mainmenu;
    Rules rules;
    GameClass gameclass;
public:
    explicit MainWindow(SDL_Window *const &, SDL_Renderer *const &);
    void Execution(SDL_Window *const &, SDL_Renderer *const &);
};
#endif // MAINWINDOW_H
