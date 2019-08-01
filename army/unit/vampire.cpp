#include "vampire.h"

Vampire::Vampire(std::string name, Point point, std::string * output) : Unit(name, point, output), Undead ()
{
    delete  ability;
    delete attack;
    attack = new VampireAttack(this);
    ability = new VampireAbility(this);
    state->setLimitHP(int(UNITHP::VAMPIRE));
    state->setHP(getLimitHP());
    state->setDamge(int(UNITDMG::VAMPIRE));
    state->setClassName("Vampire");
    this->movePoints = int(UNITMOVE::VAMPIRE);
}

Vampire::~Vampire()
{

}

int Vampire::takeDamage(int damage) {
    ensureIsAlive();

    return state->takeDamage(damage);
}



std::ostream& operator<<(std::ostream& out, const Vampire& vampire) {
    out << "Class:   " << vampire.getClassName() << "\n"
        << "Name:    " << vampire.getName()      << "\n"
        << "HP:      " << vampire.getHP()        << "\n"
        << "Damage:  " << vampire.getDamage()    << "\n"
        << "MaxHP:   " << vampire.getLimitHP()   << "\n";

    return out;
}
