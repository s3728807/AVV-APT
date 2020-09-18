#ifndef GAMEENGINE
#define GAMEENGINE

#include <iostream>
#include "GameBoard.h"
#include "UserInterface.h"

namespace Azul
{
    class GameEngine
    {
        public:
            GameEngine();
            ~GameEngine();
            
            void run();
            void menu();
        
        private:
            GameBoard *board;
            UserInterface *ui;
    };
};

#endif