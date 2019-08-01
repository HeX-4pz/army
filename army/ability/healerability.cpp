#include "healerability.h"


HealerAbility::HealerAbility(Healer *owner) : MagicAbility (owner) {
    magicOwner->changeSpell("heal");
}

HealerAbility::~HealerAbility() {}

void HealerAbility::castSpell(Unit *target) {
    if (magicOwner->spendMN(currentSpell->getCost())) {
        if (dynamic_cast<BattleSpell *>(currentSpell)) {
            int currentPower = currentSpell->getPower();
            currentSpell->setPower(currentPower/2);
            currentSpell->cast(target);
            currentSpell->setPower(currentPower);
        } else {
            currentSpell->cast(target);
        }
    }
}
