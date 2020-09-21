#include "../headers/GameBoard.h"

using namespace Azul;

GameBoard::GameBoard()
{
    playersList = new LinkedList();
    box = new BoxLid();
    factories = new Factory[6];
    bag = new Bag();
}

GameBoard::~GameBoard()
{
    delete box;
    delete bag;
    delete playersList;
    delete[] factories;
}

void GameBoard::setBag(Bag *b)
{
    bag = b;
}

void GameBoard::setBox(BoxLid *b)
{
    box = b;
}

void GameBoard::setFactories(Factory *f)
{
    factories = f;
}

void GameBoard::setPlayers(LinkedList *p)
{
    playersList = p;
}

void GameBoard::setRandom(int r)
{
    random = r;
}

Bag *GameBoard::getBag()
{
    return bag;
}

BoxLid *GameBoard::getBox()
{
    return box;
}

Factory *GameBoard::getFactories()
{
    return factories;
}

LinkedList *GameBoard::getPlayers()
{
    return playersList;
}

int GameBoard::getRandom()
{
    return random;
}