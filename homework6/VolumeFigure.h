#ifndef VOLUMEFIGURE_H
#define VOLUMEFIGURE_H

#include <iostream>

class VolumeFigure {
public:
    VolumeFigure();
    virtual ~VolumeFigure();

    virtual double getVolume() const = 0;
    virtual double getArea() const = 0;
    virtual void printInfo() const = 0;
};

#endif
