#include <iostream>
using namespace std;

int main() {
	int n, s;
	bool flag = false;
	cout << "enter n and s" << endl;
	cin >> n >> s;
	
	while (n > 0 && !flag) {
		if (n % 10 == s) {
			flag = true;
		}
		n /= 10;
	}

	if (flag) { cout << "s in n" << endl; }
	else if (!flag) { cout << "s not in n" << endl; }

	return 0;
}