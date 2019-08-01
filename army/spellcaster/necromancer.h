#pragma once

#include "spellcaster.h"
#include "../ability/necromancerability.h"
#include "../observer/observeble.h"


class Necromancer : public SpellCaster, public Observeble
{
public:
    Necromancer( std::string name, Point point, std::string * output );
    virtual ~Necromancer();

    virtual void attackEnemy(Unit * enemy);
    virtual void counterAttack(Unit * enemy);
    virtual void update();
};

