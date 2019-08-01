#pragma once
#include "unit.h"

class Soldier : public Unit
{
public:
    Soldier(std::string name, Point point, std::string * output);
    virtual ~Soldier();
};

std::ostream& operator<<(std::ostream& out, const Soldier& soldier);
