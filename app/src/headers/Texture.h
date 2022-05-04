#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

using namespace std;

enum Direction{
    Left, Right, Up, Down, None
};

class Texture
{
    public:
        explicit Texture(SDL_Renderer* );
        ~Texture();

        //Loads image at specified path
        bool loadFromFile( const char* path);

        //Creates image from font string
        bool loadFromRenderedText(const char* textureText, SDL_Color textColor, TTF_Font* gFont );

        //Creates image from font string (wrapped)
        bool loadFromRenderedTextWrapped(const char *textureText, SDL_Color textColor, TTF_Font *gfont, int textWidth);

        //Create Texture
        bool createTexture(int width, int height, SDL_TextureAccess access, int x = 0, int y = 0);

        //Deallocates texture
        void free();

        //Set alpha modulation
        void setAlpha( Uint8 alpha );

        void setRenderTarget(bool enable);
        void RenderCopy(SDL_Renderer* renderer, SDL_Rect* frame, SDL_Rect* scrRect);

        void SetRenderParameters(int x, int y, int w, int h);

        //Renders texture at given point
        virtual void render( int xOffcet = 0, int yOffcet = 0);

        //Gets image dimensions
        int getWidth(){return mWidth;}
        int getHeight(){return mHeight;}
        int GetPosX(){return xPos;}
        int GetPosY(){return yPos;}

        int mWidth;
        int mHeight;
    protected:
        //The actual hardware texture
        SDL_Texture* mTexture;
        SDL_Renderer* renderer;

        //Image dimensions

        int xPos, yPos;
};

#endif // TEXTURE_H
