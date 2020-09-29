#ifndef GAMEBOARD
#define GAMEBOARD

#include <iostream>
#include "LinkedList.h"
#include "Bag.h"
#include "Factory.h"

namespace Azul
{
    class GameBoard
    {
        public:
            GameBoard();
            ~GameBoard();

            LinkedList *getPlayers();
            Bag *getBag();
            Factory *getFactories();
            int getRandom();

            void setPlayers(LinkedList*);
            void setBag(Bag*);
            void setFactories(Factory*);
            void setRandom(int);

            void newGame(std::string, std::string);
            void refillBag();
            bool emptyFactories();
            bool emptyDump();
            void refillFactories();
            void addFirstTile();
            void factory2Mosaic(int, Colors, int);
            void factory2Dump(int);

        private:
            LinkedList *playersList;
            Bag *bag;
            Factory *factories;
            int random;
    };
};
#endif