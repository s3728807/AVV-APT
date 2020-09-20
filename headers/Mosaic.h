#ifndef MOSAIC
#define MOSAIC

#include <iostream>
#include "Tile.h"

namespace Azul
{
    class Mosaic
    {
        public:
            Mosaic();
            ~Mosaic();
        private:
        Tile **wall;
        Tile *patternLine;
    };
};
#endif