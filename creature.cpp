#include "creature.h"

Creature::Creature(int x, int y): creatureCode('C'), coordX(x), coordY(y), turnOfLastMove(0)
{
}

Creature::~Creature()
{}

Creature *Creature::Clone() const
{
    Creature *temp = new Creature(*this);
    return temp;
}

ostream& operator<<(ostream &out, const Creature &creature)
{
    out<<creature.creatureCode;

    return out;
}

void Creature::SetCode(char code)
{
    creatureCode = code;
}

char Creature::GetCode()
{
    return creatureCode;
}

void Creature::NewCoords(int &newX, int &newY, int tryDirection)
{
    newX = coordX;
    newY = coordY;

    switch(tryDirection)
    {
        case 0:
            newY -= 1;
            break;
        case 1:
            newX += 1;
            break;
        case 2:
            newY += 1;
            break;
        case 3:
            newX -= 1;
            break;
    }
}

void Creature::Move(Board &board, int turn)
{
    if(turnOfLastMove == turn)
        return;

    int tryCount = 0;
    int tryDirection = rand()%4; // 0:up, 1:right, 2:down, 3:left
    int newX, newY;

    bool moved = false;
    while(tryCount < 4 && !moved)
    {
        NewCoords(newX, newY, tryDirection);
        if(board.IsValid(newX, newY) && !board.IsOccupied(newX, newY))
        {
            board.Get(newX, newY) = board.Get(coordX, coordY);
            board.Get(coordX, coordY) = NULL;
            coordX = newX;
            coordY = newY;
            moved = true;
        }
        else
        {
            ++tryCount;
            tryDirection = (tryDirection + 1) % 4;
        }
    }

    turnOfLastMove = turn;
}

void Creature::SetX(int newX)
{
    coordX = newX;
}

int Creature::GetX()
{
    return coordX;
}

void Creature::SetY(int newY)
{
    coordY = newY;
}

int Creature::GetY()
{
    return coordY;
}
