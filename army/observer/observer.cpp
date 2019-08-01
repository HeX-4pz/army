#include "observer.h"

Observer::Observer()
{

}

Observer::~Observer()
{

}

void Observer::addToObserveSet(Observeble * pObserveble) {
    observerSet.insert(pObserveble);
}

void Observer::removeFromObservebleSet(Observeble * pObserveble) {
    observerSet.erase(pObserveble);
}

void Observer::signalToObservebles() {
    for ( std::set<Observeble*>::iterator it = observerSet.begin(); it != observerSet.end(); ++it ) {
        (*it)->update();
    }
}

