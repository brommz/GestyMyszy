#include "Gestures.h"
#include <fstream>
#include <time.h>

Gestures::Gestures() : siec(10, 12, 10)
{
    siec.otworzSiec("SIEC.net");
}

Gestures::~Gestures()
{
    data.clear();
    angles.clear();
}

void Gestures::addPoint(QPoint point)
{
    data.push_back(point);
}

void Gestures::end()
{
    calcAngles();
}

std::string Gestures::gesture()
{
    return name;
}

void Gestures::calcAngles()
{
    static std::string patterns[] =
    {
        "up",//1
        "down",//2
        "right",//3
        "left",//4
        "down-right",//5
        "down-left",//6
        "up-right",//7
        "up-left",//8
        "arrow-down-up",//9
        "arrow-up-down",//10
    };

    QLineF wektor;
    double result;
    std::vector<double>results;

    if(data.size() < 11) return;

    for(uint i=0; i<data.size()-2; i++)
    {
        wektor = QLine(data[i], data[i+1]);
        result = wektor.angle();
        angles.push_back(result);
    }

    std::ofstream file("sinus.txt");

    for(uint i=0; i<5; i++)
    {
        results.push_back(sin(0.01745*0.25*angles[i]));
        file << sin(0.01745*0.25*angles[i]) << "\n";//*pi/180
    }

    for(uint i=angles.size()-1; i>angles.size()-6; i--)
    {
        results.push_back(sin(0.01745*0.25*angles[i]));
        file << sin(0.01745*0.25*angles[i]) << "\n";//*pi/180
    }

    file.close();


    int num = siec.Oblicz(results);
    number = num;
    if(num != -1) name = patterns[num];
    else name = "Not recognize";

    data.clear();
    angles.clear();
    results.clear();

}
