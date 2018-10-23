#ifndef NEURONWEJSCIOWY_H
#define NEURONWEJSCIOWY_H

#include "definicje.h"
#include "Neuron.h"

class NeuronWejsciowy : public Neuron
{
public:
    NeuronWejsciowy();
    virtual ~NeuronWejsciowy();
    virtual void dodajWejscie(const real wejscie);
    virtual void obliczWyjscie();

protected:

private:
    real _wejscie;

    real funkcjaAktywacji();
    NeuronWejsciowy(const NeuronWejsciowy& cos);
    NeuronWejsciowy& operator=(const NeuronWejsciowy& cos);
};

#endif // NEURONWEJSCIOWY_H
