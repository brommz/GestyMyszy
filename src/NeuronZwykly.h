#ifndef NEURONZWYKLY_H
#define NEURONZWYKLY_H

#include "definicje.h"
#include "Neuron.h"

class NeuronZwykly : public Neuron
{
public:
    NeuronZwykly();
    virtual ~NeuronZwykly();
    void ustawBias(const real bias);
    real zwrocBias() const;
    virtual void obliczWyjscie();

protected:
    virtual real funkcjaAktywacji();

private:
    real _bias;

    NeuronZwykly(const NeuronZwykly& cos);
    NeuronZwykly& operator=(const NeuronZwykly& cos);
};

#endif // NEURONZWYKLY_H
