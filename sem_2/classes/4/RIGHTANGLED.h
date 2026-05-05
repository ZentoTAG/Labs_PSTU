#pragma once
#include "PAIR.h"

class RIGHTANGLED : public PAIR {
public:
    RIGHTANGLED();
    ~RIGHTANGLED();
    RIGHTANGLED(int katet1, int katet2);
    RIGHTANGLED(const RIGHTANGLED& r);

    double hypotenuse() const;  // вычисление гипотенузы

    RIGHTANGLED& operator=(const RIGHTANGLED& r);
    friend istream& operator>>(istream& in, RIGHTANGLED& r);
    friend ostream& operator<<(ostream& out, const RIGHTANGLED& r);
};
