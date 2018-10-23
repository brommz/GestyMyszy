#include "SiecDwuwarstwowa.h"
#include <cmath>
#include <fstream>
#include <iostream>


using namespace std;
SiecDwuwarstwowa::SiecDwuwarstwowa(uint ileWejsc, uint ileUkrytych, uint ileWyjsc) : SiecNeuronowa(3),
_lWejsc(ileWejsc), _lUkrytych(ileUkrytych), _lWyjsc(ileWyjsc)
{
    dodajWarstwa(new WarstwaWejsciowa(ileWejsc));
    dodajWarstwa(new WarstwaUkryta(ileUkrytych));
    dodajWarstwa(new WarstwaWyjsciowa(ileWyjsc));
}

SiecDwuwarstwowa::~SiecDwuwarstwowa()
{
}

void SiecDwuwarstwowa::otworzSiec(const std::string &filename)
{
    std::ifstream file;
    file.open(filename.c_str(), std::ios::in);

    if (!file)
    {
        throw Exception("Brak pliku sieci");
    }
    file >> iwfile; if(file.eof()) throw Exception("Zly plik siec");
    file >> hwfile; if(file.eof()) throw Exception("Zly plik siec");
    file >> hbias; if(file.eof()) throw Exception("Zly plik siec");
    file >> obias;

    pobierzWagiWejsc();
    pobierzWagiUkrytych();
    pobierzBiasyUkrytych();
    pobierzBiasyWyjsciowych();
}

int SiecDwuwarstwowa::Oblicz(std::vector<real> wejscia)
{
    //skalowanie:
    for(uint i=0; i<wejscia.size(); i++)
        wejscia[i] = skaluj(1, -1, 0.9807, 0.0218, wejscia[i]);

    static_cast<WarstwaWejsciowa*>(zwrocWarstwa(0))->dodajWejscia(wejscia);

    for(uint i=0; i<zwrocIleWarstw(); i++)
        zwrocWarstwa(i)->Oblicz();


    std::vector<real> result;
    WarstwaWyjsciowa* temp = static_cast<WarstwaWyjsciowa*>(zwrocWarstwa(2));
    result = temp->wynik();

    real max = -1000;
    uint nr = 100;

    std::ofstream file("WYNIK.txt");
    for(uint i=0; i<result.size(); i++)
    {
        if(result[i] > max)
        {
            max = result[i];
            nr = i;
        }
        //std::cout << result[i] << "\n";
        file << result[i] << "\n";
    }
    file.close();

    //if(result[nr] > 0.5) return -1;
    return nr;
}

void SiecDwuwarstwowa::pobierzWagiWejsc()
{
    std::ifstream file;
	file.open(iwfile.c_str(), std::ios::in);

	if (!file)
	{
                throw Exception("Brak pliku w-wejscia");
	}

	//cout << "\nInputW:\n";

    for(uint h = 0; h<_lUkrytych; h++)
	{
		for(uint i = 0; i<_lWejsc; i++)
		{
			if (file.eof())
			{
                                throw Exception("Zly plik w-wejscia");
			}
			real wt;
			file >> wt;
            //cout << wt << " ";
            polaczWejscie(i, h, wt);
            //cout << i+1 << " z " << h+1 << " waga "<< wt << "\n";
		}
		//cout << "\n";
	}
	file.close();
}

void SiecDwuwarstwowa::pobierzWagiUkrytych()
{
    std::ifstream file;
    file.open(hwfile.c_str(), std::ios::in);
	if (!file)
	{
                throw Exception("Brak pliku w-ukr");
	}

	//cout << "\nHiddenW:\n";
	for (uint o = 0; o < _lWyjsc; o++)
	{
		for (uint h = 0; h < _lUkrytych; h++)
		{
			if (file.eof())
			{
                                throw Exception("Zly plik w-ukr");
			}
			real wt;
			file >> wt;
            //cout << wt << " ";
           polaczWyjscie(h, o, wt);
		}
		//cout << "\n";
	}
	file.close();
}

void SiecDwuwarstwowa::pobierzBiasyUkrytych()
{
    //Warstwa* ukryta = zwrocWarstwa(1);
    std::ifstream file;
    file.open(hbias.c_str(), std::ios::in);
    if (!file)
	{
                throw Exception("Brak pliku b-ukr");
	}

	//cout << "\nHiddenB:\n";
	for (uint h = 0; h<_lUkrytych; h++)
	{
		real b;
		if (file.eof())
		{
                    throw Exception("Zly plik b-ukr");
		}

		file >> b;
		//cout << b << "\n";
        ustawBiasUkrytej(h, b);
	}
	file.close();
}

void SiecDwuwarstwowa::pobierzBiasyWyjsciowych()
{
    //Warstwa* wyjsciowa = zwrocWarstwa(2);
    std::ifstream file;
    file.open(obias.c_str(), std::ios::in);
	if (!file)
	{
        throw Exception("Brak pliku b-wyj");
	}

	//cout << "\nOutputB:\n";
	for (uint o = 0; o<_lWyjsc; o++)
	{
		real b;
		if (file.eof())
		{
                    throw Exception("Zly plik b-wyj");
		}

		file >> b;
		//cout << b << "\n";

        ustawBiasWyjsciowej(o, b);
	}
	file.close();
}

void SiecDwuwarstwowa::polaczWejscie(uint wejsciowy, uint ukryty, real waga)
{
    polacz(0, 1, wejsciowy, ukryty, waga);
}

void SiecDwuwarstwowa::polaczWyjscie(uint ukryty, uint wyjsciowy, real waga)
{
    polacz(1, 2, ukryty, wyjsciowy, waga);
}

void SiecDwuwarstwowa::ustawBiasUkrytej(uint neuron, real bias)
{
    Warstwa* ukryta = zwrocWarstwa(1);
    NeuronZwykly* Ukryty = static_cast<NeuronZwykly*>(ukryta->zwrocNeuron(neuron));

    Ukryty->ustawBias(bias);
}

void SiecDwuwarstwowa::ustawBiasWyjsciowej(uint neuron, real bias)
{
    Warstwa* wyjsciowa = zwrocWarstwa(2);
    NeuronZwykly* Wyjsciowy = static_cast<NeuronZwykly*>(wyjsciowa->zwrocNeuron(neuron));

    Wyjsciowy->ustawBias(bias);
}
