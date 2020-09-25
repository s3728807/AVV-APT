#include "../headers/GameBoard.h"

using namespace Azul;

GameBoard::GameBoard()
{
    playersList = new LinkedList();
    playersList->addPlayer(new Player());
    playersList->addPlayer(new Player());
    box = new BoxLid();
    factories = new Factory[6];
    bag = new Bag();
    random = rand()%INT32_MAX;
}

GameBoard::~GameBoard()
{
    delete box;
    delete bag;
    delete playersList;
    delete[] factories;
}

void GameBoard::newGame(std::string n1, std::string n2)
{
    playersList->head->setTurn(true);
    playersList->head->setName(n1);
    playersList->head->getMosaic()->fillWall();
    playersList->head->next->setName(n2);
    playersList->head->next->getMosaic()->fillWall();
    bag->fill();
    bag->shuffle(random);
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