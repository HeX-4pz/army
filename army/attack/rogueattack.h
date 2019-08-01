#pragma once
#include "attack.h"


class RogueAttack : public Attack
{
public:
    RogueAttack(Unit * owner);
    virtual ~RogueAttack();

    virtual void attack(Unit * enemy);
};

