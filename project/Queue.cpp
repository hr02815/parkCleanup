#include"Queue.h"
#include<iostream>

using namespace std;

Queue::Queue()
{
    head = NULL;
    tail = NULL;
}

Queue::~Queue()
{
    while(head != NULL)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void Queue::Enqueue(Unit* unit)
{
    if(head == NULL)
    {
        head = new Node;
        head->unit = unit;
        head->next = NULL;
        head->prev = NULL;
        tail = head;
    }
    else
    {
        tail->next = new Node;
        tail->next->unit = unit;
        tail->next->next = NULL;
        tail->next->prev = tail;
        tail = tail->next;
    }
}
/*
void Queue::Clean()
{
    Node* temp = head;
    while(temp!=NULL)
    {
        if(temp->unit->GetAlive() == false)
        {
            if(temp->prev == NULL)
            {
                head=head->next;
                if(head!=NULL)
                {
                    head->prev = NULL;
                }
                delete temp;
                temp = head;
            }
            else if(temp ->next == NULL)
            {
                tail = tail->prev;
                tail->next = NULL;
                delete temp;
                break;
            }
            else
            {
                Node* carry = temp->next;
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
                temp = carry;
            }
        }
        temp = temp->next;
    }
}
*/
void Queue::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        temp->unit->Render(frame, gRenderer, debug);
        temp=temp->next;
    }
}

void Queue::Move()
{
    //cout<<"\nqueue move";
    Node* temp = head;
    bool collision = false;
    Node* temp1 = temp;
    Node* temp2 = temp;
    int direction = 0;
    //SDL_Rect test
    while(temp!=NULL)
    {
        //cout<<"\nwhile temp!= null";
        collision = false;
        temp1 = temp->next;
        temp2 = temp->prev;
        //direction = rand() % 4;
        while(temp1!= NULL || temp2 != NULL)
        {
            //temp->unit->Move();
                //temp1->unit->getCollider()
                //cout<<"\ncheck collision next";
                if(temp1!=NULL)
                {
                    collision = temp->unit->checkCollision(temp1->unit->getCollider());
                    if(collision)
                    {
                        while(collision)
                        {
                            //cout<<"\nwhile collision next";
                            direction = rand() % 4;
                            temp->unit->SetDirection(direction);
                            collision = temp->unit->checkCollision(temp1->unit->getCollider());
                        }
                        //temp->unit->Move(direction);
                        break;
                    }
                    temp1 = temp1 ->next;
                }
                //cout<<"\nbefore check collision prev";
                if(temp2!= NULL)
                {
                    //cout<<"\nif temp2!=NULL before check collision prev";
                    collision = temp->unit->checkCollision(temp2->unit->getCollider());
                    //cout<<"\nafter check collision prev";
                    if(collision)
                    {
                        while(collision)
                        {
                           // cout<<"\nwhile collision prev";
                            direction = rand() % 4;
                            temp->unit->SetDirection(direction);
                            collision = temp->unit->checkCollision(temp2->unit->getCollider());
                        }
                        //temp->unit->Move(direction);
                        break;
                    }
                    temp2 = temp2 ->prev;
                }

                 //temp1 = temp1 ->next;
                 //temp2 = temp2 ->prev;
                 //cout<<"\nafter temp1 and temp2 next ";
        }
        temp->unit->Move();
        temp=temp->next;
    }
}
