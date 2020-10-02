#include "../headers/Bag.h"

using namespace Azul;

Bag::Bag()
{}

Bag::~Bag()
{}

void Bag::fill()
{
    for (int x = 0; x < NUM_TILES; x++)
    {
        for (int color = RED; color!=UNDEF; color++)
        {
            Colors c = (Colors) color;
            Tile t = Tile(c);
            addTile(t);
        }
    }
}