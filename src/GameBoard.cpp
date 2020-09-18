#include "../headers/GameBoard.h"

using namespace Azul;

GameBoard::GameBoard()
{
    playersList = new LinkedList();
    box = new BoxLid();
    factories = new Factory[6];
    bag = new Bag();
};

GameBoard::~GameBoard()
{
    delete box;
    delete bag;
    delete playersList;
    delete[] factories;
};