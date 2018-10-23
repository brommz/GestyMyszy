#include "WarstwaWyjsciowa.h"


WarstwaWyjsciowa::WarstwaWyjsciowa(const uint ileNeuronow) : Warstwa(ileNeuronow)
{
    for(uint i=0; i<ileNeuronow; i++)
        dodajNeuron( new NeuronWyjsciowy() );
}

WarstwaWyjsciowa::~WarstwaWyjsciowa()
{

}

std::vector<real> WarstwaWyjsciowa::wynik()
{
    std::vector<real> temp;
    for(uint i=0; i<zwrocIleNeuronow(); i++)
        temp.push_back(zwrocNeuron(i)->zwrocWyjscie());
    return temp;
}
