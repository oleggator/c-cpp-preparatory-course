#ifndef _RANDOMVALUES_H_
#define _RANDOMVALUES_H_

#include <vector>
#include <string>
#include <fstream>
#include <random>
#include <ctime>
#include <chrono>

const char plateCharsCount = 12;
const char plateChars[plateCharsCount] = {'A', 'B', 'E', 'K', 'M', 'H', 'P', 'O', 'C', 'T', 'Y', 'X'};

class RandomValues {
public:
    RandomValues();

    std::string getRandomManufacturer();
    std::string getRandomLastName();
    std::string getRandomRegisterPlate();
    unsigned int getRandomMileage();
    unsigned short getRandomYear();

private:
    int readValuesFromFile(std::string path, std::vector<std::string> &array);

    std::vector<std::string> manufacturers;
    std::vector<std::string> lastnames;

    std::mt19937 generator;
};

#endif
