#include "spellbook.h"

SpellBook::SpellBook()
{
    spels.insert(std::pair<std::string, Spell *> ("fireball", new FireBall()));
    spels.insert(std::pair<std::string, Spell *> ("heal", new Heal()));
    spels.insert(std::pair<std::string, Spell *> ("lightning", new Lightning()));
}

SpellBook::~SpellBook() {
    for (auto it = spels.begin(); it != spels.end(); ++it) {
        delete (*it).second;
    }
}

Spell * SpellBook::getSpell(std::string spellName) {
    return spels[spellName];
}

std::map<std::string, Spell *> SpellBook::getBook()
{
    return spels;
}
