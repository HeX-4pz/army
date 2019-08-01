#include "healer.h"

Healer::Healer(std::string name, Point point, std::string * output) :
    SpellCaster(name, point, output) {
    delete magicAbility;

    magicAbility = new HealerAbility(this);
    magicAbility->setCurrentSpell(spellBook->getSpell("heal"));
    state->setLimitHP(int(UNITHP::HEALER));
    state->setHP(getLimitHP());
    state->setDamge(int(UNITDMG::HEALER));
    magicState->setLimitMN(int(UNITMN::HEALER));
    magicState->setMN(getLimitMN());
    state->setClassName("Healer");
    this->movePoints = int(UNITMOVE::HEALER);

}

Healer::~Healer() {}

std::ostream& operator<<(std::ostream& out, const Healer& healer) {
    out << "Class:  " << healer.getClassName() << "\n"
        << "Name:   "  << healer.getName()    << "\n"
        << "HP:     "  << healer.getHP()      << "\n"
        << "Damage: "  << healer.getDamage()  << "\n"
        << "MaxHP:  "  << healer.getLimitHP() << "\n"
        << "MN:     " << healer.getMN()      << "\n"
        << "MaxMN:  "  << healer.getLimitMN() << "\n";

    return out;
}
