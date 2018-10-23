#ifndef NEURONWYJSCIOWY_H
#define NEURONWYJSCIOWY_H

#include "definicje.h"
#include "NeuronZwykly.h"


class NeuronWyjsciowy : public NeuronZwykly
{
public:
    NeuronWyjsciowy();
    virtual ~NeuronWyjsciowy();

protected:

private:
    virtual real funkcjaAktywacji();
    NeuronWyjsciowy(const NeuronWyjsciowy& cos);
    NeuronWyjsciowy& operator=(const NeuronWyjsciowy& cos);
};

#endif // NEURONWYJSCIOWY_H
