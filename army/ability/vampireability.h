#pragma once

#include "ability.h"
#include "werewolfability.h"
#include "../unit/vampire.h"
#include "../attack/vampireattack.h"

class WerewolfAbility;
class VampireAttack;

class VampireAbility : public Ability
{

public:
    VampireAbility(Unit * owner);
    virtual ~VampireAbility();

    void makeVampire(Unit *);

};

