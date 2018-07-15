#include "TrashCan.h"

TrashCan::TrashCan(LTexture* image, int x, int y)
{
    spriteSheetTexture = image;

    spriteClip.x = 36;
    spriteClip.y = 267;
    spriteClip.w = 96 - 36;
    spriteClip.h = 360 - 267;

    width = spriteClip.w;
    height = spriteClip.h;
   this-> x = x;
   this -> y = y;
   collider.x = this->x;
   collider.y = this->y;
   collider.w = width;
   collider.h = height;

}
void TrashCan::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{

        spriteSheetTexture -> Render( x, y, width, height, &spriteClip, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
        if( debug == true )
    {
        SDL_Rect rect = { x, y, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }

}

int TrashCan::Get_id()
{
    return trashCan;
}
bool TrashCan::checkCollision(SDL_Rect& a)
{

}
void TrashCan::SetDirection(int direction)
{

}
void TrashCan::Move()
{

}

void TrashCan::SetDestination(int x, int y)
{

}
TrashCan::~TrashCan()
{
    //dtor
}
