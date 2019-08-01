#pragma once

#include "spellcaster.h"
#include "../ability/healerability.h"

class Healer : public SpellCaster
{
public:
    Healer(std::string name, Point point, std::string * output);
    virtual ~Healer();

};

std::ostream& operator<<(std::ostream& out, const Healer& healer);
