#include "berserker.h"

Berserker::Berserker(std::string name, Point point, std::string * output) : Unit(name, point, output) {
    state->setLimitHP(int(UNITHP::BERSERKER));
    state->setHP(getLimitHP());
    state->setDamge(int(UNITDMG::BERSERKER));
    state->setClassName("Berserker");
    this->movePoints = int(UNITMOVE::BERSERKER);

}

Berserker::~Berserker()
{

}

int Berserker::takeMagicDamage(int damage) {
    std::cout << "Hahaha, Berserk laughs at your magic " << std::endl;
    return 0;
}


std::ostream& operator<<(std::ostream& out, const Berserker& berserker) {
    out << "Class:   " << berserker.getClassName() << "\n"
        << "Name:    " << berserker.getName()      << "\n"
        << "HP:      " << berserker.getHP()        << "\n"
        << "Damage:  " << berserker.getDamage()    << "\n"
        << "MaxHP:   " << berserker.getLimitHP()   << "\n";
    return out;
}
