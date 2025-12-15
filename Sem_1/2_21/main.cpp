#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n, temp, num;
	bool flag = true;

	cin >> n;
	cin >> temp;

	for (int i = 1; i < n; i++) {
		cin >> num;
		if (num >= temp) { flag = true; }
		else { flag = false; }
		temp = num;
	}

	if (flag) { cout << "yes" << endl; }
	else { cout << "no"; }
	return 0;
}