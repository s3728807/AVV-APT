#include "../headers/Tile.h"

using namespace Azul;

Tile::Tile()
{
    color = UNDEF;
    placed = false;
}

Tile::Tile(Colors c)
{
    color = c;
    placed = false;
}

Tile::~Tile()
{}

void Tile::setColor(Colors c)
{
    color = c;
}

void Tile::setPlaced(bool b)
{
    placed = b;
}

Colors Tile::getColor()
{
    return color;
}

bool Tile::isPlaced()
{
    return placed;
}