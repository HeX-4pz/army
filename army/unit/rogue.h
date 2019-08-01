#pragma once
#include "unit.h"
#include "../attack/rogueattack.h"


class Rogue : public Unit
{
public:
    Rogue(std::string name, Point point, std::string * output);
    virtual ~Rogue();

};

std::ostream& operator<<(std::ostream& out, const Rogue& rogue);

