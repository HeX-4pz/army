#ifndef OBSERVER_H
#define OBSERVER_H

#include "observeble.h"
#include <set>

class Observer
{
    std::set<Observeble*> observerSet;

public:
    Observer();
    ~Observer();

    void addToObserveSet(Observeble*);
    void removeFromObservebleSet(Observeble*);
    void signalToObservebles();

};

#endif // OBSERVER_H
