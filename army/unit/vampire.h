#pragma once
#include "unit.h"

#include "../ability/vampireability.h"
#include "../attack/vampireattack.h"
#include "undead.h"


class Vampire : public Unit, public Undead
{
public:
    Vampire(std::string name, Point point, std::string * output);
    virtual ~Vampire();

    virtual int takeDamage(int damage);

};

std::ostream& operator<<(std::ostream& out, const Vampire& vampire);

