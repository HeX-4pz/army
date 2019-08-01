#include "vampireattack.h"

VampireAttack::VampireAttack(Unit * owner) : Attack (owner)
{

}

VampireAttack::~VampireAttack() {}

void VampireAttack::attack(Unit * enemy)
{
    int lifeSteal = enemy->takeDamage(owner->getDamage());
    if ( !dynamic_cast<Undead*>(enemy) ) {
        owner->addHP( lifeSteal * 7 / 10);
    }

    dynamic_cast<VampireAbility * > (owner->getAbility())->makeVampire(enemy);
    try {
        enemy->counterAttack(owner);
    } catch (unitIsDead obj) { }
}

void VampireAttack::counterAttack(Unit * enemy) {
    int lifeSteal = enemy->takeDamage(owner->getDamage() / 2);
    if ( !dynamic_cast<Undead*>(enemy) ) {
        owner->addHP( lifeSteal * 7 / 10);
    }
}
