#include <iostream>
using namespace std;

int main() {
	const int n = 6;
	int arr[n] = {1, -5, 10, 100, 6, 1024};
	int max, min;
	max = arr[0];
	max = arr[0];
	
	for (int i=0; i < n; i++) { cout << arr[i] << " ";}
	cout << endl;
	
	for (int i=1; i < n; i++) {
		if (arr[i] > max) { max = arr[i]; }
		else if (arr[i] < min) { min = arr[i]; }
	}

	cout << "min: " << min << endl << "max " << max;


	return 0;
}
