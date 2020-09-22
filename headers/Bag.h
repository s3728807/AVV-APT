#ifndef BAG
#define BAG

#include <iostream>
#include "Container.h"
#include "Tile.h"

namespace Azul
{
    class Bag : public Container
    {
        public:
            Bag();
            ~Bag();
            
            void fill();
            void shuffle(int);
        private:
    };
};
#endif