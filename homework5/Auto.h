#ifndef _AUTO_H_
#define _AUTO_H_

#include <cstring>
#include <iostream>

#include "RandomValues.h"

class Auto {
public:
    Auto();
    Auto(const Auto &car);
    ~Auto();

    char *getOwner() const ;
    char *getRegistrationPlate() const ;
    char *getManufacturer() const ;
    unsigned short getYear() const ;
    unsigned int getMileage() const ;

    char *setOwner(char *value);
    char *setRegistrationPlate(char *value);
    char *setManufacturer(char *value);
    int setYear(unsigned short value);
    int setMileage(unsigned int value);

    Auto& operator=(const Auto& car);
    friend std::ostream &operator<<(std::ostream &stream, const Auto &car);
    void show(std::ostream &stream);

private:
    char* owner;

    char *registrationPlate;
    char *manufacturer;
    unsigned short year;
    unsigned int mileage;
};

#endif
