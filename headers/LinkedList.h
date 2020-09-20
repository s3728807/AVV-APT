#ifndef LINKEDLIST
#define LINKEDLIST

#include <iostream>
#include "Player.h"

namespace Azul
{
    class LinkedList
    {
        public:
            LinkedList();
            ~LinkedList();

            Player *head;
            void addPlayer(Player*);
    };
};

#endif