#include "RIGHTANGLED.h"

RIGHTANGLED::RIGHTANGLED() : PAIR() {}
RIGHTANGLED::~RIGHTANGLED() {}
RIGHTANGLED::RIGHTANGLED(int k1, int k2) : PAIR(k1, k2) {}
RIGHTANGLED::RIGHTANGLED(const RIGHTANGLED& r) : PAIR(r) {}

double RIGHTANGLED::hypotenuse() const {
    return sqrt(first * first + second * second);
}

RIGHTANGLED& RIGHTANGLED::operator=(const RIGHTANGLED& r) {
    if (this == &r) return *this;
    PAIR::operator=(r);  // вызываем присваивание базового класса
    return *this;
}

istream& operator>>(istream& in, RIGHTANGLED& r) {
    cout << "Катет 1: "; in >> r.first;
    cout << "Катет 2: "; in >> r.second;
    return in;
}

ostream& operator<<(ostream& out, const RIGHTANGLED& r) {
    out << "Катеты: " << r.first << " и " << r.second
        << ", гипотенуза = " << r.hypotenuse();
    return out;
}
