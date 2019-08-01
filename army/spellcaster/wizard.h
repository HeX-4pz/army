#pragma once

#include "spellcaster.h"
#include "../ability/wizzardability.h"

class Wizard : public SpellCaster
{
public:
    Wizard(std::string name, Point point, std::string * output);
    virtual ~Wizard();

};

std::ostream& operator<<(std::ostream& out, const Wizard& wizard);

