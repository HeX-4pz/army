#include "heal.h"

Heal::Heal() : HealingSpell ()
{
    this->cost = 10;
    this->power = 30;
    name = "heal";
}

Heal::~Heal() {}

void Heal::cast(Unit * target) {
    target->addHP(this->power);
}
