#include "Warstwa.h"

Warstwa::Warstwa(const uint ileNeuronow)
{
    _neurony.reserve(ileNeuronow);
}

Warstwa::~Warstwa()
{
    _neurony.clear();
}

uint Warstwa::zwrocIleNeuronow()
{
    return _neurony.size();
}

void Warstwa::dodajNeuron(Neuron* neuron)
{
    _neurony.push_back(neuron);
}

Neuron* Warstwa::zwrocNeuron(const uint nr)
{
    return _neurony[nr];
}

void Warstwa::Oblicz()
{
     for(uint i=0; i<_neurony.size(); i++)
         _neurony[i]->obliczWyjscie();
}

void Warstwa::polacz(Warstwa* poczatkowa, uint poczatkowy, uint koncowy, real waga)
{
    Neuron* Poczatkowy = poczatkowa->zwrocNeuron(poczatkowy);
    Neuron* Koncowy = this->zwrocNeuron(koncowy);

    Koncowy->polacz(Poczatkowy, waga);
}
