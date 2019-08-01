#pragma once
#include <iostream>
#include "../state/state.h"
#include "../ability/ability.h"
#include "../attack/attack.h"
#include "../exception/exceptions.h"
#include "../observer/observer.h"
#include "../point.h"


class State;
class Ability;
class Attack;

class Unit : public Observer {


protected:
    State * state;
    Ability * ability;
    Attack * attack;
    int movePoints;
    std::string * output;
    Point location;
    
public:
    Unit(std::string name, Point location, std::string * output);
    virtual ~Unit();
    
    virtual void attackEnemy(Unit * enemy);
    virtual void counterAttack(Unit * enemy);
    virtual int takeDamage(int damage);
    virtual int takeMagicDamage(int damage);
    
    void addHP(int hp);
    int getDamage() const ;
    const std::string getName() const ;
    const std::string getClassName() const ;
    int getHP() const ;
    int getLimitHP() const ;
    int getMovePoints() const;
    Ability * getAbility();
    Attack * getAttack();
    Point getLocation();

    void setAbility(Ability * newAbility);
    void setState(State * newState);
    void setAttack(Attack * newAttack);
    void setMovePoints(int newPoints);
    void setLocation(Point point);


    void useAbility();

    void ensureIsAlive();

    std::string * getOutput();
    
};

std::ostream& operator<<(std::ostream& out, const Unit& unit);

