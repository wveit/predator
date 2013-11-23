#include "creature.h"

Creature::Creature(): creatureCode('C')
{
}

Creature Creature::Clone() const
{
    return *this;
}

ostream& operator<<(ostream &out, const Creature &creature)
{
    out<<creature.creatureCode;

    return out;
}
