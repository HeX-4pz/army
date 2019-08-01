#pragma once

#include <iostream>
#include <string>
#include "atributes.h"

class State
{
    std::string name;
    std::string className;
    
    int HP;
    int DMG;
    
    int limitHP;
    
public:
    State(std::string name);
    State(std::string name, std::string className, int HP, int DMG, int limitHP);
    ~State();

    void setDamge( int damage);
    void setHP( int hp);
    void setLimitHP( int limitHP);
    void setClassName (std::string className);
    
    void addHP( int hp );

    int getHP() const ;
    int getDamage() const ;
    const std::string getName() const ;
    const std::string getClassName() const ;
    int getLimitHP() const ;

    int takeDamage( int );
    int takeMagicDamage( int );
    
};

