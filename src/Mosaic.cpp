#include "../headers/Mosaic.h"

using namespace Azul;

Mosaic::Mosaic()
{
    wall = new Tile*[5];
    for (int i = 0; i < 5; i++)
    {
        wall[i] = new Tile[5];
        for (int j = 0; j < 5; j++)
        {
            wall[i][j] = Tile();
        }
    }

    patternLine = new PatternLine[5];
}

Mosaic::~Mosaic()
{
    delete wall;
    delete[] patternLine;
}

void Mosaic::setPatternLine(PatternLine *p)
{
    patternLine = p;
}

void Mosaic::setWall(Tile **w)
{
    wall = w;
}

PatternLine *Mosaic::getPatternLine()
{
    return patternLine;
}

Tile **Mosaic::getWall()
{
    return wall;
}