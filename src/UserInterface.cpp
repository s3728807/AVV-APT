#include "../headers/UserInterface.h"

using namespace Azul;

UserInterface::UserInterface() {
    

}

UserInterface::~UserInterface() {

}

void UserInterface::print(std::string input) {

    std::cout << input << std::endl;
    
}

std::string UserInterface::input() {
    std::string input;
    std::cout << "> ";
    getline(std::cin, input);
    return input;
}

std::string UserInterface::printFactory(std::vector<Tile> v)
{
    std::string str;
    for (Tile t:v)
    {
        if (t.getColor() == RED)
        {   
            str.append("R ");
        }
        else if (t.getColor() == LIGHTBLUE)
        {
            str.append("L ");
        }
        else if (t.getColor() == DARKBLUE)
        {
            str.append("B ");
        }
        else if (t.getColor() == BLACK)
        {
            str.append("U ");
        }
        else if (t.getColor() == YELLOW)
        {
            str.append("Y ");
        }
    }

    return str;
}

std::string UserInterface::printPatternLine(PatternLine* p)
{
    //std::cout<<"printPatternLine"<<std::endl;
    std::string str;
    for (int i = 5; i>0; i--)
    {
        str.append(" ");
        if (i>p->getMax())
        {
            str.append(" ");
        }
        else
        {
            if (i>p->size() || p->size() == 0)
            {
                str.append(".");
            }
            else if (p->at(i).getColor() == RED)
            {
                str.append("R");
            }
            else if ((p->at(i).getColor() == YELLOW))
            {
                str.append("Y");
            }
            else if ((p->at(i).getColor() == BLACK))
            {
                str.append("U");
            }
            else if ((p->at(i).getColor() == DARKBLUE))
            {
                str.append("B");
            }
            else if ((p->at(i).getColor() == LIGHTBLUE))
            {
                str.append("L");
            }
        }
        
    }

    return str;
}

std::string UserInterface::printWall(Tile* t)
{
    std::string output;
    std::string str;
    char c;
    for (int i = 0; i < 5; i++)
    {
        if (t[i].getColor() == RED)
        {
            str = "R";
        }
        else if ((t[i].getColor() == YELLOW))
        {
            str = "Y";
        }
        else if ((t[i].getColor() == BLACK))
        {
            str = "U";
        }
        else if ((t[i].getColor() == DARKBLUE))
        {
            str = "B";
        }
        else if ((t[i].getColor() == LIGHTBLUE))
        {
            str = "L";
        }
        if (!t[i].isPlaced())
        {
            c = str[0];
            str = (::tolower(c));
        }
        output.append(str).append(" ");
    }

    return output;
}