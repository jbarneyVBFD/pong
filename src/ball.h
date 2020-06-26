#ifndef BALL_H
#define BALL_H


class Ball
{
    public:

        //simple constructor
        Ball();

        //handle ball colliding with paddle
        void Collision();

        //return whether ball went out
        bool Out();

        //update position of ball
        void Move();

        //render the ball to the screen
        void Render();


    private:
        //x and y positions of ball
        int x, y;

        //velocity of ball
        int velX, velY;

        //round
        int round = 1;
};


#endif