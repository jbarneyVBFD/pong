#include "paddle.h"
#include "common.h"


Paddle::Paddle( Side side ) : side( side )
{
    Center( side );
}

Paddle::Side Paddle::getSide()
{
    return side;
}

void Paddle::handleEvent( SDL_Event &e )
{
    if ( side == Side::left )
    {
        //if a key was pressed
        if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
        {
            //adjust velocity
            switch( e.key.keysym.sym )
            {
                case SDLK_a:
                {
                    velY -= VELOCITY;
                    break;
                }
                case SDLK_z:
                {   
                    velY += VELOCITY;
                    break;
                }
            }
        }
        //if a key was released
        else if ( e.type == SDL_KEYUP && e.key.repeat == 0 )
        {
            //adjust the velocity
            switch( e.key.keysym.sym )
            {
                case SDLK_a:
                {
                    velY += VELOCITY;
                    break;
                }
                case SDLK_z:
                {
                    velY -= VELOCITY;
                    break;
                }
            }
        }
    }

    //handle input for the right sided paddle
    if ( side == Side::right )
    {
        //if a key was pressed
        if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
        {
            //adjust velocity
            switch( e.key.keysym.sym )
            {
                case SDLK_UP:
                {
                    velY -= VELOCITY;
                    break;
                }
                case SDLK_DOWN:
                {   
                    velY += VELOCITY;
                    break;
                }
            }
        }
        //if a key was released
        else if ( e.type == SDL_KEYUP && e.key.repeat == 0 )
        {
            //adjust the velocity
            switch( e.key.keysym.sym )
            {
                case SDLK_UP:
                {
                    velY += VELOCITY;
                    break;
                }
                case SDLK_DOWN:
                {
                    velY -= VELOCITY;
                    break;
                }
            }
        }
    }
    
}

void Paddle::Move()
{
    //move paddle up or down
    y += velY;

    //update vectors
    if( getSide() == Side::left )
    {
        for( auto &item : LPADDLE )
        {
            item.y += velY;
        }
    }

    if( getSide() == Side::right )
    {
        for( auto &item : RPADDLE )
        {
            item.y += velY;
        }
    }

    //if the paddle went too far down
    if( y < 0 )
    {
        //move back
        y += VELOCITY;

        //update vectors
        if( getSide() == Side::left )
        {
            for( auto &item : LPADDLE )
            {
                item.y += VELOCITY;
            }
        }

        if( getSide() == Side::right )
        {
            for( auto &item : RPADDLE )
            {
                item.y += VELOCITY;
            }
        }

    }

    //if the paddle went too far up
    if( y + PADDLE_HEIGHT > SCREEN_HEIGHT )
    {
        y -= VELOCITY;

        //update vectors
        if( getSide() == Side::left )
        {
            for( auto &item : LPADDLE )
            {
                item.y -= VELOCITY;
            }
        }

        if( getSide() == Side::right )
        {
            for( auto &item : RPADDLE )
            {
                item.y -= VELOCITY;
            }
        }

    }
}

void Paddle::Render( Paddle::Side side )
{
    if( side == Paddle::Side::left )
    {
        lPADDLE.Render( x, y );
    }
    if( side == Paddle::Side::right )
    {
        rPADDLE.Render( x, y );
    }
}

void Paddle::Center( Side side )
{
    //initialize x, y, and velocity
    if( side == Paddle::Side::left )
    {
        x = 0;
        //add x and y points in vector
        int i = 1;
        for( auto &item : LPADDLE )
        {
            i++;
            item.x = 0;
            item.y = -30 + SCREEN_HEIGHT / 2 - PADDLE_HEIGHT / 2 + i;
        }
    }
    else if ( side == Paddle::Side::right )
    {
        x = SCREEN_WIDTH - PADDLE_WIDTH;
        //add x and y points in vector
        int i = 1;
        for( auto &item : RPADDLE )
        {
            i++;
            item.x = x;
            item.y = -30 + SCREEN_HEIGHT / 2 - PADDLE_HEIGHT / 2 + i;
        }
    }
    
    y = SCREEN_HEIGHT / 2 - PADDLE_HEIGHT / 2;

    //initialize velY to be 0(not moving)
    velY = 0;
}