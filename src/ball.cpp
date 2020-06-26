#include "ball.h"
#include "common.h"



Ball::Ball()
{
    //initialize x, y, and velocity
    x = SCREEN_WIDTH / 2;
    y = SCREEN_HEIGHT / 2;

    //initialize random seed
    srand( time( NULL ) );

    //initialize y velocity with random number between 0 and 6
    velY = rand() % 6;
    velX = BVELOCITY;
}

void Ball::Collision()
{

    float i = -5;
    for( auto &item : LPADDLE )
    {

        if( x == item.x + 10 && y == item.y )
        {

            //volley the ball back
            velX *= -1;

            //adjust the angle of trajectory base on where it hit 
            velY =  i; 
        }
        
        i += .083333;
    
    }

    float z = -5;
    for( auto &item : RPADDLE )
    {
        if( x == item.x - 10 && y == item.y )
        {
            //volley the ball back
            velX *= -1;
        
            //adjust the angle of trajectory
            velY = z;
        }
    
        z += .083333;
    }
}

bool Ball::Out()
{
    //check if ball is out of bounds
    if( x == 0 || x == SCREEN_WIDTH - 10 )
    {
        //place ball back in center of screen
        x = SCREEN_WIDTH / 2;
        y = SCREEN_HEIGHT / 2;

        //initialize random seed
        srand( time( NULL ) );

        //initialize y velocity with random number between 0 and 5
        velY = rand() % 6;

        //start the ball in the opposite direction it began
        ++ round;
        if( round % 2 == 0 )
        {
            velX = BVELOCITY * -1;
        }
        else
        {
            velX = BVELOCITY;
        }
        

        return true;
    }
    else
    {
        return false; 
    }
    
}


void Ball::Move()
{
    //move ball up or down
    y += velY;

    //move ball left or right
    x += velX;

    //if the ball went too far up
    if( y < 0 )
    {
        //move back
        velY = velY * -1; 
    
    }
    //if the ball went too far down
    if( y + BALL_HEIGHT > SCREEN_HEIGHT )
    {
        velY = velY * -1;

    }

}

void Ball::Render()
{
    BALL.Render( x, y );
}
