#pragma once

#include "battlespell.h"

class Lightning : public BattleSpell
{
public:
    Lightning();
    virtual ~Lightning();

    virtual void cast( Unit * enemy);
};

#include "battlespell.h"
