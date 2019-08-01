#pragma once

#include "../unit/unit.h"
#include "../state/magicstate.h"
#include "../ability/magicability.h"
#include "../spell/spellbook.h"

class MagicAbility;

class SpellCaster : public Unit
{

protected:
    MagicState * magicState;
    MagicAbility * magicAbility;
    SpellBook * spellBook;
    
public:
    SpellCaster(std::string name, Point point, std::string * output);
    virtual ~SpellCaster();
    
    int getMN() const;
    int getLimitMN() const;
    void addMN( int );
    bool spendMN ( int );
    void cast( Unit * );
    void changeSpell( std::string spellName);
    std::string getCurrentSpell();
    int getManaCost();
    SpellBook* getSpellBook();
    
};

