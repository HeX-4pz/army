#pragma once

#include <iostream>

class MagicState
{
    
    int MN;
    int limitMN;
    
public:
    MagicState();
    ~MagicState();

    void setLimitMN( int limit);
    void setMN( int mn);
    
    int getMN() const;
    int getLimitMN() const;
    void addMN( int );
    bool spendMN ( int );
    
};

