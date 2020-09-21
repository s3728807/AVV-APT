#ifndef MOSAIC
#define MOSAIC

#include <iostream>
#include "Tile.h"
#include "PatternLine.h"

namespace Azul
{
    class Mosaic
    {
        public:
            Mosaic();
            ~Mosaic();

            Tile **getWall();
            PatternLine *getPatternLine();

            void setWall(Tile**);
            void setPatternLine(PatternLine*);
            
        private:
        Tile **wall;
        PatternLine *patternLine;
    };
};
#endif