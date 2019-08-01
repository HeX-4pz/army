#ifndef WARLOCK_H
#define WARLOCK_H

#include "spellcaster.h"
#include "../ability/warlockability.h"

class Warlock : public  SpellCaster
{
public:
    Warlock(std::string name, Point point, std::string * output);
    virtual ~Warlock();


};

std::ostream& operator<<(std::ostream& out, const Warlock& );

#endif // WARLOCK_H
