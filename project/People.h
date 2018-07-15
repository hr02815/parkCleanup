#ifndef PEOPLE_H
#define PEOPLE_H
#include"LTexture.h"
#include "Unit.h"

using namespace std;

enum MOTION {RIGHT, LEFT, UP, DOWN, STILL};

class People: public Unit
{
    public:
        People();
        People(LTexture* image);
        void Move();
        void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);
        bool checkCollision(SDL_Rect& a);
        virtual ~People();
        void SetDirection(int direction);
        int Get_id();



    protected:

    private:
        //int x;
        //int y;
        //int width;
        //int height;
        int direction;
        //long int selectClip;
        bool active;
        //bool Alive;
        //SDL_Rect collider;
        SDL_Rect character1[12];
        SDL_Rect character2[12];
        SDL_Rect character3[12];
        SDL_Rect character4[12];

        //LTexture* spriteSheetTexture;
};

#endif // PEOPLE_H
