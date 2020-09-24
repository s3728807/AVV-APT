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
