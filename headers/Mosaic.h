#ifndef MOSAIC
#define MOSAIC

#include <iostream>
#include "Tile.h"
#include "PatternLine.h"

#define GRID_SIZE 5

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

            void fillWall();
            Colors nextColor(Colors);
            void tileToPatternLine(int, Tile);
            void tile2Wall(int, Colors);
            
        private:
        Tile **wall;
        PatternLine *patternLine;
    };
};
#endif