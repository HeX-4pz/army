#pragma once

#include "unit.h"
#include "../ability/werewolfability.h"
#include "../attack/werewolfattack.h"

class Werewolf : public Unit
{
public:
    Werewolf(std::string name, Point point, std::string * output);
    virtual ~Werewolf();

};


std::ostream& operator<<(std::ostream& out, const Werewolf& werewolf);

