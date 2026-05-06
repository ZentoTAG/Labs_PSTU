#include <iostream>
#include "Object.h"
#include "PAIR.h"
#include "RIGHTANGLED.h"
#include "Vector.h"
using namespace std;

int main() {
    Vector v(5);

    PAIR a;
    cin >> a;
    cout << "PAIR: " << a << endl;

    RIGHTANGLED b;
    cin >> b;
    cout << "RIGHTANGLED: " << b << endl;

    Object* p = &a;
    v.Add(p);

    p = &b;
    v.Add(p);

    cout << "\nСодержимое вектора (полиморфизм):" << endl;
    cout << v;

    return 0;
}
