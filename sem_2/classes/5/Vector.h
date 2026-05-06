#pragma once
#include "Object.h"
#include <iostream>
using namespace std;

class Vector {
public:
    Vector();
    Vector(int n);
    ~Vector();
    void Add(Object* p);
    friend ostream& operator<<(ostream& out, const Vector& v);
private:
    Object** beg;
    int size;
    int cur;
};
