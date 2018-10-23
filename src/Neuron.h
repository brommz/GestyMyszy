#ifndef NEURON_H
#define NEURON_H

#include "definicje.h"

class Neuron;


class Neuron
{
public:
    Neuron();//blad na 0
    virtual ~Neuron();//usuwa wszystkie linki we/wyj
    real zwrocBlad() const;
    uint zwrocIleWejsc() const;
    uint zwrocIleWyjsc() const;
    real zwrocWaga(const uint polaczenie) const;//nr polaczenia wyjsciowego
    real zwrocWyjscie() const;
    virtual void obliczWyjscie() = 0;
    virtual void polacz(Neuron* poczatek, real waga);

protected:
    virtual void ustawWynik(const real wynik);//ustawia wartosc wyjscia neuronu
    virtual void ustawBlad(const real blad);
    virtual real funkcjaAktywacji() = 0;//oblicza f.aktywacji neuronu
    virtual real sumaAktywacji();//oblicz sumę (wag * wejść) dla funkcji aktywacji
    virtual void ustawWaga(const real waga, const uint polaczenie);//polaczenie to nr polaczenia wyjsciowego

private:
    real _blad;
    real _wynik;
    std::vector<Link*>_wejscie;
    std::vector<Link*> _wyjscie;

    friend class Link;
    Neuron(const Neuron& cos);
    Neuron& operator=(const Neuron& cos);
};

#endif // NEURON_H
