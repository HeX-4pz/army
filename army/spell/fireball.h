#pragma once

#include "battlespell.h"

class FireBall : public BattleSpell
{
    
public:
    FireBall();
    virtual ~FireBall();
    
    virtual void cast( Unit * enemy);
    
};

