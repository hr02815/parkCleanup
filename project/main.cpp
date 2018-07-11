#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
//#include"LTexture.h"
#include "People.h"
//#include "Button.h"

using namespace std;

//Pre defined screen width and height
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

bool init();
bool loadMedia();
void close();

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
LTexture BgSpriteSheetTexture;
LTexture peopleSpriteSheetTexture;
LTexture Truck;


bool init();
bool loadMedia();
void close();

int main( int argc, char* args[] )
{



    //Start up SDL and create window
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        //Load media
        if( !loadMedia() )
        {
            printf( "Failed to load media!\n" );
        }
        else
        {

            bool quit = false;                      //Main loop flag
            SDL_Event e;                            //Event handler
            long int frame = 0;                     //Current animation frame

            // initialize random seed:
            srand (time(NULL));

            int x = 210;
            int y = 9;
            int w = 385 - 210;
            int h = 168 - 9;
            SDL_Rect background = {x, y, w, h};
            //SDL_Rect character = {0, 0, 30, 30};


            BgSpriteSheetTexture.Render(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, &background, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
            //peopleSpriteSheetTexture.Render(15, 15, 30, 30, &character, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
            People p(&peopleSpriteSheetTexture, 700, SCREEN_HEIGHT/2);

            while( !quit )                          //While application is running
            {
                if(frame % 20 == 0)
                {
                    cout<<frame<<endl;
                    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );    //Clear screen
                    SDL_RenderClear( gRenderer );
                    BgSpriteSheetTexture.Render(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, &background, 0.0, NULL, SDL_FLIP_NONE, gRenderer);

                    p.Move();
                    p.Render(frame, gRenderer, false);
                    SDL_RenderPresent( gRenderer );
                }
                while( SDL_PollEvent( &e ) != 0 )   //Handle events on queue
                {


                    //User requests quit
                    if( e.type == SDL_QUIT )
                    {
                        quit = true;
                    }

                    //SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );    //Clear screen
                    //SDL_RenderClear( gRenderer );
                    //p.Render(frame, gRenderer, false);
                    //SDL_RenderPresent( gRenderer );     //Update screen
                    //cout<<frame<<endl;
                    //frame++;                            //Go to next frame

                }
                SDL_RenderPresent( gRenderer );
                cout<<frame<<endl;
                frame++;

            }

            //Free resources and close SDL
            close();

        }
    }



    return 0;

}

bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Set texture filtering to linear
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            printf( "Warning: Linear texture filtering not enabled!" );
        }

        //Create window
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Create renderer for window
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if( gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                    success = false;
                }
            }
        }
    }

    return success;
}

bool loadMedia()
{
    //Loading success flag
    bool success = true;

    //Load sprite sheet texture
    if( !BgSpriteSheetTexture.LoadFromFile( "Images/park.png", gRenderer  ) )
    {
        printf( "Failed to load sprite sheet texture!\n" );
        success = false;
    }
    if( !peopleSpriteSheetTexture.LoadFromFile( "Images/characters.png", gRenderer  ) )
    {
        printf( "Failed to load sprite sheet texture!\n" );
        success = false;
    }
    if( !Truck.LoadFromFile( "Images/characters.png", gRenderer  ) )
    {
        printf( "Failed to load sprite sheet texture!\n" );
        success = false;
    }

    return success;
}

void close()
{
    //Free loaded images
    BgSpriteSheetTexture.Free();
    peopleSpriteSheetTexture.Free();

    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}
