#ifndef MONEY
#define MONEY

#include <iostream>
#include <fstream>

class Money {
    long Rubles;
    int Pennies;

    public:
        Money();
        Money(long, int);
        Money(const Money&);
        ~Money();

        Money& operator=(const Money&);
        Money operator+(const Money&);
        Money operator-(const Money&);

        friend std::istream& operator>>(std::istream&, Money&);
        friend std::ostream& operator<<(std::ostream&, Money&);

        friend std::ifstream& operator>>(std::ifstream&, Money&);
        friend std::ofstream& operator<<(std::ofstream&, Money&);

        void SetRubles(long);
        void SetPennies(int);

        long GetRubles() const;
        int GetPennies() const;
};
#endif