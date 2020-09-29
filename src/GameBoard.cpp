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

void GameBoard::factory2Mosaic(int f, Colors c, int patternLine)
{
    //std::cout<<"factory2Mosaic"<<std::endl;
    int p = patternLine - 1;
    for (Tile t:(factories+f)->getContent())
    {
        //std::cout<<"for factory content"<<std::endl;
        if (t.getColor() == c || t.getColor() == F)
        {
            //std::cout<<"if color"<<std::endl;
            //if patternline is full or if tile is First then put in floor
            if ((playersList->head->getMosaic()->getPatternLine()+p)->isFull() || t.getColor() == F)
            {
                //std::cout<<"add to floor"<<std::endl;
                playersList->head->getFloor()->addTile(t);
            }
            //else put in patternline
            else
            {
                //std::cout<<"add to patternline"<<std::endl;
                playersList->head->getMosaic()->tileToPatternLine(p, t);
            }
        }
    }
    //std::cout<<"remove color"<<std::endl;
    (factories+f)->removeColor(c);
    if (f == 0 && factories->findColor(F) == 1)
    {
        factories->removeColor(F);
    }
    
    factory2Dump(f);
    //std::cout<<"finished moving tiles"<<std::endl;
}

void GameBoard::factory2Dump(int f)
{
    if (f != 0)
    {        
        for (Tile t:(factories+f)->getContent())
        {
            //std::cout<<"move to dump"<<std::endl;
            factories->addTile(t);
        }

        while (!(factories+f)->empty())
        {
            //std::cout<<"removed tiles"<<std::endl;
            //std::cout<<(factories+f)->size()<<std::endl;
            (factories+f)->removeFront();
        }
    }
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
    //std::cout<<"emptyFact"<<std::endl;
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