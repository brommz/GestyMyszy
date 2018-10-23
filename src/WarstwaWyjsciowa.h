#ifndef WARSTWAWYJSCIOWA_H
#define WARSTWAWYJSCIOWA_H

#include "definicje.h"
#include "Warstwa.h"
#include "NeuronWyjsciowy.h"

class WarstwaWyjsciowa : public Warstwa
{
public:
    WarstwaWyjsciowa(const uint ileNeuronow);
    virtual ~WarstwaWyjsciowa();
    virtual std::vector<real> wynik();

protected:

private:
    WarstwaWyjsciowa(const WarstwaWyjsciowa& cos);
    WarstwaWyjsciowa& operator=(const WarstwaWyjsciowa& cos);
};

#endif // WARSTWAWYJSCIOWA_H
