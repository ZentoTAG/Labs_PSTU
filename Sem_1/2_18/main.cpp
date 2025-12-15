#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, reversed, lastD;

	cin >> n;
	reversed = 0;

	while (n > 0) {
		lastD = n % 10;
		reversed = reversed * 10 + lastD;
		n /= 10;
	}

	cout << reversed << endl;
	return 0;
}