#include "attack.h"

Attack::Attack( Unit * owner) : owner(owner) {}

Attack::~Attack() {}

void Attack::attack(Unit *enemy) {
    enemy->takeDamage(owner->getDamage());
    try {
        enemy->counterAttack(owner);
    } catch (unitIsDead obj) { }
}

void Attack::counterAttack(Unit *enemy) {
    enemy->takeDamage(owner->getDamage() / 2);
}

