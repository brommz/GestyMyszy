#include "Neuron.h"
#include "Link.h"

Neuron::Neuron()
{
    _blad = 0;
}

Neuron::~Neuron()
{
    _wejscie.clear();
    _wyjscie.clear();
}

real Neuron::zwrocBlad() const
{
    return _blad;
}

real Neuron::zwrocWyjscie() const
{
    return _wynik;
}

uint Neuron::zwrocIleWejsc() const
{
    return _wejscie.size();
}

uint Neuron::zwrocIleWyjsc() const
{
    return _wyjscie.size();
}


void Neuron::ustawWaga(const real waga, const uint polaczenie)
{
    _wyjscie[polaczenie]->ustawWaga(waga);
}

real Neuron::zwrocWaga(const uint polaczenie) const
{
    return _wyjscie[polaczenie]->zwrocWaga();
}

void Neuron::polacz(Neuron* poczatek, real waga)
{
    Link* link = new Link(poczatek, this, waga);
    poczatek->_wyjscie.push_back(link);//wyjscie z neuronu poczatkowego
    _wejscie.push_back(link);//wejscie naszego this
}

real Neuron::sumaAktywacji()
{
    real suma = 0;
    for(uint i = 0; i < _wejscie.size(); i++)
        suma += _wejscie[i]->zwrocWaga() * _wejscie[i]->zwrocPoczatek()->zwrocWyjscie();
    return suma;
}

void Neuron::ustawWynik(const real wynik)
{
    _wynik = wynik;
}

void Neuron::ustawBlad(const real blad)
{
    _blad = blad;
}
