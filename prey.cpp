#include "prey.h"

Prey::Prey(int x, int y, int turn) : Creature(x,y,turn)
{
    creatureCode = 'O';
}

Prey::~Prey()
{}

void Prey::Reproduce(Board &board, int turn)
{
    const int REPRODUCTION_CYCLE = 3;

    int turnsSinceReproducing = turn - turnOfLastReproduce;
    if(turnsSinceReproducing>=REPRODUCTION_CYCLE)
    {
        int tryCount = 0;
        int tryDirection = rand()%4; // 0:up, 1:right, 2:down, 3:left
        int newX, newY;

        bool reproduced = false;
        while(tryCount < 4 && !reproduced)
        {
            NewCoords(newX, newY, tryDirection);
            if(board.IsValid(newX, newY) && !board.IsOccupied(newX, newY))
            {
                board.Get(newX, newY) = new Prey(newX, newY, turn);
                reproduced = true;
            }
            else
            {
                ++tryCount;
                tryDirection = (tryDirection + 1) % 4;
            }
        }

        turnOfLastReproduce = turn;
    }
}
