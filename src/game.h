#ifndef GAME_H
#define GAME_H

#include <string>

class Game
{
    public:
        //initialize and run game
        void Run();

        //initialize sdl and create window
        bool init();

        //load media from file
        bool loadMedia( std::string path1, std::string path2, std::string path3, std::string path4 );

        //free resources and shut down sdl
        void close();
};

#endif