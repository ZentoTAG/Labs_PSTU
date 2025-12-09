#include <iostream>
#include <cmath>
using namespace std;

int main(){
	float x, factorial, sum;
	int n;

	cin >> n >> x;
	sum = 1 + x;
	factorial = 1;

	for (int i = 2; i <= n; i++) {
		factorial *= i;
		sum += (pow(x, i) / factorial);
	}

	cout << sum << endl;
	return 0;
}