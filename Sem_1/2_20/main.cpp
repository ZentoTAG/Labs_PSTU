#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n;
	double s;
	bool flag = false;
	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		if (abs(sin(n + i / double(n)) - s) < 0.000001) {
			flag = true;
			break;
		}
	}

	if (flag == 1) { cout << "yest"; }
	else { cout << "nety"; }
	return 0;
}