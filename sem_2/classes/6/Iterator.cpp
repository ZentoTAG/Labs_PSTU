#include <iostream>
#include "Iterator.h"

Iterator::Iterator() : elem(nullptr) {}
Iterator::Iterator(int * elem) : elem(elem) {}
Iterator::Iterator(const Iterator &obj) {
    elem = obj.elem;
}

Iterator::~Iterator() {
    elem = nullptr;
}

bool Iterator::operator==(const Iterator &obj) {
    return (elem == obj.elem);
}

bool Iterator::operator!=(const Iterator &obj) {
    return (elem != obj.elem);
}

int& Iterator::operator*() {
    if (elem == nullptr) {
        throw std::runtime_error("Dereferencing null iterator");
    }
    return *elem;
}

Iterator& Iterator::operator++() {
    elem++;
    return *this;
}
        
Iterator& Iterator::operator--() {
    elem--;
    return *this;
}