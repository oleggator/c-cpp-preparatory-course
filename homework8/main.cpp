

#include <iostream>
#include "Word.hpp"
int main(int argc, char *argv[]) {
    if (argc <= 3) {
        std::cout << "homework8 count file1 file2 ..." << std::endl;
        return 1;
    }

    const unsigned int N = (unsigned int)atoi(argv[1]);
    const unsigned int filesCount = (unsigned int)(argc - 2);
    if (!N) {
        std::cout << "homework8 count file1 file2 ..." << std::endl;
        return 1;
    }



    return 0;
}
