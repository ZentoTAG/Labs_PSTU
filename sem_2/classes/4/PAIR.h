#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class PAIR {
protected:
    int first;
    int second;
public:
    PAIR();
    virtual ~PAIR();
    PAIR(int f, int s);
    PAIR(const PAIR& p);

    void set_first(int f);
    void set_second(int s);
    int get_first() const { return first; }
    int get_second() const { return second; }
    int product() const;  // вычисление произведения чисел

    PAIR& operator=(const PAIR& p);
    friend istream& operator>>(istream& in, PAIR& p);
    friend ostream& operator<<(ostream& out, const PAIR& p);
};
