#include "../headers/Mosaic.h"

using namespace Azul;

Mosaic::Mosaic()
{
    wall = new Tile*[GRID_SIZE];
    for (int i = 0; i < GRID_SIZE; i++)
    {
        wall[i] = new Tile[GRID_SIZE];
        for (int j = 0; j < GRID_SIZE; j++)
        {
            wall[i][j] = Tile();
        }
    }

    patternLine = new PatternLine[GRID_SIZE];
    for (int i = 0; i < GRID_SIZE; i++)
    {
        patternLine[i].setMax(i+1);
    }
}

Mosaic::~Mosaic()
{
    delete wall;
    delete[] patternLine;
}

int Mosaic::tile2Wall(int r, Colors color)
{
    int score = 0;
    for (int c = 0; c < 5; c++)
    {
        if (wall[r][c].getColor() == color)
        {
            wall[r][c].setPlaced(true);
            score = scoring(r,c);
        }
    }
    return score;
}

int Mosaic::scoring(int row, int col)
{
    int total = 1;
    int count = row;
    while ((count-1)>=0 && wall[count-1][col].isPlaced())
    {
        total++;
        count--;
    }
    count = row;
    while ((count+1)<=4 && wall[count+1][col].isPlaced())
    {
        total++;
        count++;
    }
    count = col;
    while ((count-1)>=0 && wall[row][count-1].isPlaced())
    {
        total++;
        count++;
    }
    count = col;
    while ((count+1)<=4 && wall[row][count+1].isPlaced())
    {
        total++;
        count++;
    }

    return total;
}

void Mosaic::tileToPatternLine(int p, Tile t)
{
    patternLine[p].addTile(t);
}

void Mosaic::fillWall()
{
    Colors c = DARKBLUE;
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j <GRID_SIZE; j++)
        {
            wall[i][j] = c;
            if (j<4)
            {
                c = nextColor(c);
            }
        }
    }

}

Colors Mosaic::nextColor(Colors c)
{
    Colors ret = UNDEF;
    if (c == RED)
    {
        ret = BLACK;
    }
    else if (c == BLACK)
    {
        ret = LIGHTBLUE;
    }
    else if (c == LIGHTBLUE)
    {
        ret = DARKBLUE;
    }
    else if (c == DARKBLUE)
    {
        ret = YELLOW;
    }
    else if (c == YELLOW)
    {
        ret = RED;
    }
    return ret;
}

void Mosaic::setPatternLine(PatternLine *p)
{
    patternLine = p;
}

void Mosaic::setWall(Tile **w)
{
    wall = w;
}

PatternLine *Mosaic::getPatternLine()
{
    return patternLine;
}

Tile **Mosaic::getWall()
{
    return wall;
}