#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include<fstream>

#include "SiecDwuwarstwowa.h"

using namespace std;

int main()
{
try
{
    SiecDwuwarstwowa siec(40, 10, 10);
    siec.otworzSiec("SIEC.net");

    std::vector<real> test;
    for(uint i=0; i<40;i++)
        test.push_back(0.4);

    std::cout << "00works\n";
    std::cout << siec.Oblicz(test) << "\n";
}
catch(Exception& e)
{
        std::cout << "ERROR: " << e.what() << "\n";
}
catch(...)
{
        std::cout << "Dziwny blad";
}

    return 0;
}
