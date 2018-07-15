#ifndef TRUCK_H
#define TRUCK_H
#include "Unit.h"



class Truck : public Unit
{
    public:
        Truck(LTexture* image);
        virtual int Get_id();
        virtual bool checkCollision(SDL_Rect& a);
        virtual void SetDirection(int direction);
         virtual void Move();
         virtual void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);
         virtual void SetDestination(int x, int y);
        virtual ~Truck();

    protected:

    private:
        int direction;
        bool active;
        SDL_Rect spriteClip;
        Point destination;

        enum MOTION {RIGHT, LEFT, UP, DOWN, STILL};
};

#endif // TRUCK_H
