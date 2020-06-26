#include "game.h"
#include "common.h"

void Game::Run()
{
    //start sdl and create window
    if( !init() )
    {
        printf( "failed to initialize\n" );
    }
    else
    {
        //load media
        if( !loadMedia( "../paddle.bmp", "../rPaddle.bmp", "../ball.bmp", "../space.bmp" ) )
        {
            printf("failed to load media\n" );
        }
        else
        {
            //main loop flag
            bool quit = false;
        
            //event handler
            SDL_Event e;

            //initialize paddle and ball objects
            Paddle lPaddle( Paddle::Side::left );
            Paddle rPaddle( Paddle::Side::right );
            Ball ball;

            //while app is running
            while( !quit )
            {
                //handle events on queue
                while( SDL_PollEvent( &e ) != 0 )
                {
                    //user quits
                    if( e.type == SDL_QUIT )
                    {
                        quit = true;
                    }

                    //handle input for paddles
                    lPaddle.handleEvent( e );
                    rPaddle.handleEvent( e );
                }

                //check for collision
                ball.Collision();

                //check if ball went out
                if( ball.Out() )
                {
                    //wait  1 second
                    SDL_Delay( 1000 );

                    lPaddle.Center( Paddle::Side::left );
                    rPaddle.Center( Paddle::Side::right );

                    //move the paddles and ball
                    lPaddle.Move();
                    rPaddle.Move();
                    ball.Move();

                    //clear the screen
                    SDL_SetRenderDrawColor( RENDERER, 0xFF, 0xFF, 0xFF, 0xFF );
                    SDL_RenderClear( RENDERER );

                    //render background
                    BACKGROUND.Render( 0, 0 );

                    //render paddles
                    lPaddle.Render( Paddle::Side::left );
                
                    rPaddle.Render( Paddle::Side::right );

                    ball.Render();

                    //update the screen
                    SDL_RenderPresent( RENDERER );

                    //wait 1 second
                    SDL_Delay( 1000 );

                    continue;

                }

                //move the paddles and ball
                lPaddle.Move();
                rPaddle.Move();
                ball.Move();


                //clear the screen
                SDL_SetRenderDrawColor( RENDERER, 0xFF, 0xFF, 0xFF, 0xFF );
                SDL_RenderClear( RENDERER );

                //render background
                BACKGROUND.Render( 0, 0 );
                
                //render paddles
                lPaddle.Render( Paddle::Side::left );
                
                rPaddle.Render( Paddle::Side::right );

                ball.Render();

                //update the screen
                SDL_RenderPresent( RENDERER );
            }
        }
        
    }

    //free resources
    close();
}

bool Game::init()
{
    //initialization flag
    bool success = true;

    //initialize sdl
    if( !SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "unable to initialize sdl! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //set texture filtering to linear
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            printf( "warning: linear texture filtering not enabled\n" );
        }
        
        //create window
        WINDOW = SDL_CreateWindow( "Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( WINDOW == NULL )
        {
            printf( "unable to create window! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //create vsynced renderer for window
            RENDERER = SDL_CreateRenderer( WINDOW, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if( RENDERER == NULL )
            {
                printf( "renderer could not be created! SDL_Error: %s\n", SDL_GetError() );
                success = false;
            }
            else
            {
                //initialize renderer color
                SDL_SetRenderDrawColor( RENDERER, 0xFF, 0xFF, 0XFF, 0xFF );
            }
            
        }
        
        
    }
    return success;
}

bool Game::loadMedia( std::string path1, std::string path2, std::string path3, std::string path4 )
{
    //loading success flag
    bool success = true;

    //load textures
    if( !lPADDLE.loadFromFile( path1.c_str() ) )
    {
        printf( "unable to load texture %s! SDL_Error: %s\n", path1.c_str(), SDL_GetError() );
        success = false;
    }
    if( !rPADDLE.loadFromFile( path2.c_str() ) )
    {
        printf( "unable to load texture %s! SDL_Error: %s\n", path2.c_str(), SDL_GetError() );
        success = false;
    }
    if( !BALL.loadFromFile( path3.c_str() ) )
    {
        printf( "unable to load texture %s! SDL_Error: %s\n", path3.c_str(), SDL_GetError() );
        success = false;
    }

    if( !BACKGROUND.loadFromFile( path4.c_str() ) )
    {
        printf( "unable to load texture %s! SDL_Error: %s\n", path4.c_str(), SDL_GetError() );
        success = false;
    }

    return success;
}

void Game::close()
{
    //free loaded images
    rPADDLE.free();
    lPADDLE.free();

    //destroy window
    SDL_DestroyRenderer( RENDERER );
    SDL_DestroyWindow( WINDOW );
    RENDERER = NULL;
    WINDOW = NULL;

    //quit sdl
    SDL_Quit();
}