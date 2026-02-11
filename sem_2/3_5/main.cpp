#include <iostream>
using namespace std;

int main() {
	const int n = 5;
	int arr[n] = {10, 5, 0, 100, 102};
	int max = arr[0];

	for (int i=1; i < n; i++) {
		if (arr[i] > max) {max = arr[i]; }
	}

	cout << max;
	return 0;
	
	
	
}
