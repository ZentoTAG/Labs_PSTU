#include <iostream>
using namespace std;

int main() {
	int n, temp, max, min;
	cin >> n >> temp;

	max = temp;
	min = temp;

	for (int i = 1; i < n; i++) {
		cin >> temp;
		if (temp > max) { max = temp; }
		else if (temp < min) { min = temp; }
	}
	cout << max + min << endl;
	return 0;
}