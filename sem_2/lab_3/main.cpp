#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a = 0.1, b = 1.0;
    double eps = 0.0001;
    double step = (b - a) / 10.0;
    
    for (double x = a; x <= b + step/2; x += step) {
        double sn = x;
        double term = x;
        for (int n = 1; n <= 10; n++) {
            term *= -x * x / ((2 * n) * (2 * n + 1));
            sn += term;
        }
        
        double se = x;
        term = x;
        int n = 1;
        while (fabs(term) > eps) {
            term *= -x * x / ((2 * n) * (2 * n + 1));
            se += term;
            n++;
        }
        
        double y = sin(x);
        
        cout << "x=" << x << " SN=" << sn << " SE=" << se << " Y=" << y << endl;
    }
    
    return 0;
}
