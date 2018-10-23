#include "NeuronWejsciowy.h"

NeuronWejsciowy::NeuronWejsciowy() : Neuron()
{
}

NeuronWejsciowy::~NeuronWejsciowy()
{
}

void NeuronWejsciowy::dodajWejscie(const real wejscie)
{
    _wejscie = wejscie;
}

void NeuronWejsciowy::obliczWyjscie()
{
    ustawWynik(_wejscie);
}

real NeuronWejsciowy::funkcjaAktywacji()
{
    return zwrocWyjscie();
}
