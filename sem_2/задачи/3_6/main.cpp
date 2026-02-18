#include <iostream>
using namespace std;

int main() {
	const int n = 6;
	int arr[n] = {1, 2, 4, 3, 100, 0};
	int k;

	cin >> k;
	k = k % n;

	for (int i=0; i < n; i++) { cout << arr[i] << " ";}

	int tmp[n];
	for (int i=0; i < n; i++) {
		int new_pos = i-k;
		if (new_pos < 0) { new_pos += n; }
		tmp[new_pos] = arr[i];
	} 


	cout << endl;
	for (int i=0; i < n; i++) {
		arr[i] = tmp[i];
		cout << arr[i] << " ";
	}
	
	return 0;
}
