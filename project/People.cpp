#include "People.h"
#include <stdlib.h>

People::People(LTexture* image, float x, float y)
{
    this->x = x;
    this->y = y;
    selectClip = 0;
    direction = 2;
    spriteSheetTexture = image;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            character1[i * 3 + j].x = j * 30;
            character1[i * 3 + j].y = i * 31;
            character1[i * 3 + j].w = 30;
            character1[i * 3 + j].h = 31;
            character2[i * 3 + j].x = 90 + j * 30;
            character2[i * 3 + j].y = i * 31;
            character2[i * 3 + j].w = 30;
            character2[i * 3 + j].h = 31;
            character3[i * 3 + j].x = j * 30;
            character3[i * 3 + j].y = 124 + i * 31;
            character3[i * 3 + j].w = 30;
            character3[i * 3 + j].h = 31;
            character4[i * 3 + j].x = 90 + j * 30;
            character4[i * 3 + j].y = 124 + i * 31;
            character4[i * 3 + j].w = 30;
            character4[i * 3 + j].h = 31;
            if(i * 4 + j == 12)
                break;

        }
    }

    width = character1[0].w;
    height = character1[0].h;

}
void People::Move()
{
    if(x < 50 && direction == LEFT)
    {
        while(direction == LEFT)
         {
             direction = rand() % 4;
         }
    }
    if(x > 750 && direction == RIGHT)
    {
        while(direction == RIGHT)
         {
             direction = rand() % 4;
         }
    }
    if(y > 500 && direction == DOWN)
    {
        while(direction == DOWN)
         {
             direction = rand() % 4;
         }
    }
    if(y < 50 && direction == UP)
    {
        while(direction == UP)
         {
             direction = rand() % 4;
         }
    }
    if(direction == RIGHT)
        x += 20;
    if(direction == LEFT)
        x -= 20;
    if(direction == UP)
        y -= 20;
    if(direction == DOWN)
        y += 20;

}
void People::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{

/*
selectClip % 3
    if (id == 1) {
         p = 8;
    }
    if (id==2)
    {

        p = 5;
    }
    */
    if(direction == RIGHT)
        spriteSheetTexture -> Render( x, y, width, height, &character1[selectClip % 3 + 6], 0.0, NULL, SDL_FLIP_NONE, gRenderer);
    if(direction == LEFT)
        spriteSheetTexture -> Render( x, y, width, height, &character1[selectClip % 3 + 3], 0.0, NULL, SDL_FLIP_NONE, gRenderer);
    if(direction == UP)
        spriteSheetTexture -> Render( x, y, width, height, &character1[selectClip % 1 + 9], 0.0, NULL, SDL_FLIP_NONE, gRenderer);
    if(direction == DOWN)
        spriteSheetTexture -> Render( x, y, width, height, &character1[selectClip % 3], 0.0, NULL, SDL_FLIP_NONE, gRenderer);

    selectClip += 1;
}
People::~People()
{
    //dtor
}
