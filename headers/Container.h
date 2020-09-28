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

            void setContent(std::vector<Tile>);
            std::vector<Tile> getContent();
            Tile getFront();
            void addTile(Tile);
            void removeColor(Colors);
            void removeFront();
            bool empty();
            int size();
            int findColor(Colors);

        protected:
            std::vector<Tile> content;
    };
};
#endif