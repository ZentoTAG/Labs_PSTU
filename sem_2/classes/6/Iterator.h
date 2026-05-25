#pragma once
#include <iostream>

class Iterator {
    friend class Set;

    private:
        int * elem;

    public:
        Iterator();
        Iterator(int*);
        Iterator(const Iterator&);
        ~Iterator();

        bool operator==(const Iterator&);
        bool operator!=(const Iterator&);
        int& operator*();

        Iterator& operator++();
        Iterator& operator--();
};