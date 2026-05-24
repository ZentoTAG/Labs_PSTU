#include "calc.h"  // латиница
#include <iostream>
using namespace std;

void Calc::Init(int f, int s) {
    first = f;
    second = s;
}

void Calc::Read() {
    cout << "first: ";
    cin >> first;
    cout << "second: ";
    cin >> second;
}

int Calc::cost() {
	return first*second;
}
void Calc::Show() {
    cout << "first = " << first << ", second = " << second << endl;
}
