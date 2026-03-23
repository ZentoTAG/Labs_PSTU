#include <iostream>

using namespace std;

int main() {
	int n;
	float mx, mn, a;

	float *ptr_mx = &mx;
	float* ptr_mn = &mn;

	cin >> n;

	cin >> *ptr_mx;
	*ptr_mn = *ptr_mx;

	for (size_t i = 1; i < n; i++) {
		cin >> a;

		if (a > *ptr_mx) {
			*ptr_mx = a;
		}
		if (a < *ptr_mn) {
			*ptr_mn = a;
		}
	}
	cout << "max: " << *ptr_mx << " min: " << *ptr_mn;
}