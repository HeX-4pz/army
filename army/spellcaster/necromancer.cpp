#include "necromancer.h"

Necromancer::Necromancer(std::string name, Point point, std::string * output) :
        SpellCaster(name, point, output) {
    delete magicAbility;
    magicAbility = new NecromancerAbility(this);
    magicAbility->setCurrentSpell(spellBook->getSpell("fireball"));
    state->setLimitHP(int(UNITHP::NECROMACER));
    state->setHP(getLimitHP());
    state->setDamge(int(UNITDMG::NECROMACER));
    magicState->setLimitMN(int(UNITMN::NECROMACER));
    magicState->setMN(getLimitMN());
    state->setClassName("Necromancer");
    this->movePoints = int(UNITMOVE::NECROMACER);
}

Necromancer::~Necromancer() {}

void Necromancer::attackEnemy(Unit *enemy) {
    ensureIsAlive();
    enemy->ensureIsAlive();

    attack->attack(enemy);
    enemy->addToObserveSet(this);
}

void Necromancer::counterAttack(Unit *enemy) {
    ensureIsAlive();
    enemy->ensureIsAlive();

    attack->counterAttack(enemy);
    enemy->addToObserveSet(this);
}

void Necromancer::update() {
    ensureIsAlive();
    addHP(50);
}

std::ostream& operator<<(std::ostream& out, const Necromancer& necromancer) {
    out << "Class:  " << necromancer.getClassName() << "\n"
        << "Name:   " << necromancer.getName()    << "\n"
        << "HP:     " << necromancer.getHP()      << "\n"
        << "Damage: " << necromancer.getDamage()  << "\n"
        << "MaxHP:  " << necromancer.getLimitHP() << "\n"
        << "MN:     " << necromancer.getMN()      << "\n"
        << "MaxMN:  " << necromancer.getLimitMN() << "\n";

    return out;
}
