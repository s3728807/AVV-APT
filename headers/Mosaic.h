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

            Tile **getWall();
            Tile *patternLine();

            void setWall(Tile**);
            void setPatternLine(Tile*);
            
        private:
        Tile **wall;
        Tile *patternLine;
    };
};
#endif