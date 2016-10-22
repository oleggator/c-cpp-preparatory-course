#ifndef _ELEMENT_H_
#define _ELEMENT_H_

#include <string>

namespace utl {

class List;

class Element {

public:
    Element();
    Element(std::string &word);

    void removeElement();

    void setValue(std::string &value);
    std::string getValue();

    Element *getPrevious();
    Element *getNext();

    friend List;
private:
    Element *previous = nullptr;
    Element *next = nullptr;

    std::string value;

};

}

#endif
