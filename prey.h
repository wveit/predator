#ifndef PREY_H
#define PREY_H

#include "creature.h"

class Prey:public Creature
{
public:
    Prey(int x, int y, int turn);
    virtual ~Prey();
    virtual void Reproduce(Board &board, int turn);

};

#endif // PREY_H
