#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <cstring>

#include "Auto.h"
#include "RandomValues.h"

void printCarsByOwner(Auto *begin, Auto *end);
void printCarsByManufacturer(Auto *begin, Auto *end);
void printCarsByMileage(Auto *begin, Auto *end);

int main() {
    std::array<Auto, 150> cars;

    std::cout << std::string(100, '\n');
    while (1) {
        std::cout << "[1] Поиск по владельцу" << std::endl
                  << "[2] Поиск по производителю" << std::endl
                  << "[3] Поиск по пробегу" << std::endl
                  << "[0] Выход" << std::endl
                  << "> ";

        char choice;
        std::cin >> choice;

        switch (choice) {
            case '1':
                std::cout << std::string(100, '\n');
                printCarsByOwner(cars.begin(), cars.end());
                break;

            case '2':
                std::cout << std::string(100, '\n');
                printCarsByManufacturer(cars.begin(), cars.end());
                break;

            case '3':
                std::cout << std::string(100, '\n');
                printCarsByMileage(cars.begin(), cars.end());
                break;

            case '0':
                return 0;

            default:
                break;
        }

    }
}

void printCarsByOwner(Auto *begin, Auto *end) {
    std::string owner;

    std::cout << "Input owner's last name." << std::endl
              << "[0] Random last name" << std::endl
              << "> ";
    std::cin >> owner;

    if (!strcmp(owner.c_str(), "0")) {
        RandomValues rv;
        owner = rv.getRandomLastName(); 
    }

    std::cout << std::string(100, '\n');
    std::cout << "Имя для поиска: " << owner << std::endl;

    std::for_each(begin, end, [&owner](Auto &car) {
        if (!strcmp(car.getOwner(), owner.c_str())) {
            std::cout << car << std::endl;
        }
    });

    std::cout << std::endl;
}

void printCarsByManufacturer(Auto *begin, Auto *end) {
    std::string manufacturer;

    std::cout << "Input car's manufacturer." << std::endl
              << "[0] Random manufacturer" << std::endl
              << "> ";
    std::cin >> manufacturer;

    if (!strcmp(manufacturer.c_str(), "0")) {
        RandomValues rv;
        manufacturer = rv.getRandomManufacturer(); 
    }

    std::cout << std::string(100, '\n');
    std::cout << "Производитель для поиска: " << manufacturer << std::endl;

    std::for_each(begin, end, [&manufacturer](Auto &car) {
        if (!strcmp(car.getManufacturer(), manufacturer.c_str())) {
            std::cout << car.getOwner() << "\n\t" << car.getManufacturer() << ' ' << car.getRegistrationPlate() << std::endl;
        }
    });

    std::cout << std::endl;
}

void printCarsByMileage(Auto *begin, Auto *end) {

    unsigned int count;
    std::cout << "Cars count: ";
    std::cin >> count;
    if (count > end - begin) {
        std::cout << "Incorrect cars count." << std::endl;
        return 0;
    }

    std::sort(begin, end, [](const Auto &car1, const Auto &car2) -> bool {
        return (car1.getMileage() > car2.getMileage());
    });

    for (Auto *i = begin; i < begin + count; ++i) {
        std::cout << *i << std::endl;
    }

    std::cout << std::endl;
}
