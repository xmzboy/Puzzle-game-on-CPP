#include "Texture.h"

Texture::Texture(SDL_Renderer* renderer)
{
    mTexture = NULL;
    this->renderer = renderer;
    mWidth = 0;
    mHeight = 0;
}

Texture::~Texture()
{
    cout << "texture destructor" << endl;
    free();
}

void Texture::free(){
    if( mTexture != NULL )
    {
        SDL_DestroyTexture( mTexture );
        mTexture = NULL;
        mWidth = 0;
        mHeight = 0;
    }
}

void Texture::RenderCopy(SDL_Renderer* renderer, SDL_Rect* frame, SDL_Rect* scrRect){
    SDL_RenderCopy(renderer,mTexture,frame,scrRect);
}

void Texture::setRenderTarget(bool enable){
    if (enable) SDL_SetRenderTarget(renderer, mTexture);
    else SDL_SetRenderTarget(renderer, NULL);
}

bool Texture::loadFromFile(const char* path){
    free();
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError() );
    }
    else
    {
        //Color key image
        SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
        if( newTexture == NULL )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError() );
        }
        else
        {
            //Get image dimensions
            mWidth = loadedSurface->w;
            mHeight = loadedSurface->h;
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    mTexture = newTexture;
    return mTexture != NULL;
}
void Texture::setAlpha(Uint8 alpha){
    SDL_SetTextureAlphaMod( mTexture, alpha );
}
bool Texture::loadFromRenderedText( const char* textureText, SDL_Color textColor, TTF_Font* gFont)
{
    //Get rid of preexisting texture
    free();

    //Render text surface
    SDL_Surface* textSurface = TTF_RenderUTF8_Blended( gFont, textureText, textColor );
    if( textSurface == NULL)
    {
        //printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
    }
    else
    {
        //Create texture from surface pixels
        mTexture = SDL_CreateTextureFromSurface( renderer, textSurface );
        if( mTexture == NULL )
        {
            printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
        }
        else
        {
            //Get image dimensions
            mWidth = textSurface->w;
            mHeight = textSurface->h;
        }

        //Get rid of old surface
        SDL_FreeSurface( textSurface );
    }

    //Return success
    return mTexture != NULL;
}

bool Texture::loadFromRenderedTextWrapped(const char *textureText, SDL_Color textColor, TTF_Font *gFont, int textWidth) {
       //Get rid of preexisting texture
    free();

    //Render text surface
    SDL_Surface* textSurface = TTF_RenderUTF8_Blended_Wrapped( gFont, textureText, textColor, textWidth );
    if( textSurface == NULL )
    {
        //printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
    }
    else
    {
        //Create texture from surface pixels
        mTexture = SDL_CreateTextureFromSurface( renderer, textSurface );
        if( mTexture == NULL )
        {
            printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
        }
        else
        {
            //Get image dimensions
            mWidth = textSurface->w;
            mHeight = textSurface->h;
        }

        //Get rid of old surface
        SDL_FreeSurface( textSurface );
    }

    //Return success
    return mTexture != NULL;
}
bool Texture::createTexture( int width, int height, SDL_TextureAccess access, int xPos, int yPos){
    free();
    mTexture = SDL_CreateTexture( renderer, SDL_PIXELFORMAT_RGBA8888, access, width, height );
    SDL_SetTextureBlendMode(mTexture,SDL_BLENDMODE_BLEND);

    if( mTexture == NULL )
    {
        printf( "Unable to create blank texture! SDL Error: %s\n", SDL_GetError() );
    }
    else
    {
        mWidth = width;
        mHeight = height;

        this->xPos = xPos;
        this->yPos = yPos;
    }

    return mTexture != NULL;
}

void Texture::SetRenderParameters(int x, int y, int w, int h){
        xPos = x;
        yPos = y;
        mWidth = w;
        mHeight = h;
}

void Texture::render( int xOffcet, int yOffcet )
{
    //Set rendering space and render to screen
    SDL_Rect renderQuad = { xPos+xOffcet, yPos+yOffcet, mWidth, mHeight };

    //Render to screen
    SDL_RenderCopy( renderer, mTexture, NULL, &renderQuad);
}

