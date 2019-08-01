#pragma once

#include "../unit/unit.h"

class Unit;

class Ability
{

protected:
    Unit * owner;
    
public:
    Ability(Unit * owner);
    virtual ~Ability();

    virtual void use();
    virtual void use(Unit *);

};

