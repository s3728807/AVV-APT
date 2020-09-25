#include "../headers/Factory.h"

using namespace Azul;

Factory::Factory()
{}

Factory::~Factory()
{}

bool Factory::missingTiles()
{
    return content.size() < 4;
}