#ifndef CUBOID_H
#define CUBOID_H

#include "VolumeFigure.h"

class Cuboid: public VolumeFigure {
public:
    Cuboid(double x, double y, double z);
    Cuboid(const Cuboid &cuboid);

    double getVolume() const;
    double getArea() const;
    void printInfo() const;

private:
    double x, y, z;
};

#endif
