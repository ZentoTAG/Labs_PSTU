#include <iostream>
using namespace std;

int main() {
	int n, temp;
	bool plusFirst = false; 
	bool minusFirst = false;

	cout << "enter lenght of sequence ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (!plusFirst && !minusFirst) {
			if (temp > 0) { plusFirst = true; }
			else if (temp < 0) { minusFirst = true; }
		}
	}
	if (plusFirst) { cout << "first num is positive"; }
	else if (minusFirst) { cout << "first num is negative"; }
	return 0;
}