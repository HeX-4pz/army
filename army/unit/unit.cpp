#include "unit.h"


Unit::Unit(std::string name,  Point point, std::string * output) {
    this->location = point;
    this->output = output;
    state = new State(name);
    ability = new Ability(this);
    attack = new Attack(this);

    state->setLimitHP(int(UNITHP::UNIT));
    state->setHP(getLimitHP());
    state->setDamge(int(UNITDMG::UNIT));
    state->setClassName("Unit");
    this->movePoints = int(UNITMOVE::UNIT);
}

Unit::~Unit() {
    delete state;
    delete ability;
    delete attack;
}

void Unit::attackEnemy(Unit * enemy) {
    ensureIsAlive();
    enemy->ensureIsAlive();

    int wasEnemy = enemy->getHP();
    attack->attack(enemy);
    int nowEnemy = enemy->getHP();
    *output += this->getClassName() + " " + this->getName() + " attack " + enemy->getClassName() + " " + enemy->getName()
            + " caused damage " + std::to_string(wasEnemy-nowEnemy)  + "\n";
}

void Unit::counterAttack(Unit * enemy) {
    ensureIsAlive();
    enemy->ensureIsAlive();

    int wasEnemy = enemy->getHP();
    attack->counterAttack(enemy);
    int nowEnemy = enemy->getHP();

    *output += this->getClassName() + " " + this->getName() + " counter attack " + enemy->getClassName() + " " + enemy->getName()
            + " caused damage " + std::to_string(wasEnemy-nowEnemy)  + "\n";
}

int Unit::takeDamage(int damage) {
    ensureIsAlive();

    int takedDamage = state->takeDamage( damage );

    try {
        ensureIsAlive();
    } catch (unitIsDead obj) {
        *output += this->getClassName() + " " + this->getName() + " unit die \n";
        signalToObservebles();
    }

    return takedDamage;


}

int Unit::takeMagicDamage(int damage) {
    ensureIsAlive();

    return state->takeMagicDamage( damage );
}

void Unit::addHP(int hp) {
    ensureIsAlive();

    int wasHp = this->getHP();
    state->addHP(hp);
    int nowHp = this->getHP();

    *output += this->getClassName() + " " + this->getName() + " was healed to " + std::to_string(nowHp-wasHp)  + " HP\n";
}

int Unit::getDamage() const {
    return this->state->getDamage();
}

const std::string Unit::getName() const {
    return this->state->getName();
}

const std::string Unit::getClassName() const {
    return this->state->getClassName();
}

int Unit::getHP() const {
    return this->state->getHP();
}

void Unit::setAbility(Ability *newAbility) {
    delete ability;
    ability = newAbility;
}

void Unit::setState(State *newState) {
    delete  state;
    state = newState;
}

void Unit::setAttack(Attack *newAttack) {
    delete attack;
    attack = newAttack;
}

void Unit::setMovePoints(int newPoints) {
    movePoints = newPoints;
}

void Unit::setLocation(Point point) {
    this->location = point;
}

void Unit::useAbility() {
    ensureIsAlive();

    ability->use();
}

void Unit::ensureIsAlive() {
    if (state->getHP() == 0) {
        throw unitIsDead();
    }
}

std::string *Unit::getOutput() {
    return output;
}

int Unit::getLimitHP() const {
    return this->state->getLimitHP();
}

int Unit::getMovePoints() const
{
    return this->movePoints;
}

Ability *Unit::getAbility() {
    return ability;
}

Attack *Unit::getAttack() {
    return attack;
}

Point Unit::getLocation() {
    return location;
}

std::ostream& operator<<(std::ostream& out, const Unit& unit) {
    out << "Class:   " << unit.getClassName() << "\n"
        << "Name:    " << unit.getName()      << "\n"
        << "HP:      " << unit.getHP()        << "\n"
        << "Damage:  " << unit.getDamage()    << "\n"
        << "MaxHP:   " << unit.getLimitHP()   << "\n";
    
    return out;
}


