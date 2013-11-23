#ifndef CREATURE_H
#define CREATURE_H

#include <cstdlib>
#include <iostream>
using std::ostream;

class Creature
{
public:
    Creature();

    virtual Creature Clone() const;
    friend ostream& operator<<(ostream &out, const Creature &creature);

protected:
    char creatureCode;

private:

};

#endif // CREATURE_H
