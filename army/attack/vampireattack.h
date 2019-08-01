#pragma once

#include "attack.h"
#include "../ability/vampireability.h"

class VampireAbility;

class VampireAttack : public Attack
{
public:
    VampireAttack(Unit * owner);
    virtual ~VampireAttack();

    virtual void attack(Unit *);
    virtual void counterAttack(Unit *);
};

