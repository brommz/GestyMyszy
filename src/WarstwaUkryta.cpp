#include "WarstwaUkryta.h"

WarstwaUkryta::WarstwaUkryta(const uint ileNeuronow) : Warstwa(ileNeuronow)
{
    for(uint i=0; i<ileNeuronow; i++)
        dodajNeuron(new NeuronZwykly());
}

WarstwaUkryta::~WarstwaUkryta()
{
}
