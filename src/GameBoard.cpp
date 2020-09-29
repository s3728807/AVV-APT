#include "../headers/GameBoard.h"

using namespace Azul;

GameBoard::GameBoard()
{
    playersList = new LinkedList();
    playersList->addPlayer(new Player());
    playersList->addPlayer(new Player());
    factories = new Factory[6];
    bag = new Bag();
    srand(time(NULL));
    random = rand()%INT32_MAX;
}

GameBoard::~GameBoard()
{
    delete bag;
    delete playersList;
    delete[] factories;
}

void GameBoard::factory2Mosaic(int f, Colors c, int p)
{
    
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

void GameBoard::addFirstTile()
{
    factories->addTile(Tile(F));
}

void GameBoard::refillBag()
{
    
}

void GameBoard::refillFactories()
{
    std::vector<Tile> b;
    //iterate over all factories
    for (int i = 1;i<6;i++)
    {
        //fill a factory with 4 tiles
        while ((factories+i)->missingTiles())
        {
            //std::cout<<"missing Tiles"<<std::endl;
            b = bag->getContent();
            (factories+i)->addTile(b.front());
            bag->removeFront();
        }
    }
}

bool GameBoard::emptyFactories()
{
    return (factories+1)->empty() && (factories+2)->empty() && (factories+3)->empty() && (factories+4)->empty() && (factories+5)->empty();
}

bool GameBoard::emptyDump()
{
    return factories->empty();
}

void GameBoard::setBag(Bag *b)
{
    bag = b;
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