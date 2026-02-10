#include <iostream>
using namespace std;

int main() {
	const int n = 7;
	int array[n] = {1, 2, 100, 115, 107};
	bool Flag = true;

	for (int i = 1; i < n; i++) {
		if (array[i] < array[i - 1]) {
			Flag = false;
			break;
		}
	}

	if (Flag) { cout << "norm"; }
	else { cout << "ne poryadok";}

	return 0;
	
}