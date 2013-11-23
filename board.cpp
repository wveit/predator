#include "board.h"

const int DEFAULT_HEIGHT = 20;
const int DEFAULT_WIDTH = 20;

Board::Board():height(DEFAULT_HEIGHT), width(DEFAULT_WIDTH)
{
    BlankGrid();
}

Board::Board(int newHeight, int newWidth)
{
    if(newHeight<0 || newWidth<0)
    {
        width = DEFAULT_WIDTH;
        height = DEFAULT_HEIGHT;
    }
    else
    {
        width = newWidth;
        height = newHeight;
    }

    BlankGrid();
}

void Board::BlankGrid()
{
    creatureGrid = new Creature**[height];
    for(int i=0; i<height; i++)
    {
        creatureGrid[i] = new Creature*[width];

        for(int j=0; j<width; j++)
            creatureGrid[i][j]=NULL;
    }
}

void Board::Delete()
{
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
            delete creatureGrid[i][j];

        delete[] creatureGrid[i];
    }

    delete[] creatureGrid;

    width = 0;
    height = 0;
}

Board::Board(const Board &other)
{
    *this = other;
}

Board& Board::operator=(const Board &other)
{
    if(creatureGrid != NULL)
        Delete();

    width = other.width;
    height = other.height;
    BlankGrid();

    for(int i=0; i<height; i++)
        for(int j=0; j<width; j++)
        {
            *creatureGrid[i][j] = other.creatureGrid[i][j]->Clone();
        }

    return *this;
}

Board::~Board()
{
    Delete();
}

// This would be better if it returned a reference...but this would cause crash if that element was NULL ptr
// need to think of solution to this.
Creature* Board::Get(int h, int w)
{
    return creatureGrid[h][w];
}

int Board::Height()
{
    return height;
}

int Board::Width()
{
    return width;
}

void Board::Print()
{
    for(int i=0; i<height; i++)
    {
        cout<<'|';
        for(int j=0; j<width; j++)
        {
            cout<<*creatureGrid[i][j]<<'|';
        }
        cout<<endl;
    }
}
