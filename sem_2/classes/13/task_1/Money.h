#ifndef MONEY
#define MONEY
#include <iostream>

class Money {
    long Rubles;
    int Pennies;

    public:
        Money();
        Money(long, int);
        Money(const Money&);
        ~Money();

        Money& operator=(const Money&);
        bool operator>(const Money&);
        bool operator<(const Money&);

        Money operator+(const Money&) const;
        Money operator-(const Money&);

        friend Money operator/(const Money&, int);

        friend std::istream& operator>>(std::istream&, Money&);
        friend std::ostream& operator<<(std::ostream&, const Money&);

        void SetRubles(long);
        void SetPennies(int);

        long GetRubles() const;
        int GetPennies() const;
};
#endif