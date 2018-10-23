#ifndef WARSTWAUKRYTA_H
#define WARSTWAUKRYTA_H

#include "definicje.h"
#include "Warstwa.h"
#include "NeuronZwykly.h"

class WarstwaUkryta : public Warstwa
{
public:
    WarstwaUkryta(const uint ileNeuronow);
    virtual ~WarstwaUkryta();

protected:

private:
    WarstwaUkryta(const WarstwaUkryta& cos);
    WarstwaUkryta& operator=(const WarstwaUkryta& cos);
};

#endif // WARSTWAUKRYTA_H
