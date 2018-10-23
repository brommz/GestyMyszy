#ifndef WARSTWAWEJSCIOWA_H
#define WARSTWAWEJSCIOWA_H

#include "definicje.h"
#include "Warstwa.h"
#include "NeuronWejsciowy.h"

class WarstwaWejsciowa : public Warstwa
{
public:
    WarstwaWejsciowa(const uint ileNeuronow);
    virtual ~WarstwaWejsciowa();
    virtual void dodajWejscia(const std::vector<real>wejscia);

protected:

private:
    WarstwaWejsciowa(const WarstwaWejsciowa& cos);
    WarstwaWejsciowa& operator=(const WarstwaWejsciowa& cos);
};

#endif // WARSTWAWEJSCIOWA_H
