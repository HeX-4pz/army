#include "state.h"


State::State(std::string name) : name(name) {
}

State::State(std::string name, std::string className, int HP, int DMG, int limitHP)
{
    this->name = name;
    this->className = className;
    this->HP = HP;
    this->DMG = DMG;
    this->limitHP = limitHP;
}


State::~State() {
}

void State::setDamge(int damage) {
    if ( damage < 0 ) {
        std::cout << "Cannot set negative damage" << std::endl;
        return;
    }
    this->DMG = damage;

}

void State::setHP(int hp) {
    if ( hp > this->limitHP ) {
        std::cout << "Cannot set hp bigger limit" << std::endl;
        return;
    }
    this->HP = hp;
}

void State::setLimitHP(int limitHP) {
    if ( limitHP < 0 ) {
        std::cout << "Cannot set negative limit HP" << std::endl;
        return;
    }
    this->limitHP = limitHP;
}

void State::setClassName(std::string className)
{
    this->className = className;
}

void State::addHP(int hp) {
    int result = this->HP + hp;

    if( result > this->limitHP ) {
        this->HP = this->limitHP;
        return;
    }

    this->HP = result;
}

int State::getHP() const {
    return this->HP;
}

int State::getDamage() const {
    return this->DMG;
}

int State::getLimitHP() const {
    return this->limitHP;
}

const std::string State::getName() const {
    return this->name;
}

const std::string State::getClassName() const
{
    return className;
}

int State::takeDamage( int damage ) {
    int result = HP - damage;
    
    if ( HP == 0 ) {
      std::cout << "Init alredy dead" << std::endl;
      return 0;
    }
    
    if ( result < 0 ) {
      std::cout << " Init die!" << std::endl;
      HP = 0;
      return damage - HP;
    }
    
    HP -= damage;
    std::cout << name << " take damage = " << damage << std::endl;
    return damage;
}

int State::takeMagicDamage(int damage)
{
    int result = HP - damage;

    if ( HP == 0 ) {
      std::cout << "Init alredy dead" << std::endl;
      return 0;
    }

    if ( result < 0 ) {
      std::cout << " Init die!" << std::endl;
      HP = 0;
      return damage - HP;
    }

    HP -= damage;
    std::cout << name << " take damage = " << damage << std::endl;
    return damage;
}

