#include "spell.h"

Spell::Spell() : power(0), cost(0) {
    name = "spell";
}

Spell::~Spell() {}

void Spell::cast( Unit * unit ) {
    unit->takeDamage(this->power);
}

int Spell::getCost() const {
    return cost;
}

int Spell::getPower() const {
    return power;
}

void Spell::setPower(int power)
{
    this->power = power;
}

std::string Spell::getName()
{
    return name;
}
