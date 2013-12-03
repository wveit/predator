#ifndef BOARD_H
#define BOARD_H

#include <cstdlib>
#include <iostream>
#include "creature.h"
using std::cout;
using std::endl;

class Creature;

class Board
{
public:
    Board();
    Board(int newHeight, int newWidth);

    Board(const Board &other);
    Board& operator=(const Board &other);
    ~Board();

    Creature*& Get(int x, int y);
    int Height();
    int Width();
    void BlankGrid();
    void Delete();
    void Print();
    bool IsValid(int x, int y);
    bool IsOccupied(int x, int y);

private:
    Creature ***creatureGrid;
    int height;
    int width;
};

#endif // BOARD_H
