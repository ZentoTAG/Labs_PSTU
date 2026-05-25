#include <iostream>
#include <fstream>
#include "Money.h"

Money::Money() : Rubles(0), Pennies(0) {}

Money::Money(long rubles, int pennies) : Rubles(rubles), Pennies(pennies) {
    SetRubles(Rubles);
    SetPennies(Pennies);
}

Money::Money(const Money &other) {
    Rubles = other.Rubles;
    Pennies = other.Pennies;
}
Money::~Money() {};

void Money::SetRubles(long summ) {
    if (summ >= 0) {
        Rubles = summ;
    }
    else {
        std::cout << "Error! Rubles < 0" << std::endl;
    }
}

void Money::SetPennies(int summ) {
    if (summ >= 0) {
        Rubles += summ / 100;
        Pennies = summ % 100;
    }
    else {
        std::cout << "Error! Pennies < 0" << std::endl;
    }
}

long Money::GetRubles() const {
    return Rubles;
}

int Money::GetPennies() const {
    return Pennies;
}

Money& Money::operator=(const Money &m) {
    if (&m == this) {
        return *this;
    }
    Rubles = m.Rubles;
    Pennies = m.Pennies;
    return *this;
}

Money Money::operator+(const Money& other) {
    long rub = Rubles + other.Rubles + (Pennies + other.Pennies) / 100;
    int pen = (Pennies + other.Pennies) % 100;
    return Money(rub, pen);
}

Money Money::operator-(const Money& other) {
    if ((Rubles < other.Rubles) || (Rubles == other.Rubles && Pennies < other.Pennies)) {
        std::cout << "Error! Balance < 0" << std::endl;
        return Money(0, 0);
    }
    long rub = (Rubles - other.Rubles);
    int pen = (Pennies - other.Pennies);

    if (pen < 0) {
        rub--;
        pen = (100 - abs(pen));
    }
    
    return Money(rub, pen);
}

std::istream& operator>>(std::istream &in, Money &obj) {
    long rub;
    int pen;
    std::cout << "Rubles: ";
    in >> rub;
    std::cout << "Pennie: ";
    in >> pen;

    obj.SetRubles(rub);
    obj.SetPennies(pen);

    return in;
}

std::ostream& operator<<(std::ostream &out, Money &obj) {
    out << "Balance: " << obj.GetRubles();

    if (obj.GetPennies() < 10) {
        out << ",0" << obj.GetPennies() << " rub";
    }
    else {
        out << "," << obj.GetPennies() << " rub";
    }

    return out;
}

std::ifstream& operator>>(std::ifstream &fin, Money &obj) {
    fin >> obj.Rubles;
    fin >> obj.Pennies;

    obj.SetRubles(obj.Rubles);
    obj.SetPennies(obj.Pennies);

    return fin;
}

std::ofstream& operator<<(std::ofstream &fout, Money &obj) {
    fout <<  obj.GetRubles() << "\n";
    fout  << obj.GetPennies() << "\n";

    return fout;
}