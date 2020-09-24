#include "../headers/Mosaic.h"

using namespace Azul;

Mosaic::Mosaic()
{
    wall = new Tile*[GRID_SIZE];
    for (int i = 0; i < GRID_SIZE; i++)
    {
        wall[i] = new Tile[GRID_SIZE];
        for (int j = 0; j < GRID_SIZE; j++)
        {
            wall[i][j] = Tile();
        }
    }

    patternLine = new PatternLine[GRID_SIZE];
    for (int i = 0; i < GRID_SIZE; i++)
    {
        patternLine[i].setMax(i+1);
    }
}

Mosaic::~Mosaic()
{
    delete wall;
    delete[] patternLine;
}

void Mosaic::fillWall()
{
    Colors c = DARKBLUE;
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j <GRID_SIZE; j++)
        {
            wall[i][j] = c;
            if (j<4)
            {
                c = nextColor(c);
            }
        }
    }

}

Colors Mosaic::nextColor(Colors c)
{
    Colors ret = UNDEF;
    if (c == RED)
    {
        ret = BLACK;
    }
    else if (c == BLACK)
    {
        ret = LIGHTBLUE;
    }
    else if (c == LIGHTBLUE)
    {
        ret = DARKBLUE;
    }
    else if (c == DARKBLUE)
    {
        ret = YELLOW;
    }
    else if (c == YELLOW)
    {
        ret = RED;
    }
    return ret;
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