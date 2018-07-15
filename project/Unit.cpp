#include "Unit.h"


bool Unit::GetAlive()
{
    return Alive;
}
int Unit::GetWidth()
{
    return width;
}
int Unit::GetHeight()
{
    return height;
}
int Unit::GetX()
{
    return x;
}
int Unit::GetY()
{
    return y;
}
SDL_Rect& Unit::getCollider()
{
    collider.x = x;
    collider.y = y;
    collider.w = width;
    collider.h = height;
    return collider;
}

/*
int Unit::Get_id()
{

}


*/
Unit::~Unit()
{
    cout<<"\nUnit destructor";
}


