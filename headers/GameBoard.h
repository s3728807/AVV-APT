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
            int getRandom();

            void setPlayers(LinkedList*);
            void setBox(BoxLid*);
            void setBag(Bag*);
            void setFactories(Factory*);
            void setRandom(int);

            void newGame(std::string, std::string);
            void refillBag();
            bool emptyFactories();
            bool emptyDump();
            void refillFactories();

        private:
            LinkedList *playersList;
            BoxLid *box;
            Bag *bag;
            Factory *factories;
            int random;
    };
};
#endif