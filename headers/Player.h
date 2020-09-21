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
            
            void setName(std::string);
            void setPoints(int);
            void setFloor(Floor*);
            void setMosaic(Mosaic*);
            
        private:
            std::string name;
            int points;
            Floor *floor;
            Mosaic *mosaic;

    };
};
#endif
