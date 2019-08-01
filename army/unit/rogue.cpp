#include "rogue.h"

Rogue::Rogue(std::string name, Point point, std::string * output) : Unit(name, point, output) {
    delete attack;
    attack = new RogueAttack(this);
    state->setLimitHP(int(UNITHP::ROGUE));
    state->setHP(getLimitHP());
    state->setDamge(int(UNITDMG::ROGUE));
    state->setClassName("Rogue");
    this->movePoints = int(UNITMOVE::ROGUE);

}

Rogue::~Rogue() {}

std::ostream& operator<<(std::ostream& out, const Rogue& rogue) {
    out << "Class:   " << rogue.getClassName() << "\n"
        << "Name:    " << rogue.getName()      << "\n"
        << "HP:      " << rogue.getHP()        << "\n"
        << "Damage:  " << rogue.getDamage()    << "\n"
        << "MaxHP:   " << rogue.getLimitHP()   << "\n";
    return out;
}
