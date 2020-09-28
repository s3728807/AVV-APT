#include "../headers/Container.h"

using namespace Azul;

Container::Container()
{}

Container::~Container()
{}

std::vector<Tile> Container::getContent()
{
    return content;
}

Tile Container::getFront()
{
    return content.at(0);
}

void Container::addTile(Tile t)
{
    content.push_back(t);
}

void Container::removeColor(Colors c)
{
    for (unsigned int x = 0; x<content.size();x++)
    {
        if (content.at(x).getColor()==c)
        {
            content.erase(content.begin()+x);
        }
    }
}

void Container::removeFront()
{
    content.erase(content.begin());
}

bool Container::empty()
{
    return content.empty();
}

void Container::setContent(std::vector<Tile> v)
{
    content = v;
}

int Container::size()
{
    return content.size();
}

int Container::findColor(Colors c)
{
    int count = 0;
    for (unsigned int x = 0; x<content.size();x++)
    {
        if (content.at(x).getColor()==c)
        {
            count++;
        }
    }

    return count;
}