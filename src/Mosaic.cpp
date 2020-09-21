#include "../headers/Mosaic.h"

using namespace Azul;

Mosaic::Mosaic()
{}

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