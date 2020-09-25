#ifndef FACTORY
#define FACTORY

#include <iostream>
#include "Container.h"

namespace Azul
{
    class Factory : public Container
    {
        public:
            Factory();
            ~Factory();

            bool missingTiles();
    };
};
#endif