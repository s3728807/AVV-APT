#ifndef PATTERNLINE
#define PATTERNLINE

#include <iostream>
#include "Container.h"

namespace Azul
{
    class PatternLine : public Container
    {
        public:
            PatternLine();
            PatternLine(int);
            ~PatternLine();

            void setMax(int);
            int getMax();
            bool isFull();
            Tile at(int);

        private:
            int max;
    };
};
#endif