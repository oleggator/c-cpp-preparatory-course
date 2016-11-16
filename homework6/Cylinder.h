#ifndef CYLINDER_H
#define CYLINDER_H

#include <cmath>

#include "VolumeFigure.h"

class Cylinder: public VolumeFigure {
public:
    Cylinder(double height, double radius);

    double getVolume() const;
    double getArea() const;
    void printInfo() const;

private:

    double height, radius;
};

#endif
