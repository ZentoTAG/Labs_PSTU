#include "PAIR.h"

PAIR::PAIR() : first(0), second(0) {}
PAIR::~PAIR() {}
PAIR::PAIR(int f, int s) : first(f), second(s) {}
PAIR::PAIR(const PAIR& p) : first(p.first), second(p.second) {}

void PAIR::set_first(int f) { first = f; }
void PAIR::set_second(int s) { second = s; }
int PAIR::product() const { return first * second; }

PAIR& PAIR::operator=(const PAIR& p) {
    if (this == &p) return *this;
    first = p.first;
    second = p.second;
    return *this;
}

istream& operator>>(istream& in, PAIR& p) {
    cout << "first: "; in >> p.first;
    cout << "second: "; in >> p.second;
    return in;
}

ostream& operator<<(ostream& out, const PAIR& p) {
    out << "first = " << p.first << ", second = " << p.second;
    return out;
}
