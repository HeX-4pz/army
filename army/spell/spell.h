#pragma once

#include "../unit/unit.h"

class Spell
{
    
protected:
    int power;
    int cost;
    std::string name;
    
public:
    Spell();
     virtual ~Spell();
    
    virtual void cast( Unit *);
    int getCost() const;
    int getPower() const;

    void setPower(int power);
    virtual std::string getName();
    
};

