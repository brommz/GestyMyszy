#include "NeuronZwykly.h"
#include <cmath>

NeuronZwykly::NeuronZwykly() : Neuron()
{
    _bias = 0;
}

NeuronZwykly::~NeuronZwykly()
{

}

void NeuronZwykly::ustawBias(const real bias)
{
    _bias = bias;
}

real NeuronZwykly::zwrocBias() const
{
    return _bias;
}

void NeuronZwykly::obliczWyjscie()
{
    ustawWynik( funkcjaAktywacji() );
}

real NeuronZwykly::funkcjaAktywacji()
{
    real suma = sumaAktywacji();
    return tanh(suma+_bias);
    //return 1/(1+exp(-(suma+_bias)));
}

