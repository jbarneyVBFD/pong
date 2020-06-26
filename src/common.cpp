#include "common.h"


//screen dimensions
const int SCREEN_HEIGHT = 480;
const int SCREEN_WIDTH = 640;

//dimensions of paddle
const int PADDLE_WIDTH = 30;
const int PADDLE_HEIGHT = 90;

//vector containing position of paddles and ball
std::vector<SDL_Point> LPADDLE( PADDLE_HEIGHT + 30 );
std::vector<SDL_Point> RPADDLE( PADDLE_HEIGHT + 30 ); 

//dimensions of ball
const int BALL_WIDTH = 30;
const int BALL_HEIGHT = 30;

//velocity of paddle and ball
const int VELOCITY = 10;
const int BVELOCITY = 5;

//global window
SDL_Window *WINDOW;

//global renderer
SDL_Renderer *RENDERER;

//global right paddle renderer
Renderer rPADDLE;

//global left paddle renderer
Renderer lPADDLE;

//global ball renderer
Renderer BALL;

//global background rednerer
Renderer BACKGROUND;