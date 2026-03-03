#include <iostream>

using namespace std;

int main() {
	int a = 10;
	cout << a << " ";

	int *ptr_a = &a;

	*ptr_a = 4209;

	cout << a;
	
	return 0;
}
