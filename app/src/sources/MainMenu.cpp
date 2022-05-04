#include "MainMenu.h"

MainMenu::MainMenu(SDL_Window *const &window, SDL_Renderer *const &renderer) : mainText(renderer), unselectedColor{155, 134, 233, 255}, selectedColor {0, 0, 255, 255},
                                                                                                                                                pressedColor{100,0,90,255} {
    font = TTF_OpenFont("17838.ttf", 70);
    gameButton = new Button (renderer, unselectedColor, pressedColor, selectedColor, "Игра", font, SDL_Rect{350, 240, 100, 58});
    infoButton = new Button (renderer, unselectedColor, pressedColor, selectedColor, "Справочная информация", font, SDL_Rect{157, 355, 500, 60});
    exitButton = new Button (renderer, unselectedColor, pressedColor, selectedColor, "Выход", font, SDL_Rect{320, 467, 150, 60});


    mainText.loadFromRenderedText("Меню", unselectedColor, font);
    mainText.SetRenderParameters(300, 51, 200, 90);
    Show(renderer);
}

void MainMenu::Show(SDL_Renderer *const &renderer) {
    SDL_SetRenderDrawColor(renderer, 220, 220, 220, 255);
    SDL_RenderClear(renderer);
    mainText.render();

    gameButton->render();
    infoButton->render();
    exitButton->render();
}

MainMenu::EventTypes MainMenu::EventMenu(SDL_Event &event) {
    if (gameButton->eventHandler(event)) return Game;
    if (infoButton->eventHandler(event)) return Rule;
    if (exitButton->eventHandler(event)) return Exit;

    return Nothing;
}

MainMenu::~MainMenu() {
    std::cout << "JUST MAINMNENU DESTRUCTOR " << std::endl;
    if (gameButton) {
        std::cout << "game1 deleted" << std::endl;
        delete gameButton;
        std::cout << "game2 deleted" << std::endl;
        gameButton = nullptr;
        std::cout << "game3 deleted" << std::endl;
    }
    if (infoButton) {
        std::cout << "info1 deleted" << std::endl;
        delete infoButton;
        std::cout << "info2 deleted" << std::endl;
        infoButton = nullptr;
        std::cout << "info3 deleted" << std::endl;
    }
    if (exitButton) {
        std::cout << "exit1 deleted" << std::endl;
        delete exitButton;
        std::cout << "exit2 deleted" << std::endl;
        exitButton = nullptr;
        std::cout << "exit3 deleted" << std::endl;
    }
}

