#include "../headers/LinkedList.h"

using namespace Azul;

LinkedList::LinkedList()
{}

LinkedList::~LinkedList()
{}

void LinkedList::addPlayer(Player* p)
{
    if (head == nullptr)
    {
        head = p;
    }
    else
    {
        head->next = p;
    }
}