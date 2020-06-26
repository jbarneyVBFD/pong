#ifndef COMMON_H
#define COMMON_H

#include <SDL2/SDL.h>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <stdio.h>

#include "paddle.h"
#include "ball.h"
#include "renderer.h"
#include "game.h"

//screen dimensions
extern const int SCREEN_HEIGHT;
extern const int SCREEN_WIDTH;

//dimensions of paddle
extern const int PADDLE_WIDTH;
extern const int PADDLE_HEIGHT;

//vector containing position of paddles and ball
extern std::vector<SDL_Point> LPADDLE;
extern std::vector<SDL_Point> RPADDLE; 

//dimensions of ball
extern const int BALL_WIDTH;
extern const int BALL_HEIGHT;

//velocity of paddle 
extern const int VELOCITY;

//velocity of ball
extern const int BVELOCITY;

//global window
extern SDL_Window *WINDOW;

//global renderer
extern SDL_Renderer *RENDERER;

//global right paddle renderer
extern Renderer rPADDLE;

//global left paddle renderer
extern Renderer lPADDLE;

//global ball renderer
extern Renderer BALL;

//global background renderer
extern Renderer BACKGROUND;

#endif