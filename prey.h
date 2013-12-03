#ifndef PREY_H
#define PREY_H

#include "creature.h"

class Prey:public Creature
{
public:
    Prey(int x, int y);
    virtual ~Prey();

};

#endif // PREY_H
