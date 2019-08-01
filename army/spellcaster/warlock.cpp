#include "warlock.h"

Warlock::Warlock(std::string name, Point point, std::string * output) :
    SpellCaster(name, point, output) {
    delete magicAbility;
    magicAbility = new WarlockAbility(this);
    magicAbility->setCurrentSpell(spellBook->getSpell("fireball"));
    state->setLimitHP(int(UNITHP::WARLOCK));
    state->setHP(getLimitHP());
    state->setDamge(int(UNITDMG::WARLOCK));
    magicState->setLimitMN(int(UNITMN::WARLOCK));
    magicState->setMN(getLimitMN());
    state->setClassName("Warlock");
    this->movePoints = int(UNITMOVE::WARLOCK);
}

Warlock::~Warlock() {}

std::ostream& operator<<(std::ostream& out, const Warlock& warlock) {
    out << "Class:  " << warlock.getClassName() << "\n"
        << "Name:   " << warlock.getName()    << "\n"
        << "HP:     " << warlock.getHP()      << "\n"
        << "Damage: " << warlock.getDamage()  << "\n"
        << "MaxHP:  " << warlock.getLimitHP() << "\n"
        << "MN:     " << warlock.getMN()      << "\n"
        << "MaxMN:  " << warlock.getLimitMN() << "\n";

    return out;
}
