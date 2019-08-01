#pragma once

#include "magicability.h"
#include "../spellcaster/necromancer.h"
class Necromancer;

class NecromancerAbility : public MagicAbility
{
public:
    NecromancerAbility( Necromancer * owner);
    virtual ~NecromancerAbility();

    virtual void castSpell(Unit *);
};

