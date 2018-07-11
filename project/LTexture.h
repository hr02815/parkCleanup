#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>

//Texture wrapper class
class LTexture
{
private:
    SDL_Texture* texture;
    int width;
    int height;
public:
    LTexture();
    ~LTexture();

    bool LoadFromFile( std::string path, SDL_Renderer* gRenderer );

    void Free();    //Deallocates texture

    void Render( int x, int y, int w, int h, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE, SDL_Renderer* gRenderer = NULL);

};
