#ifndef CREATURE_H
#define CREATURE_H

#include <cstdlib>
#include <iostream>
#include "board.h"
using std::ostream;

class Board;

class Creature
{
public:
    Creature(int x, int y);
    virtual ~Creature();

    virtual Creature* Clone() const;
    friend ostream& operator<<(ostream &out, const Creature &creature);
    void SetCode(char code);
    char GetCode();
    virtual void Move(Board &board, int turn);
    void SetX(int newX);
    int GetX();
    void SetY(int newY);
    int GetY();
    void NewCoords(int &newX, int &newY, int tryDirection);

protected:
    char creatureCode;
    int coordX;
    int coordY;
    int turnOfLastMove;

private:

};

#endif // CREATURE_H
