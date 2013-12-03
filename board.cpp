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
    for(int xx=0; xx<width; xx++)
    {
        creatureGrid[xx] = new Creature*[width];

        for(int yy=0; yy<height; yy++)
            creatureGrid[xx][yy] = NULL;
    }
}

void Board::Delete()
{
    for(int xx=0; xx<width; xx++)
    {
        for(int yy=0; yy<height; yy++)
            delete creatureGrid[xx][yy];

        delete[] creatureGrid[xx];
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

    for(int xx=0; xx<width; xx++)
        for(int yy=0; yy<height; yy++)
        {
            creatureGrid[xx][yy] = other.creatureGrid[xx][yy]->Clone();
        }

    return *this;
}

Board::~Board()
{
    Delete();
}

Creature*& Board::Get(int x, int y)
{
    if(!IsValid(x,y))
    {
        cout<<"Error: Board::Get() called with bad x & y...\n\n";
        exit(1);
    }
    return creatureGrid[x][y];
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
    int zzMax = width*2+1;
    for(int zz=0; zz<zzMax; zz++)
        cout<<"-";
    cout<<endl;

    for(int yy=0; yy<height; yy++)
    {
        cout<<'|';
        for(int xx=0; xx<width; xx++)
        {
            if(creatureGrid[xx][yy]==NULL)
                cout<<" |";
            else
                cout<<*creatureGrid[xx][yy]<<'|';
        }

        cout<<endl;
        for(int zz=0; zz<zzMax; zz++)
            cout<<"-";
        cout<<endl;
    }
}

bool Board::IsValid(int x, int y)
{
    return x>=0 && x<width && y>=0 && y<height;
}

bool Board::IsOccupied(int x, int y)
{
    if(!IsValid(x,y))
    {
        cout<<"Error: Board::IsOccupied() called on bad x & y...\n\n";
        exit(1);
    }

    if(Get(x,y)!=NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
