#include "MainWindow.h"

MainWindow::MainWindow(SDL_Window *const &window, SDL_Renderer *const &renderer) : windowID(0), quit(false), mainmenu(window, renderer), rules(renderer), gameclass(renderer, window)
{
}
void MainWindow::Execution(SDL_Window *const &window, SDL_Renderer *const &renderer) {
    bool flag = true;
    Status status = Status(MainMenuStatus);
    SDL_Event event;
    windowID = SDL_GetWindowID(window);
    while (!quit) {
        while(SDL_PollEvent(&event) || flag) {
            if (event.type == SDL_QUIT || event.type == SDL_WINDOWEVENT && event.window.windowID == windowID && event.window.event == SDL_WINDOWEVENT_CLOSE) { // Если закрыли программу
                quit = true;    // Выходим из программы
            }
            flag = false;
            if (status == MainMenuStatus)  // Если находимся в меню
                switch(mainmenu.EventMenu(event)) {
                    case MainMenu::Exit:
                        quit = true;                     // Если нажали на выход
                        break;
                    case MainMenu::Rule:
                        status = Status(RuleStatus);  // Если открыли справочную информацию
                        break;
                    case MainMenu::Game:
                        status = Status(GameStatus);   // Если открыли game
                        break;
                }
            else if (status == RuleStatus) {
                if (rules.EventInfo(event) == Rules::Exit)
                    status = Status(MainMenuStatus);
            }

            else if (status == GameStatus) {
                if (gameclass.EventGame(event) == GameClass::Exit)
                    status = Status(MainMenuStatus);
            }

        if (status == MainMenuStatus) {
            SDL_SetRenderDrawColor(renderer, 150, 244, 213, 255);
            SDL_RenderClear(renderer);
            mainmenu.Show(renderer);
        }

         else if (status == RuleStatus) {
            SDL_SetRenderDrawColor(renderer, 220, 220, 220, 255);
            SDL_RenderClear(renderer);
            rules.Show();
        }

        else if (status == GameStatus) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderClear(renderer);
            gameclass.Show(renderer);
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(10);
        SDL_RenderClear(renderer);
    }
}
}



