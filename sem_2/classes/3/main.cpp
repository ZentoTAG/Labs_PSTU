#include "Time.h"
#include <iostream>
using namespace std;

int main() {
    Time a, b, c, d, e;
    cin >> a;
    cin >> b;
    ++a;
    cout << a << endl;
    c = (a++) + b;
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    cout << "c=" << c << endl;
    d = a + 90;   
    cout << "a + 90s = " << d << endl;
    
    e = a - 45;  
    cout << "a - 45s = " << e << endl;
    return 0;
}
