#include "necromancerability.h"

NecromancerAbility::NecromancerAbility(Necromancer *owner) : MagicAbility (owner) {
    magicOwner->changeSpell("fireball");
}

NecromancerAbility::~NecromancerAbility() {}

void NecromancerAbility::castSpell(Unit *unit) {
    if ( magicOwner->spendMN(currentSpell->getCost()) ) {
        int previosPower = currentSpell->getPower();
        currentSpell->setPower(previosPower / 2);
        currentSpell->cast(unit);
        currentSpell->setPower(previosPower);
    }
}
