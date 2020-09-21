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

            LinkedList *getPlayers();
            BoxLid *getBox();
            Bag *getBag();
            Factory *getFactories();

            void setPlayers(LinkedList*);
            void setBox(BoxLid*);
            void setBag(Bag*);
            void setFactories(Factory*);

        private:
            LinkedList *playersList;
            BoxLid *box;
            Bag *bag;
            Factory *factories;
    };
};
#endif