#pragma once

#include "attack.h"
#include "../ability/werewolfability.h"

class WerewolfAttack : public Attack
{
public:
    WerewolfAttack(Unit *);
    virtual ~WerewolfAttack();

    virtual void attack(Unit * enemy);

};

