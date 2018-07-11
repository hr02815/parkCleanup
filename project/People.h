#ifndef PEOPLE_H
#define PEOPLE_H
#include"LTexture.h"

using namespace std;

enum MOTION {RIGHT, LEFT, UP, DOWN};

class People
{
    public:
        People();
        People(LTexture* image, float x, float y);
        void Move();
        void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);
        virtual ~People();

    protected:

    private:
        int x;
        int y;
        int width;
        int height;
        int direction;
        long int selectClip;
        SDL_Rect character1[12];
        SDL_Rect character2[12];
        SDL_Rect character3[12];
        SDL_Rect character4[12];
        LTexture* spriteSheetTexture;
};

#endif // PEOPLE_H
