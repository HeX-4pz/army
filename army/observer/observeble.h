#ifndef OBSERVEBLE_H
#define OBSERVEBLE_H


class Observeble
{
public:
    Observeble();
    virtual ~Observeble();

    virtual void update() = 0;
};

#endif // OBSERVEBLE_H
