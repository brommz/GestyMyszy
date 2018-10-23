#include "SiecNeuronowa.h"

SiecNeuronowa::SiecNeuronowa(const uint ileWarstw)
{
    _warstwy.reserve(ileWarstw);
}

SiecNeuronowa::~SiecNeuronowa()
{
    _warstwy.clear();
}

void SiecNeuronowa::dodajWarstwa(Warstwa* warstwa)
{
    _warstwy.push_back(warstwa);
}

uint SiecNeuronowa::zwrocIleWejsc() const
{
    return _warstwy[0]->zwrocIleNeuronow();
}

uint SiecNeuronowa::zwrocIleWyjsc() const
{
    return _warstwy[_warstwy.size()-1]->zwrocIleNeuronow();
}

uint SiecNeuronowa::zwrocIleWarstw() const
{
    return _warstwy.size();
}

Warstwa* SiecNeuronowa::zwrocWarstwa(uint nr)
{
    return _warstwy[nr];
}

void SiecNeuronowa::polacz(uint wPoczatkowa, uint wKoncowa, uint poczatkowy, uint koncowy, real waga)
{
    Warstwa* Wpoczatek = zwrocWarstwa(wPoczatkowa);
    Warstwa* WKoniec = zwrocWarstwa(wKoncowa);

    WKoniec->polacz(Wpoczatek,poczatkowy,koncowy,waga);
}

real SiecNeuronowa::skaluj(real ymax, real ymin, real xmax, real xmin, real x)
{
    /*wzór: y = (ymax-ymin)*(x-xmin)/(xmax-xmin) + ymin
    ymax=1
    ymin=-1
    xmax, xmin - wzięte z macierzy inputs (max i min możliwe na wejście)
    x - podane w trakcie działania wejście
    */
    return ((ymax-ymin)*(x-xmin))/(xmax-xmin) + ymin;
}
