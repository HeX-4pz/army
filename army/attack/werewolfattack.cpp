#include "werewolfattack.h"


WerewolfAttack::WerewolfAttack(Unit * owner) : Attack (owner)
{

}


WerewolfAttack::~WerewolfAttack() {}

void WerewolfAttack::attack(Unit * enemy) {
    enemy->takeDamage(owner->getDamage());
    dynamic_cast<WerewolfAbility *>(owner->getAbility())->makeWerewolf(enemy);
    try {
        enemy->counterAttack(owner);
    } catch (unitIsDead obj) { }
}
