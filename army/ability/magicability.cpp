#include "magicability.h"

MagicAbility::MagicAbility( SpellCaster * owner ) : Ability (owner) {
    magicOwner = owner;
}

MagicAbility::~MagicAbility() {}
    
void MagicAbility::castSpell( Unit * unit) {
    if ( magicOwner->spendMN(currentSpell->getCost()) ) {
        currentSpell->cast(unit);
    }
}

void MagicAbility::setCurrentSpell( Spell * spell) {
    currentSpell = spell;
}

std::string MagicAbility::getCurrentSpell()
{
    return currentSpell->getName();
}

SpellCaster *MagicAbility::getOwner()
{
    return magicOwner;
}

int MagicAbility::getManaCost()
{
    return  currentSpell->getCost();
}
