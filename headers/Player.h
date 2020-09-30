#ifndef PLAYER
#define PLAYER

#include <iostream>
#include "Floor.h"
#include "Mosaic.h"

namespace Azul
{
    class Player
    {
        public:
            Player();
            ~Player();
            Player *next;

            std::string getName();
            int getPoints();
            Floor *getFloor();
            Mosaic *getMosaic();
            bool isTurn();
            bool tookFirstDump();
            
            void setName(std::string);
            void setPoints(int);
            void setFloor(Floor*);
            void setMosaic(Mosaic*);
            void setTurn(bool);
            void setFirstDump(bool);
            void addPoints(int);
            void subtractPoints(int);
            
        private:
            std::string name;
            int points;
            Floor *floor;
            Mosaic *mosaic;
            bool turn;
            bool firstDump;

    };
};
#endif
