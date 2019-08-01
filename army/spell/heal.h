#pragma once

#include "healingspell.h"

class Heal : public HealingSpell
{
public:
    Heal();
    virtual ~Heal();

    virtual void cast( Unit * target);
};
