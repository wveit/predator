#ifndef BOARD_H
#define BOARD_H

#include <cstdlib>
#include <iostream>
#include "creature.h"
using std::cout;
using std::endl;

class Board
{
public:
    Board();
    Board(int newHeight, int newWidth);

    Board(const Board &other);
    Board& operator=(const Board &other);
    ~Board();

    Creature *Get(int h, int w);
    int Height();
    int Width();
    void BlankGrid();
    void Delete();
    void Print();

private:
    Creature ***creatureGrid;
    int height;
    int width;
};

#endif // BOARD_H
