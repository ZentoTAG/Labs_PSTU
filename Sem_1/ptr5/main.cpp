#include <iostream>

using namespace std;

int main() {
	int n, factorial = 1;
	int *ptr_n = &n;
	int *ptr_factorial = &factorial;

	cin >> *ptr_n;

	for (size_t i = 1; i <= *ptr_n; i++) {
		*ptr_factorial *= i;
	}
	cout << factorial;
}