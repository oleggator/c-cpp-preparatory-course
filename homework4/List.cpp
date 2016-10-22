#include "List.h"

using namespace utl;

List::List() {
    this->firstElement = new Element();
}

List::List(std::string &value) {
    this->firstElement = new Element(value);
}

List::~List() {
    Element *element = firstElement->getNext();
    delete firstElement;

    while (element) {
        Element *next = element->getNext();
        delete element;
        element = next;
    }
}

Element *List::addElement(std::string &value) {

    if (isEmpty) {
        firstElement->setValue(value);
        isEmpty = 0;
        return firstElement;
    }

    Element *element = new Element(value);
    Element *currentElement = firstElement;
    while (currentElement) {
        if (value.compare(currentElement->getValue()) < 0) {
            element->previous = currentElement->previous;
            element->next = currentElement;

            currentElement->previous = element;

            if (element->previous == nullptr) {
                this->firstElement = element;
            }

            isEmpty = 0;

            return element;

        } else if (value.compare(currentElement->getValue()) == 0) {

            std::cout << "Element is exist\n";
            return element;
        }

        if (currentElement->next == 0) {
            currentElement->next = element;
            element->previous = currentElement;
            isEmpty = 0;

            return element;
        }
        currentElement = currentElement->getNext();
    }
}

Element *List::findElement(std::string &value) {
    Element *currentElement = firstElement;
    while (currentElement) {
        if ( value.compare(currentElement->getValue()) == 0 ) {
            return currentElement;
        } else {
            currentElement = currentElement->getNext();
        }
    }

    return nullptr;
}
