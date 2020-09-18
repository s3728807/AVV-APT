#ifndef GAMEBOARD
#define GAMEBOARD

#include <iostream>
#include "LinkedList.h"
#include "Bag.h"
#include "BoxLid.h"
#include "Factory.h"

namespace Azul
{
    class GameBoard
    {
        public:
            GameBoard();
            ~GameBoard();

        private:
            LinkedList *playersList;
            BoxLid *box;
            Bag *bag;
            Factory *factories;
    };
};
#endif