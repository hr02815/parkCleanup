#pragma once
#include "People.h"

struct Node
{
    People* people;
    Node* next;
    Node* prev;

    ~Node()
    {
        delete people;
    }
};
