#include <iostream>
#include "PAIR.h"
#include "RIGHTANGLED.h"
using namespace std;

void f1(PAIR& p) {
    p.set_first(100);
    cout << "f1: " << p << endl;
}

PAIR f2() {
    RIGHTANGLED r(3, 4);
    return r; 
}

int main() {
    PAIR a;
    cin >> a;
    cout << "a: " << a << endl;
    cout << "Произведение: " << a.product() << endl;

    PAIR b(5, 7);
    cout << "b: " << b << endl;
    a = b;
    cout << "a после присваивания: " << a << endl;

    RIGHTANGLED c;
    cin >> c;
    cout << "c: " << c << endl;
    cout << "Гипотенуза: " << c.hypotenuse() << endl;

    f1(c);           
    a = f2();        
    cout << "a после f2(): " << a << endl;

    return 0;
}
