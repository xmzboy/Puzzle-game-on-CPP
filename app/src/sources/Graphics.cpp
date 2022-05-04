#include "Graphics.h"

Graphics::Graphics() : texture(nullptr), font(nullptr) {
    coordinates.x = 0;
    coordinates.y = 0;
    coordinates.w = 0;
    coordinates.h = 0;
}

Graphics::~Graphics() {
    std::cout << "GRAPHICS DESTRUCTOR" << std::endl;
    if (texture)
        SDL_DestroyTexture(texture);
    std::cout << "GRAPHICS DESTRUCTOR" << std::endl;
    if (font)
        TTF_CloseFont(font);
    std::cout << "GRAPHICS DESTRUCTOR" << std::endl;
}

