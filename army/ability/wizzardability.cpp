#include "wizzardability.h"

WizzardAbility::WizzardAbility(Wizard *owner) : MagicAbility(owner) {
    magicOwner->changeSpell("fireball");
}

WizzardAbility::~WizzardAbility() {}

void WizzardAbility::castSpell(Unit *unit) {
    if ( magicOwner->spendMN(currentSpell->getCost()) ) {
        if ( dynamic_cast<HealingSpell * >(currentSpell) ) {
            int previosPower = currentSpell->getPower();
            currentSpell->setPower(previosPower / 2);
            currentSpell->cast(unit);
            currentSpell->setPower(previosPower);
        } else {
            currentSpell->cast(unit);
        }
    }
}
