#pragma once

#include "unit.h"

class Berserker : public Unit
{
public:
    Berserker(std::string name, Point point, std::string * output);
    virtual ~Berserker();

    virtual int takeMagicDamage( int damage);
};

std::ostream& operator<<(std::ostream& out, const Berserker& berserker);
