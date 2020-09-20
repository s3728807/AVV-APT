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
        private:
            std::string name;
            int points;
            Floor *floor;
            Mosaic *mosaic;

    };
};
#endif
