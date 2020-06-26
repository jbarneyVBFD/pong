#ifndef PADDLE_H
#define PADDLE_H

#include <SDL2/SDL.h>


class Paddle
{
    public:
        enum class Side { left, right };
        //constructor
        Paddle( Side side );

        //get paddle side
        Side getSide();

        //handle input from user to move paddle
        void handleEvent( SDL_Event &e );

        //update position of paddle
        void Move();

        //render the paddle to the screen
        void Render( Side side );

        //place paddle back in center
        void Center( Side side );


    private:
        //x and y positions of paddle
        int x, y;
        
        //side paddle is on
        Side side;

        //velocity of paddle
        int velY;

};


#endif