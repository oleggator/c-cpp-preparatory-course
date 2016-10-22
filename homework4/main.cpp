#include <iostream>
#include <fstream>
#include <string>

#include "List.h"

int handleFile(std::ifstream &file);
void printWord(utl::List *list, std::string &word);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "homework4 [filename]\n";
        return EXIT_FAILURE;
    }

    std::ifstream file1(argv[1]);
    if ( !file1.is_open() ) {
        std::cout << "File open error\n";
        return EXIT_FAILURE;
    }


    if ( !handleFile(file1) ) {
        std::cout << "File handling error\n";
        return EXIT_FAILURE;
    }

    file1.close();

    return EXIT_SUCCESS;
}

int handleFile(std::ifstream &file) {
    utl::List *list = new utl::List();
    utl::List list1("name");
    char op = 0;
    std::string word;
    file >> op >> word;

    if ( file.bad() ){
        std::cout << "File reading error\n";
        delete list;
        return 0;
    }
    
    while ( !file.eof() ) {
        utl::Element *element;
        switch (op) {
            case '+':
                if ( list->addElement(word) ) {
                    break;
                } else {
                    delete list;
                    return 0;
                }

            case '-':
                element = list->findElement(word);
                if (element) {
                    element->removeElement();
                    break;
                } else {
                    delete list;
                    return 0;
                }

            case '?':
                printWord(list, word);
                break;

            default:
                printf("Wrong operator\n");
                delete list;
                return 0;

        }

        file >> op >> word;
        if ( file.bad() ){
            std::cout << "File reading error\n";
            delete list;
            return 0;
        }
    }

    delete list;
}

void printWord(utl::List *list, std::string &word) {
    utl::Element *element = list->findElement(word);

    if (element) {
        std::cout << "YES\t" << word << std::endl;
    } else {
        std::cout << "NO\t" << word << std::endl;
    }

}
