#ifndef TILE
#define TILE

#include <iostream>

#define NUM_TILES 20

namespace Azul
{
    enum Colors
    {
        RED,
        LIGHTBLUE,
        BLACK,
        YELLOW,
        DARKBLUE,
        UNDEF
    };

    class Tile
    {
        public:
            Tile();
            ~Tile();

            Colors getColor();
            
        private:
            Colors color;
            bool placed;

    };
};
#endif