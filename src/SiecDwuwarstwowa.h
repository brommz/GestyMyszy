#ifndef SIECDWUWARSTWOWA_H
#define SIECDWUWARSTWOWA_H

#include "definicje.h"
#include "SiecNeuronowa.h"
#include "WarstwaWejsciowa.h"
#include "WarstwaWyjsciowa.h"
#include "WarstwaUkryta.h"


class SiecDwuwarstwowa : public SiecNeuronowa
{
public:
    SiecDwuwarstwowa(const uint ileWejsc, const uint ileUkrytych, const uint ileWyjsc);
    virtual ~SiecDwuwarstwowa();
    virtual void otworzSiec(const std::string &filename);
    virtual int Oblicz(std::vector<real> wejscia);

protected:

private:
    std::string iwfile, hwfile, hbias, obias;
    uint _lWejsc, _lUkrytych, _lWyjsc;

    SiecDwuwarstwowa(const SiecDwuwarstwowa& cos);
    SiecDwuwarstwowa& operator=(const SiecDwuwarstwowa& cos);
    virtual void polaczWejscie(uint wejsciowy, uint ukryty, real waga);
    virtual void polaczWyjscie(uint ukryty, uint wyjsciowy, real waga);
    virtual void ustawBiasUkrytej(uint neuron, real bias);//nr neuronu
    virtual void ustawBiasWyjsciowej(uint neuron, real bias);

    void pobierzWagiWejsc();
    void pobierzWagiUkrytych();
    void pobierzBiasyUkrytych();
    void pobierzBiasyWyjsciowych();
};


#endif // SIECDWUWARSTWOWA_H
