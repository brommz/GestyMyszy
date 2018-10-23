#include "WarstwaWejsciowa.h"

WarstwaWejsciowa::WarstwaWejsciowa(const uint ileNeuronow) : Warstwa(ileNeuronow)
{
    for(uint i=0; i<ileNeuronow; i++)
        dodajNeuron(new NeuronWejsciowy());
}

WarstwaWejsciowa::~WarstwaWejsciowa()
{
}

void WarstwaWejsciowa::dodajWejscia(std::vector<real>wejscia)
{
    if(wejscia.size() != zwrocIleNeuronow()) throw 1;

    for(uint i=0; i<wejscia.size(); i++)
        static_cast<NeuronWejsciowy*>(zwrocNeuron(i))->dodajWejscie(wejscia[i]);
}
