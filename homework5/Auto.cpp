#include "Auto.h"

Auto::Auto() {
    RandomValues randomValues;

    registrationPlate = new char[7];
    strncpy(registrationPlate, randomValues.getRandomRegisterPlate().c_str(), 6);

    char buffer[64];

    strncpy(buffer, randomValues.getRandomManufacturer().c_str(), 63);
    manufacturer = new char[strlen(buffer) + 1];
    strcpy(manufacturer, buffer);

    strncpy(buffer, randomValues.getRandomLastName().c_str(), 63);
    owner = new char[strlen(buffer) + 1];
    strcpy(owner, buffer);

    mileage = randomValues.getRandomMileage();
    year = randomValues.getRandomYear();
}

Auto::Auto(const Auto &car) {
    registrationPlate = new char[7];
    strncpy(registrationPlate, car.getRegistrationPlate(), 6);

    char buffer[64];

    strncpy(buffer, car.getManufacturer(), 63);
    manufacturer = new char[strlen(buffer) + 1];
    strcpy(manufacturer, buffer);

    strncpy(buffer, car.getOwner(), 63);
    owner = new char[strlen(buffer) + 1];
    strcpy(owner, buffer);

    mileage = car.getMileage();
    year = car.getYear();
}

Auto::~Auto() {
    delete[] owner;
    delete[] manufacturer;
    delete[] registrationPlate;
}

char *Auto::getOwner() const {
    return owner;
}

char *Auto::getRegistrationPlate() const  {
    return registrationPlate;
}

char *Auto::getManufacturer() const  {
    return manufacturer;
}

unsigned short Auto::getYear() const {
    return year;
}

unsigned int Auto::getMileage() const {
    return mileage;
}


char *Auto::setOwner(char *value) {
    delete[] owner;
    owner = new char[strlen(value)];

    return strcpy(owner, value);
}

char *Auto::setRegistrationPlate(char *value) {
    delete[] registrationPlate;
    registrationPlate = new char[strlen(value)];

    return strcpy(registrationPlate, value);
}

char *Auto::setManufacturer(char *value) {
    delete[] manufacturer;
    manufacturer = new char[strlen(value)];

    return strcpy(manufacturer, value);
}

int Auto::setYear(unsigned short value) {
    return year = value;
}

int Auto::setMileage(unsigned int value) {
    return mileage = value;
}

Auto& Auto::operator=(const Auto& car) {
    delete[] owner;
    delete[] manufacturer;
    delete[] registrationPlate;

    owner = new char[strlen(car.getOwner()) + 1];
    strcpy(owner, car.getOwner());

    manufacturer = new char[strlen(car.getManufacturer()) + 1];
    strcpy(manufacturer, car.getManufacturer());

    registrationPlate = new char[strlen(car.getRegistrationPlate()) + 1];
    strcpy(registrationPlate, car.getRegistrationPlate());

    mileage = car.getMileage();
    year = car.getYear();

    return *this;
}

std::ostream &operator<<(std::ostream &stream, const Auto &car) {
    stream << car.getOwner() << "\n\t" << car.getRegistrationPlate()
                  << ' ' << car.getManufacturer() << ' ' << car.getMileage();
                  
    return stream;
}

void Auto::show(std::ostream &stream) {
    stream << this->getOwner() << "\n\t" << this->getRegistrationPlate()
           << ' ' << this->getManufacturer() << ' ' << this->getMileage();
}
