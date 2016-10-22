#include "Element.h"
using namespace utl;

Element::Element() {
    this->value = "";
}

Element::Element(std::string &value) {
    this->value = value;
}

void Element::removeElement() {
    if (previous) {
        previous->next = next;
    }

    if (next) {
        next->previous = previous;
    }

    delete this;
}

void Element::setValue(std::string &value) {
    this->value = value;
}

std::string Element::getValue() {
    return this->value;
}

Element *Element::getPrevious() {
    return previous;
}

Element *Element::getNext() {
    return next;
}
