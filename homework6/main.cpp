#include <iostream>
#include <vector>

#include "VolumeFigure.h"
#include "Cuboid.h"
#include "Cylinder.h"

int main () {
    
    std::vector<VolumeFigure*> figures = {
        new Cuboid(4, 4, 4),
        new Cylinder(10, 5)
    };

    std::for_each(figures.begin(), figures.end(), [](VolumeFigure* figure) {
        figure->printInfo();
        std::cout << "\tVolume: " << figure->getVolume() << ", Area: " << figure->getArea() << std::endl;
    });

    std::for_each(figures.begin(), figures.end(), [](VolumeFigure* figure) {
        delete figure;
    });

    return 0;
}
