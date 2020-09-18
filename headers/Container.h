#ifndef CONTAINER
#define CONTAINER

#include <iostream>
#include <vector>
#include "Tile.h"

namespace Azul
{
    class Container
    {
        public:
            Container();
            ~Container();

        protected:
            std::vector<Tile> content;
    };
};
#endif