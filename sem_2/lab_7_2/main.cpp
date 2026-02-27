#include <iostream>
#include <cstdarg>
using namespace std;

int sum(int k, ...) {
    va_list args;
    va_start(args, k);
    
    int s = 0;
    int prev = va_arg(args, int);  
    for (int i = 1; i < k; i++) {
        int cur = va_arg(args, int);
        s += prev * cur; 
        prev = cur;
    }
    
    va_end(args);
    return s;
} 



int main() {
	cout << sum(4, 1, 2, 3, 4);
	

	return 0;
}
