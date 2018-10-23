#ifndef _LINK_H
#define _LINK_H

#include "definicje.h"

class Link
{
public:
    Link(Neuron* poczatek, Neuron* koniec, real waga);
    virtual ~Link();
    real zwrocWaga() const;
    void ustawWaga(const real waga);
    const Neuron* zwrocPoczatek() const;
    const Neuron* zwrocKoniec() const;

private:
    Neuron* _poczatek;//neuron poczatkowy w polaczeniu
    Neuron* _koniec;
    real _waga;//waga polaczenia

    Link(const Link& link);
    Link& operator=(const Link& link);
};

#endif // define _LINK_H

