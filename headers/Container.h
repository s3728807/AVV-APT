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

            std::vector<Tile> get();
            void addTile(Tile);
            void removeColor(Colors);
            void removeFront();
            bool empty();

        protected:
            std::vector<Tile> content;
    };
};
#endif