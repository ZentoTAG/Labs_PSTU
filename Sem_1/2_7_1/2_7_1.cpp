#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, a;
	cin >> n;
	
	a = sqrt(n);

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++) {
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}