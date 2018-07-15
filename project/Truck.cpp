#include "Truck.h"

Truck::Truck(LTexture* image)
{
    Alive = true;
    active = false;
    spriteClip.x = 185 ;
    spriteClip.y = 54;
    spriteClip.w = 232 -185;
    spriteClip.h = 96 - 54;

    //int spawn = rand() %4;
    int spawn = 1;
    if(spawn == 0)
    {
        x = 0;
        y = rand() % SCREEN_HEIGHT;
        direction = 0;
    }
    if(spawn == 1)
    {
        x = SCREEN_WIDTH ;
        y = rand() % SCREEN_HEIGHT;
        direction = 1;
    }
    if(spawn == 2)
    {
        x = rand() %SCREEN_WIDTH;
        y = SCREEN_HEIGHT ;
        direction = 2;
    }
    if(spawn == 3)
    {
        x = rand() %SCREEN_WIDTH;
        y = 0;
        direction = 3;
    }

    spriteSheetTexture = image;

    width = spriteClip.w;
    height = spriteClip.h;

    collider.x = x;
    collider.y = y;
    collider.w = width;
    collider.h = height;

}
void Truck::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    if(direction == RIGHT)
        spriteSheetTexture -> Render( x, y, width, height, &spriteClip, 0.0, NULL, SDL_FLIP_HORIZONTAL, gRenderer);
    if(direction == LEFT)
        spriteSheetTexture -> Render( x, y, width, height, &spriteClip, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
    if(direction == UP)
        spriteSheetTexture -> Render( x, y, width, height, &spriteClip, 90.0, NULL, SDL_FLIP_NONE, gRenderer);
    if(direction == DOWN)
        spriteSheetTexture -> Render( x, y, width, height, &spriteClip, 270.0, NULL, SDL_FLIP_NONE, gRenderer);

    if( debug == true )
    {
        SDL_Rect rect = { x, y, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }

}
bool Truck::checkCollision(SDL_Rect& a)
{
    if(direction == LEFT)
        x -= 2;
    if(direction == RIGHT)
        x += 2;

    collider.x = x;

    if(direction == UP)
        y -= 2;
    if(direction == DOWN)
        y += 2;

    collider.y = y;

    int leftA;
    int rightA;
    int topA;
    int bottomA;

    int leftB;
    int rightB;
    int topB;
    int bottomB;

    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    leftB = collider.x;
    rightB = collider.x + collider.w;
    topB = collider.y;
    bottomB = collider.y + collider.h;

    if(direction == LEFT)
        x += 2;
    if(direction == RIGHT)
        x -= 2;

    collider.x = x;

    if(direction == UP)
        y += 2;
    if(direction == DOWN)
        y -= 2;

    collider.y = y;

    if( bottomA <= topB )
        return false;

    if( topA >= bottomB )
        return false;

    if( rightA <= leftB )
        return false;

    if( leftA >= rightB )
        return false;

    return true;
}
void Truck::SetDirection(int direction)
{
    this-> direction = direction;
}
void Truck::Move()
{
    if(x > 0 && x < SCREEN_WIDTH && y > 0 && y < SCREEN_HEIGHT )
    {
        active = true;
    }
    if(active)
    {
        if(x < 0 || x > SCREEN_WIDTH || y < 0 || y > SCREEN_HEIGHT)
            Alive = false;
    }
    if(direction == RIGHT)
     {
         x += 2;
         collider.x = x;
     }
    if(direction == LEFT)
     {
        x -= 2;
        collider.x = x;
     }
    if(direction == UP)
    {
        y -= 2;
        collider.y = y;
    }

    if(direction == DOWN)
     {
        y += 2;
        collider.y = y;
     }

     int distance = 0;
     int lowestDistance = 0;
     distance = sqrt(pow(x - destination.x,2));
     cout<<distance<<endl;
     if( (int)distance > 2 && distance > 30 )
     {
         cout<<"\nleft,right";
         x += 5;
         distance = sqrt( pow ( x - destination.x, 2 ) + pow( y - destination.y, 2 ) );
         direction = RIGHT;
         lowestDistance = distance;
         x-= 5;

         x-=5;
         distance = sqrt( pow ( x - destination.x, 2 ) + pow( y - destination.y, 2 ) );
         if(distance < lowestDistance)
         {
             lowestDistance = distance;
             direction = LEFT;
         }
         x+=5;
     }

    else
    {
         cout<<"\nup,down";
         y+=5;
         distance = sqrt( pow ( x - destination.x, 2 ) + pow( y - destination.y, 2 ) );
         //if(distance < lowestDistance)
         //{
             lowestDistance = distance;
             direction = DOWN;
         //}
         y-=5;

         y-=5;
         distance = sqrt( pow ( x - destination.x, 2 ) + pow( y - destination.y, 2 ) );
         if(distance < lowestDistance)
         {
             lowestDistance = distance;
             direction = UP;
         }
         y+=5;

    }

}

void Truck::SetDestination(int x, int y)
{
    destination.x = x;
    destination.y = y;
}

int Truck::Get_id()
{
    return truck;
}
Truck::~Truck()
{
    cout<<"\nTruck destructor";
}
