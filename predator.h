#ifndef PREDATOR_H
#define PREDATOR_H

#include "creature.h"

class Predator:public Creature
{
public:
    Predator(int x, int y, int turn);
    virtual ~Predator();

    void Eat(Board &board, int turn);
    virtual void Move(Board &board, int turn);
    virtual void DieOrLive(Board &board, int turn);
    virtual void Reproduce(Board &board, int turn);

private:
    int turnOfLastMeal;
};

#endif // PREDATOR_H
