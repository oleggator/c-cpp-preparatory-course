#include "RandomValues.h"

RandomValues::RandomValues() {
    readValuesFromFile("manufacturers.txt", manufacturers);
    readValuesFromFile("lastnames.txt", lastnames);
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count(); 
    generator.seed(seed);
}

std::string RandomValues::getRandomManufacturer() {
    std::uniform_int_distribution<> uid(0, manufacturers.size() - 1);
    return manufacturers[uid(generator)];
}

std::string RandomValues::getRandomLastName() {
    std::uniform_int_distribution<> uid(0, lastnames.size() - 1);
    return lastnames[uid(generator)];
}

std::string RandomValues::getRandomRegisterPlate() {
    std::string registerPlate(6, '\0');

    std::uniform_int_distribution<> uid1(0, plateCharsCount - 1);
    registerPlate[0] = plateChars[uid1(generator)];
    registerPlate[4] = plateChars[uid1(generator)];
    registerPlate[5] = plateChars[uid1(generator)];

    std::uniform_int_distribution<> uid2(0, 9);
    registerPlate[1] = '0' + uid2(generator);
    registerPlate[2] = '0' + uid2(generator);
    registerPlate[3] = '0' + uid2(generator);

    return registerPlate;
}

unsigned int RandomValues::getRandomMileage() {
    std::uniform_int_distribution<> uid(0, 1000000);
    return uid(generator);
}

unsigned short RandomValues::getRandomYear() {
    std::time_t time = std::chrono::system_clock::to_time_t(
        std::chrono::system_clock::now()
    );
    
    tm local_tm = *localtime(&time);

    std::uniform_int_distribution<> uid(local_tm.tm_year + 1860, local_tm.tm_year + 1900);

    return uid(generator);
}

int RandomValues::readValuesFromFile(std::string path, std::vector<std::string> &array) {
    std::ifstream file(path.c_str());
    if (!file.is_open()) {
        return 0;
    }

    std::string buffer;
    std::getline(file, buffer);
    while (!file.eof()) {
        array.push_back(buffer);
        std::getline(file, buffer);
    }

    file.close();

    return 1;
}
