#include "wizard.h"

Wizard::Wizard(std::string name, Point point, std::string * output) :
    SpellCaster(name, point, output) {
    delete magicAbility;
    magicAbility = new WizzardAbility(this);
    magicAbility->setCurrentSpell(spellBook->getSpell("fireball"));
    state->setLimitHP(int(UNITHP::WIZARD));
    state->setHP(getLimitHP());
    state->setDamge(int(UNITDMG::WIZARD));
    magicState->setLimitMN(int(UNITMN::WIZARD));
    magicState->setMN(getLimitMN());
    state->setClassName("Wizard");
    this->movePoints = int(UNITMOVE::WIZARD);
}

Wizard::~Wizard() {}

std::ostream& operator<<(std::ostream& out, const Wizard& wizard) {
    out << "Class:  " << wizard.getClassName() << "\n"
        << "Name:   " << wizard.getName()    << "\n"
        << "HP:     " << wizard.getHP()      << "\n"
        << "Damage: " << wizard.getDamage()  << "\n"
        << "MaxHP:  " << wizard.getLimitHP() << "\n"
        << "MN:     " << wizard.getMN()      << "\n"
        << "MaxMN:  " << wizard.getLimitMN() << "\n";

    return out;
}
