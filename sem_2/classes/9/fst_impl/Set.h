#ifndef SET
#define SET
#include <iostream>

class Set {
    private:
        int size;
        int * data;
    public:
        Set();
        Set(int);
        Set (const Set&);
        ~Set();

        Set& operator=(const Set&);
        Set operator+(const Set&);

        const int& operator[](int) const;
        int operator()();

        Set& operator++();
        Set operator++(int);
        
        friend std::istream& operator>>(std::istream&, Set&);
        friend std::ostream& operator<<(std::ostream&, const Set&);
};
#endif