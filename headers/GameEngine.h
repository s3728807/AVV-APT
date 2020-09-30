#ifndef GAMEENGINE
#define GAMEENGINE

#include <iostream>
#include "GameBoard.h"
#include "UserInterface.h"
#include <sstream>

namespace Azul
{
    class GameEngine
    {
        public:
            GameEngine();
            ~GameEngine();
            
            void run();
            void menu();
            void introducePlayers();
            void factoryCheck();
            void findPlayerTurn();
            void printFactory();
            void printMosaic();
            bool playerAction();
            bool validTurn(int, char, int);
            bool validColor(char);
            Colors char2Col(char);
            void endOfRound();
            std::vector<std::string> parseLine(std::string, char);
        
        private:
            GameBoard *board;
            UserInterface *ui;
            int roundCounter;
            bool hasQuit;
    };
};

#endif