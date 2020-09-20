#ifndef LINKEDLIST
#define LINKEDLIST

#include <iostream>
#include "Player.h"

namespace Azul
{
    class LinkedList
    {
        public:
            Player *p;
            LinkedList();
            ~LinkedList();

            int size();
            void clear();
            int get(int i);

            void addFront(int data);
            void addBack(int data);

            void deleteFront();
            void deleteBack();
        private:
            Player* head;
    };
};

#endif