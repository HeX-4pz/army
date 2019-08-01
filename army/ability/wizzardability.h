#pragma once

#include "magicability.h"
#include "../spellcaster/wizard.h"

class Wizard;
class WizzardAbility : public MagicAbility
{
public:
    WizzardAbility(Wizard * owner);
    virtual ~WizzardAbility();

    virtual void castSpell( Unit * unit );
};
