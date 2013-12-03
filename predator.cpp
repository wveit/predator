#include "predator.h"

Predator::Predator(int x, int y) : Creature(x,y), turnOfLastMeal(0)
{
    creatureCode = 'X';
}

Predator::~Predator()
{}

void Predator::Eat(Board &board, int turn)
{
    if(turnOfLastMove==turn)
        return;
    
    int tryCount = 0;
    int tryDirection = rand()%4; // 0:up, 1:right, 2:down, 3:left
    int newX, newY;

    bool moved = false;
    while(tryCount < 4 && !moved)
    {
        NewCoords(newX, newY, tryDirection);
        if(board.IsValid(newX, newY) && board.Get(newX, newY)!=NULL && board.Get(newX, newY)->GetCode()=='O')
        {
            delete board.Get(newX, newY);
            board.Get(newX, newY) = board.Get(coordX, coordY);
            board.Get(coordX, coordY) = NULL;
            coordX = newX;
            coordY = newY;
            turnOfLastMeal = turn;
            moved = true;
        }
        else
        {
            ++tryCount;
            tryDirection = (tryDirection + 1) % 4;
        }
    }
}

void Predator::Move(Board &board, int turn)
{
    Eat(board, turn);

    Creature::Move(board, turn);
}
