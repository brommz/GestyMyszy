#include "NeuronWyjsciowy.h"
#include<cmath>

NeuronWyjsciowy::NeuronWyjsciowy() : NeuronZwykly()
{

}

NeuronWyjsciowy::~NeuronWyjsciowy()
{

}

real NeuronWyjsciowy::funkcjaAktywacji()
{
    real suma = sumaAktywacji();
    real bias = zwrocBias();
    //return (1/(1+exp(-(suma+bias))));
    return tanh(suma+bias);
}

