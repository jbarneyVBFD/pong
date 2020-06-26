#include "renderer.h"
#include "common.h"

Renderer::Renderer()
{
    //initialize
    texture = NULL;
    iWidth = 0;
    iHeight = 0;
}

Renderer::~Renderer()
{
    //deallocate
    free();
}

bool Renderer::loadFromFile( std::string path )
{
    //get rid of preexisting texture
    free();

    //the final texture
    SDL_Texture *newTexture = NULL;

    //load image at specified path
    SDL_Surface* loadedSurface = SDL_LoadBMP( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "unable to load image %s! SDL_Error: %s\n", path.c_str(), SDL_GetError() );
    }
    else
    {
        //color key image
        SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0xFF, 0xFF, 0xFF ) );

        //create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( RENDERER, loadedSurface );
        if( newTexture == NULL )
        {
            printf( "unable to create texture from %s! SDL_Error: %s\n", path.c_str(), SDL_GetError() );
        }
        else
        {
            //get image dimensions
            iWidth = loadedSurface->w;
            iHeight = loadedSurface->h;
        }

        //get rid of old surface
        SDL_FreeSurface( loadedSurface );
        
    }

    //return success
    texture = newTexture;
    return texture != NULL;
}

void Renderer::free()
{
    //free texture if it exists
    if( texture != NULL )
    {
        SDL_DestroyTexture( texture );
        texture = NULL;
        iWidth = 0;
        iHeight = 0;
    }
}

void Renderer::Render( int x, int y, SDL_Rect *clip, double angle, SDL_Point *center, SDL_RendererFlip flip )
{
    //set rendering space and render to screen
    SDL_Rect renderQuad = { x, y, iWidth, iHeight };

    //set clip rendering dimensions
    if( clip != NULL )
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    //render to screen
    SDL_RenderCopyEx( RENDERER, texture, clip, &renderQuad, angle, center, flip );
}

int Renderer::getWidth()
{
    return iWidth;
}

int Renderer::getHeight()
{
    return iHeight;
}
