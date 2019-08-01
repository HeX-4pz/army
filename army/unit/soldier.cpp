#include "soldier.h"

Soldier::Soldier(std::string name, Point point, std::string * output) : Unit(name, point, output) {
    state->setLimitHP(int(UNITHP::SOLDIER));
    state->setHP(getLimitHP());
    state->setDamge(int(UNITDMG::SOLDIER));
    state->setClassName("Soldier");
    this->movePoints = int(UNITMOVE::SOLDIER);

}

Soldier::~Soldier() {

}

std::ostream& operator<<(std::ostream& out, const Soldier& soldier) {
    out << "Class:   " << soldier.getClassName() << "\n"
        << "Name:    " << soldier.getName()      << "\n"
        << "HP:      " << soldier.getHP()        << "\n"
        << "Damage:  " << soldier.getDamage()    << "\n"
        << "MaxHP:   " << soldier.getLimitHP()   << "\n";
    return out;
}
