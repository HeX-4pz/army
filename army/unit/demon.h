#ifndef DEMON_H
#define DEMON_H

#include "unit.h"

class Demon : public Unit
{
    Unit * master;
public:
    Demon(std::string name, Unit * owner, Point point, std::string * output);
    virtual ~Demon();
};

std::ostream& operator<<(std::ostream& out, const Demon& demon);

#endif // DEMON_H
