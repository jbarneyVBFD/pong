#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include <string>

class Renderer
{
    public:
        //initializes variables
        Renderer();

        //deallocates memory
        ~Renderer();

        //loads individual image
        bool loadFromFile( std::string path );

        //deallocates texture
        void free();

        //renders texture at given point
        void Render( int x, int y, SDL_Rect *clip = NULL, double angle = 0.0, SDL_Point *center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

        int getWidth();

        int getHeight();


    private:

        //the actual hardware texture
        SDL_Texture *texture;

        //image dimensions
        int iHeight;
        int iWidth;

};


#endif