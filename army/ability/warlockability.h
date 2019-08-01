#pragma once

#include "magicability.h"
#include "../unit/demon.h"
#include "../spellcaster/warlock.h"

class Warlock;
class WarlockAbility : public MagicAbility
{
public:
    WarlockAbility(Warlock * owner);
    virtual ~WarlockAbility();

    virtual void castSpell( Unit *);
    virtual void use(Unit * placeForDemon);

};

