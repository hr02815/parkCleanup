#ifndef TRASHCAN_H
#define TRASHCAN_H
#include "Unit.h"


class TrashCan: public Unit
{
    public:

        TrashCan(LTexture* image, int x, int y);
        virtual void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);
        virtual int Get_id();
        virtual bool checkCollision(SDL_Rect& a);
        virtual void SetDirection(int direction);
        virtual void Move();
        virtual void SetDestination(int x, int y);
        virtual ~TrashCan();

    protected:

    private:
        SDL_Rect spriteClip;
};

#endif // TRASHCAN_H
