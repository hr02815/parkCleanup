#include "People.h"



People::People(LTexture* image)
{

    Alive = true;
    active = false;
    //this->x = x;
    //this->y = y;
    int way = rand() %4;
    cout<<way<<endl;
    if(way == 0)
    {
        x = 0;
        y = rand() % SCREEN_HEIGHT;
        direction = 0;
    }
    if(way == 1)
    {
        x = SCREEN_WIDTH ;
        y = rand() % SCREEN_HEIGHT;
        direction = 1;
    }
    if(way == 2)
    {
        x = rand() %SCREEN_WIDTH;
        y = SCREEN_HEIGHT ;
        direction = 2;
    }
    if(way == 3)
    {
        x = rand() %SCREEN_WIDTH;
        y = 0;
        direction = 3;
    }
    cout<<x<<"  "<<y<<endl;
    cout<<direction<<endl;
    //selectClip = 0;
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
    collider.x = x;
    collider.y = y;
    collider.w = width;
    collider.h = height;



}

void People::Move()
{
    //direction = rand() % 4;

    /*
    if(direction == LEFT)
    {
        x -= 5;
        collider.x = x;
        if( ( x < 10 ) || ( x + width > SCREEN_WIDTH ) || checkCollision(  wall ) )
            {
                x += 5;
                collider.x = x;
            }
    }
    if(direction == RIGHT)
    {
        x += 5;
        collider.x = x;
        if( ( x < 10 ) || ( x + width > SCREEN_WIDTH ) || checkCollision(  wall ) )
            {
                x -= 5;
                collider.x = x;
            }
    }
    if(direction == UP)
    {
        y -= 5;
        collider.x = x;
        if( ( y < 10 ) || ( y + height > SCREEN_HEIGHT ) || checkCollision(  wall ) )
            {
                y += 5;
                collider.y = y;
            }
    }
    if(direction == DOWN)
    {
        y += 5;
        collider.y = y;
        if( ( y < 10 ) || ( y + height > SCREEN_HEIGHT ) || checkCollision(  wall ) )
            {
                y -= 5;
                collider.y = y;
            }
    }
/*
        while(direction == LEFT)
         {
             direction = rand() % 4;
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
    */
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
         x += 5;
         collider.x = x;
     }
    if(direction == LEFT)
     {
        x -= 5;
        collider.x = x;
     }
    if(direction == UP)
    {
        y -= 5;
        collider.y = y;
    }

    if(direction == DOWN)
     {
         y += 5;
        collider.y = y;
     }


}

void People::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    //spriteSheetTexture -> Render( x, y, width, height, &character1[11], 0.0, NULL, SDL_FLIP_NONE, gRenderer);
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
        spriteSheetTexture -> Render( x, y, width, height, &character1[frame % 3 + 6], 0.0, NULL, SDL_FLIP_NONE, gRenderer);
    if(direction == LEFT)
        spriteSheetTexture -> Render( x, y, width, height, &character1[frame % 3 + 3], 0.0, NULL, SDL_FLIP_NONE, gRenderer);
    if(direction == UP)
        spriteSheetTexture -> Render( x, y, width, height, &character1[frame % 1 + 9], 0.0, NULL, SDL_FLIP_NONE, gRenderer);
    if(direction == DOWN)
        spriteSheetTexture -> Render( x, y, width, height, &character1[frame % 3], 0.0, NULL, SDL_FLIP_NONE, gRenderer);

    //selectClip += 1;

}

bool People::checkCollision( SDL_Rect& a)
{

    if(direction == LEFT)
        x -= 5;
    if(direction == RIGHT)
        x += 5;

    collider.x = x;

    if(direction == UP)
        y -= 5;
    if(direction == DOWN)
        y += 5;

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
        x += 5;
    if(direction == RIGHT)
        x -= 5;

    collider.x = x;

    if(direction == UP)
        y += 5;
    if(direction == DOWN)
        y -= 5;

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

/*
SDL_Rect& People::getCollider()
{
    return collider;
}
*/
void People::SetDirection(int direction)
{
    this-> direction = direction;
}
/*
bool People::GetAlive()
{
    return Alive;
}
*/
int People::Get_id()
{
    return people;
}
People::~People()
{
    cout<<"\npeople destroyed";
}
