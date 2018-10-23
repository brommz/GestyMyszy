#ifndef SIECNEURONOWA_H
#define SIECNEURONOWA_H

#include "definicje.h"
#include "Warstwa.h"
#include <string>

class SiecNeuronowa
{
public:
    SiecNeuronowa(const uint ileWarstw);
    virtual ~SiecNeuronowa();
    virtual void dodajWarstwa(Warstwa* warstwa);
    uint zwrocIleWejsc() const;
    uint zwrocIleWyjsc() const;
    uint zwrocIleWarstw() const;

protected:
    Warstwa* zwrocWarstwa(const uint nr);
    virtual void otworzSiec(const std::string &filename) = 0;
    void polacz(uint wPoczatkowa, uint wKoncowa, uint poczatkowy, uint koncowy, real waga);
    virtual real skaluj(real ymax, real ymin, real xmax, real xmin, real x);//oznaczenia wg matlaba, wzór w def

private:
    std::vector<Warstwa*>_warstwy;

    SiecNeuronowa(const SiecNeuronowa& cos);
    SiecNeuronowa& operator=(const SiecNeuronowa& cos);
};

#endif // SIECNEURONOWA_H
