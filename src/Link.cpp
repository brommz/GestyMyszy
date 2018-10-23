#include "Link.h"
#include "Neuron.h"

using namespace std;

Link::Link(Neuron *poczatek, Neuron *koniec, real waga)
{
    _poczatek = poczatek;
    _koniec = koniec;
    ustawWaga(waga);
}

void Link::ustawWaga(const real waga)
{
    _waga = waga;
}

Link::~Link()
{
    delete _poczatek;
    delete _koniec;
}

real Link::zwrocWaga() const
{
    return _waga;
}

const Neuron* Link::zwrocPoczatek() const
{
    return _poczatek;
}

const Neuron* Link::zwrocKoniec() const
{
    return _koniec;
}
