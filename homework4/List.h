#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>

#include "Element.h"

namespace utl {

class List {
public:
    List();
    List(std::string &value);
    ~List();

    Element *addElement(std::string &value);
    Element *findElement(std::string &value);

private:
    bool isEmpty = 1;

    Element *firstElement = nullptr;

};

}

#endif
