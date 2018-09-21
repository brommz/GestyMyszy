#ifndef GESTY_H
#define GESTY_H

#include <QPoint>
#include <QLine>
#include "vector"
#include <cmath>
#include "SiecNeuronowa/SiecDwuwarstwowa.h"



class Gestures
{
public:
    Gestures();
    ~Gestures();
    void addPoint(QPoint point);
    void end();//ze juz skonczyl pobieranie punktow

    std::string gesture();
    int gNumber() { return number; }

protected:

private:
    void calcAngles();//liczy katy

    std::vector<QPoint> data;
    std::vector<double> angles;
    std::string name;
    int number;
    SiecDwuwarstwowa siec;
};


#endif // GESTY_H
