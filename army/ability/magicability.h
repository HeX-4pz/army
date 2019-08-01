#pragma once

#include "../spellcaster/spellcaster.h"
#include "../spell/spell.h"
#include "ability.h"

class SpellCaster;

class MagicAbility : public Ability
{

protected:
    SpellCaster * magicOwner;
    Spell * currentSpell;

public:
    MagicAbility( SpellCaster * owner );
    virtual ~MagicAbility();

    
    virtual void castSpell( Unit * unit );
    void setCurrentSpell( Spell * spell);
    virtual std::string getCurrentSpell();
    SpellCaster * getOwner();
    int getManaCost();
};
