#include <iostream>

using namespace std;

int main() {
	float a = 10.4;
	float b = 9.13;

	cout << "a=" << a << " b=" << b << endl;

	float *ptr_a = &a;
	float *ptr_b = &b;

	float sum = *ptr_a + *ptr_b;

	cout << "a + b = " << sum << endl;

	return 0;
}


