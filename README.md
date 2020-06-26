# Pong
 C++ Nanodegree Capstone Project

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pong`.

## Pong Game Description

#### I chose to build a simple pong game using the SDL library. This project is designed with the following classes:
* paddle
  * the paddle class is used to define the left and right paddles private variables, and public functions for moving, rendering, etc.
* ball
  * the ball class is used to define the ball's public functions used to move, detect collisions, detect outs, control trajectory, etc.
* renderer
  * the renderer class contains funcions needed to render SDL's textures to the window
* game
  * the game class contains functions needed to initialize the SDL library and run the game
* common
  * the common file, though not a class, contains all of the include statements needed as well as all of the global variables used throughout the app.

#### Expected behaviour of the program
When the program is ran, a simple pong game will ensue. The right side moves the paddle up and down with the up and down keys. The left side moves their paddle up and down with the 'a' and 'z' keys. When the ball goes out, the game resets and starts the ball the opposite direction of the previous round. The game runs continuously until the user closes the window. 

## Rubric Points 
#### The project demonstrates an understanding of C++ functions and control structures.
  * ball.cpp; line 23 - 54
#### The project reads data from a file and process the data, or the program writes data to a file.
  * game.cpp; line 14
#### The project accepts user input and processes the input.
  * paddle.cpp; line 20 - 54
#### Class constructors utilize member initialization lists.
  * paddle.cpp; line 5
#### Classes encapsulate behavior.
  * main.cpp; line 10
