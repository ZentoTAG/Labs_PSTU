#pragma once
#include "PAIR.h"

class RIGHTANGLED : public PAIR {
public:
    RIGHTANGLED();
    ~RIGHTANGLED();
    RIGHTANGLED(int k1, int k2);
    RIGHTANGLED(const RIGHTANGLED& r);

    double hypotenuse() const;
    void Show();  // переопределение виртуальной функции

    RIGHTANGLED& operator=(const RIGHTANGLED& r);
    friend istream& operator>>(istream& in, RIGHTANGLED& r);
    friend ostream& operator<<(ostream& out, const RIGHTANGLED& r);
};
