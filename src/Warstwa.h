#ifndef WARSTWA_H
#define WARSTWA_H

#include "definicje.h"
#include "Neuron.h"
#include "Link.h"

class Warstwa
{
public:
    Warstwa(const uint ileNeuronow);
    virtual ~Warstwa();//usuwa wszystkie neurony, polaczenia
    virtual uint zwrocIleNeuronow();
    Neuron* zwrocNeuron(const uint nr);
    virtual void Oblicz();
    void polacz(Warstwa* poczatkowa, uint poczatkowy, uint koncowy, real waga);//poczatkowy-nr neuronu w tej warstwie, koncowy-nr neuronu z warstwy nast czyli nr polaczenia

protected:
    virtual void dodajNeuron(Neuron* neuron);//zeby mozna bylo dodawac neuron wej/wyj/zwykly

private:
    std::vector<Neuron*>_neurony;//kontener neuronow w warstwie

    Warstwa(const Warstwa& cos);
    Warstwa& operator=(const Warstwa& cos);
};

#endif // WARSTWA_H
