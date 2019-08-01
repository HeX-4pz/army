#pragma once

#include "ability.h"
#include "vampireability.h"
#include "../attack/werewolfattack.h"

class VampireAbility;
class WerewolfAttack;

class WerewolfAbility : public Ability
{

public:
    WerewolfAbility(Unit * owner);
    virtual ~WerewolfAbility();

    virtual void use();
    void makeWerewolf(Unit *);
};
