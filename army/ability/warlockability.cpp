#include "warlockability.h"

WarlockAbility::WarlockAbility(Warlock *owner) : MagicAbility(owner) {
    magicOwner->changeSpell("fireball");
}

WarlockAbility::~WarlockAbility() {}

void WarlockAbility::castSpell(Unit *unit) {
    if ( magicOwner->spendMN(currentSpell->getCost()) ) {
        int previosPower = currentSpell->getPower();
        currentSpell->setPower(previosPower / 2);
        currentSpell->cast(unit);
        currentSpell->setPower(previosPower);
    }
}

void WarlockAbility::use(Unit * placeForDemon) {
    if (magicOwner->spendMN(100)) {
        placeForDemon = new Demon("Demonnn_" + owner->getName(),  magicOwner, owner->getLocation(), owner->getOutput());
    }

}
