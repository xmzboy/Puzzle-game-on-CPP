#include "Rules.h"

Rules::Rules(SDL_Renderer *const &renderer) : texture(renderer), color {0, 0, 228}
{
    font = TTF_OpenFont("font.otf", 19);
    buf = "\n                                            СПРАВОЧНАЯ ИНФОРМАЦИЯ\n\n\nАвтор:Андрейчук Иван\nГруппа: И584\nИгра: Паззлы\nИнструкция: Перетягивайте кусочки картинки на игральную доску собирая \nцелое изображение. Наводите на изображение картинки в правом верхнем \nуглу чтобы увидеть подсказку. Клавиша Esc-выход на предыдущий экран.";
    texture.loadFromRenderedTextWrapped(buf, color, font, 1260);
    texture.SetRenderParameters(10, 15, 1280, 500);
    buttonExit = new Button(renderer, SDL_Color {255, 0, 0}, SDL_Color {8, 232, 222},  SDL_Color {120, 162, 183}, "Вернуться в главное меню", font, SDL_Rect{10, 8, 152, 30});
}

void Rules::Show() {
    texture.render();
    buttonExit->render();
}

Rules::EventTypes Rules::EventInfo(SDL_Event &event) {
    if (buttonExit->eventHandler(event)) return Exit;
    return Nothing;
}

Rules::~Rules() {
    if (buttonExit) {
        std::cout << "INFO BUTTON deleted" << std::endl;
        delete buttonExit;
        std::cout << "INFO BUTTON deleted" << std::endl;
        buttonExit = nullptr;
        std::cout << "INFO BUTTON deleted" << std::endl;
    }
}
