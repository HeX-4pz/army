#pragma once

#include "magicability.h"
#include "../spellcaster/healer.h"

class Healer;
class HealerAbility : public MagicAbility
{
public:
    HealerAbility( Healer * owner);
    virtual ~HealerAbility();

    virtual void castSpell(Unit * target);

};
