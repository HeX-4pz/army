#include "demon.h"

Demon::Demon(std::string name, Unit *owner, Point point, std::string * output) : Unit(name, point, output) {
    this->master = owner;
    state->setLimitHP(int(UNITHP::DEMON));
    state->setHP(getLimitHP());
    state->setDamge(int(UNITDMG::DEMON));
    state->setClassName("Demon");
    this->movePoints = int(UNITMOVE::DEMON);

}

Demon::~Demon(){}

