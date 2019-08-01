#pragma once

#include <map>
#include <string>
#include "fireball.h"
#include "heal.h"
#include "lightning.h"

class SpellBook
{
    std::map<std::string, Spell *> spels;

public:
    SpellBook();
    ~SpellBook();
    Spell * getSpell(std::string spellName);
    std::map<std::string, Spell *> getBook();
};

