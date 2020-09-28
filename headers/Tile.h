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
        UNDEF,
        F
    };

    class Tile
    {
        public:
            Tile();
            Tile(Colors);
            ~Tile();

            Colors getColor();
            bool isPlaced();

            void setColor(Colors);
            void setPlaced(bool);
            
        private:
            Colors color;
            bool placed;

    };
};
#endif