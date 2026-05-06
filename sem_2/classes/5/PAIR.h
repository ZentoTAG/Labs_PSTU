#pragma once
#include "Object.h"
#include <iostream>
using namespace std;

class PAIR : public Object {
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
    int product() const;

    void Show();  // переопределение виртуальной функции

    PAIR& operator=(const PAIR& p);
    friend istream& operator>>(istream& in, PAIR& p);
    friend ostream& operator<<(ostream& out, const PAIR& p);
};
