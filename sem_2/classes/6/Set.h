#pragma once
#include <iostream>
#include "Iterator.h"

class Set {
    private:
        int size;
        int * data;
        Iterator beg;
        Iterator end;
    public:
        Set();
        Set(int);
        Set (const Set&);
        ~Set();

        Set& operator=(const Set&);
        Set operator+(const Set&);

        int& operator[](int);
        int operator()();

        Iterator fst();
        Iterator last();
        
        friend std::istream& operator>>(std::istream&, Set&);
        friend std::ostream& operator<<(std::ostream&, const Set&);
};