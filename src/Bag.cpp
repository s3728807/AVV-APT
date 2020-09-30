#include "../headers/Bag.h"

using namespace Azul;

Bag::Bag()
{}

Bag::~Bag()
{}

void Bag::fill()
{
    for (int color = RED; color!=UNDEF; color++)
    {
        for (int x = 0; x < NUM_TILES; x++)
        {
            Colors c = (Colors) color;
            Tile t = Tile(c);
            addTile(t);
        }
    }
}

void Bag::shuffle(int s)
{
    srand(s);
    int total = 5*NUM_TILES;
    for (int i = 0; i < total; i++)
    {
        Tile temp = content.at(i);
        Tile& a = content.at(i);
        Tile& b = content.at(rand()%(total-1));
        a = b;
        b = temp;
    }
}