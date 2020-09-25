#ifndef USERINTERFACE
#define USERINTERFACE

#include <iostream>
#include <string>
#include <vector>
#include "Tile.h"
#include "PatternLine.h"

namespace Azul
{
    class UserInterface
    {
        public:
            UserInterface();
            ~UserInterface();

            void print(std::string);
            std::string input();

            std::string printFactory(std::vector<Tile>);
            std::string printPatternLine(PatternLine*);
            std::string printWall(Tile*);

        private:
    };
};
#endif