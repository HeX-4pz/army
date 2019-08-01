#include "werewolf.h"

Werewolf::Werewolf(std::string name, Point point, std::string * output) : Unit(name, point, output)
{
    delete  ability;
    delete attack;
    ability = new WerewolfAbility(this);
    attack = new WerewolfAttack(this);
    state->setLimitHP(int(UNITHP::WEREWOLF));
    state->setHP(getLimitHP());
    state->setDamge(int(UNITDMG::WEREWOLF));
    state->setClassName("Werewolf");
    this->movePoints = int(UNITMOVE::WEREWOLF);
}

Werewolf::~Werewolf() {}

std::ostream& operator<<(std::ostream& out, const Werewolf& werewolf) {
    out << "Class:   " << werewolf.getClassName() << "\n"
        << "Name:    " << werewolf.getName()      << "\n"
        << "HP:      " << werewolf.getHP()        << "\n"
        << "Damage:  " << werewolf.getDamage()    << "\n"
        << "MaxHP:   " << werewolf.getLimitHP()   << "\n";

    return out;
}
