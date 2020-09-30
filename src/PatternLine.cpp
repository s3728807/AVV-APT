#include "../headers/PatternLine.h"

using namespace Azul;

PatternLine::PatternLine()
{}

PatternLine::PatternLine(int s)
{
    max = s;
}

PatternLine::~PatternLine()
{}

bool PatternLine::matchesTile(Tile t)
{
    return t.getColor() == getFront().getColor();
}

void PatternLine::setMax(int i)
{
    max = i;
}

int PatternLine::getMax()
{
    return max;
}

bool PatternLine::isFull()
{
    return content.size() == (unsigned)max;
}

Tile PatternLine::at(int i)
{
    return content.at(i);
}