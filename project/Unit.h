#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include"LTexture.h"
#include"Point.h"
#include"math.h"

using namespace std;




class Unit
{
    protected:
        bool Alive;
        int x;
        int y;
        int width;
        int height;
        //int direction;
        SDL_Rect collider;

        LTexture* spriteSheetTexture;

        enum id{people, truck, garbage, trashCan};
        //enum MOTION {RIGHT, LEFT, UP, DOWN, STILL};

    public:

        virtual ~Unit();
        //void SetAlive(bool);
        bool GetAlive();
        int GetWidth();
        int GetHeight();
        int GetX();
        int GetY();
        SDL_Rect& getCollider();
        virtual void SetDestination(int x, int y) = 0;
        virtual int Get_id() = 0;
        virtual bool checkCollision(SDL_Rect& a) = 0;
        virtual void SetDirection(int direction) = 0;
        virtual void Move() = 0;
        virtual void Render(long int& frame, SDL_Renderer* gRenderer, bool debug) = 0;
};




