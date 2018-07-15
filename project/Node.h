#pragma once
#include "People.h"
#include "Truck.h"


struct Node
{
    Unit* unit;
    Node* next;
    Node* prev;

    ~Node()
    {
        delete unit;
    }
};
