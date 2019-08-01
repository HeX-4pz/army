#include "magicstate.h"

MagicState::MagicState() {}

MagicState::~MagicState() {}

void MagicState::setLimitMN(int limit) {
    if ( limit < 0 ) {
        std::cout << "Cannot set negative limit MN" << std::endl;
        return ;
    }
    this->limitMN = limit;
}

void MagicState::setMN(int mn){
    if ( mn > this->limitMN ) {
        std::cout << "Cannot set mana bigger limit" << std::endl;
        return ;
    }
    this->MN = mn;
}

int MagicState::getMN() const {
    return this->MN;
}

int MagicState::getLimitMN() const {
    return this->limitMN;
}

void MagicState::addMN( int mana) {
    int manaAfter = this->MN + mana;
    
    if ( manaAfter > this->limitMN ) {
        MN = limitMN;
        return ;
    }
    
    this->MN += mana;
}

bool MagicState::spendMN ( int mana ) {
    int manaAfter = this->MN - mana;
    
    if ( manaAfter < 0 ) {
        std::cout << "Not enough manna!" << std::endl;
        return false;
    }
    
    this->MN -= mana;
    return true;
}
