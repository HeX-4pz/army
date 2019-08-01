#include "rogueattack.h"

RogueAttack::RogueAttack(Unit * owner) : Attack (owner)
{

}

RogueAttack::~RogueAttack() {}

void RogueAttack::attack(Unit *enemy)
{
    enemy->takeDamage(owner->getDamage());
}
