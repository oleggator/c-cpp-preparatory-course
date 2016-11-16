#include "Cuboid.h"

Cuboid::Cuboid(double x, double y, double z): x(x), y(y), z(z) {}

double Cuboid::getVolume() const {
    return x * y * z;
}

double Cuboid::getArea() const {
    return 2 * (x * y + x * z + y * z);
}

void Cuboid::printInfo() const {
    std::cout << "x: " << x << ", y: " << y << ", z: " << z << std::endl;
}
