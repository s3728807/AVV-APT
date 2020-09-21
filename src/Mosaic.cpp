#include "../headers/Mosaic.h"

using namespace Azul;

Mosaic::Mosaic()
{}

Mosaic::~Mosaic()
{
    delete wall;
    delete[] patternLine;
}

