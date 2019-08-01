#include "lightning.h"


Lightning::Lightning() : BattleSpell () {
    this->power = 50;
    this->cost = 20;
    name = "lightning";
}

Lightning::~Lightning() {}

void Lightning::cast( Unit * unit ) {
    unit->takeDamage(this->power);
}
