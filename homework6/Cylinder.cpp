#include "Cylinder.h"

Cylinder::Cylinder(double height, double radius): height(height), radius(radius) {}

double Cylinder::getVolume() const {
    return pow(radius, 2) * M_PI * height;
}

double Cylinder::getArea() const {
    return 2 * M_PI * radius * (height + radius);
}

void Cylinder::printInfo() const {
    std::cout << "Height: " << height << ", Radius: " << radius << std::endl;
}
