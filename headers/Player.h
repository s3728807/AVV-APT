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
            int getPointsGained();
            int getPointsLost();
            Floor *getFloor();
            Mosaic *getMosaic();
            bool isTurn();
            bool tookFirstDump();
            int pointsLost();
            int pointsGained();
            
            void setName(std::string);
            void setPoints(int);
            void setFloor(Floor*);
            void setMosaic(Mosaic*);
            void setTurn(bool);
            void setFirstDump(bool);
            void resetPointsGainedLost();
            void addPoints(int);
            void subtractPoints(int);
            
        private:
            std::string name;
            int points;
            int pointsG;
            int pointsL;
            Floor *floor;
            Mosaic *mosaic;
            bool turn;
            bool firstDump;

    };
};
#endif
