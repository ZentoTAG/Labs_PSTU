#include <iostream>
using namespace std;

int main() {
	int n;

	if (n < 5) {
		n *= 3;
	}
	else if (n > 7) {
		n += 3;
	}
	else {
		n /= 10;
	}
	cout << n << endl;

	return 0;
}

