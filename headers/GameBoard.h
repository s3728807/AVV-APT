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

            void setPlayers(LinkedList*);
            void setBag(Bag*);
            void setFactories(Factory*);

            void newGame(std::string, std::string);
            void refillBag(Container*);
            bool emptyFactories();
            bool emptyDump();
            void refillFactories();
            void addFirstTile();
            void factory2Mosaic(int, Colors, int);
            void factory2Dump(int);
            void patternLine2Wall();
            void clearFloors();
            int penalty();

        private:
            LinkedList *playersList;
            Bag *bag;
            Factory *factories;
    };
};
#endif