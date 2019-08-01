#include "fireball.h"

FireBall::FireBall() : BattleSpell () {
    this->power = 30;
    this->cost = 10;
    name = "fireball";
}

FireBall::~FireBall() {}

void FireBall::cast( Unit * unit ) {
    unit->takeDamage(this->power);
}
