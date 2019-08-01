#pragma once

#include "../unit/unit.h"

class Unit;

class Attack {
protected:
    Unit * owner;
public:
    Attack(Unit *);
    virtual ~Attack();

    virtual void attack(Unit * enemy);
    virtual void counterAttack(Unit * enemy);
};
