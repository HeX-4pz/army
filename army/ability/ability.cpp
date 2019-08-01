#include "ability.h"


Ability::Ability( Unit * owner) :
            owner(owner) {}

Ability::~Ability() {}

void Ability::use(Unit*) {
    std::cout << "Empty ability!" << std::endl;
}

void Ability::use() {
    std::cout << "Empty ability!" << std::endl;
}
