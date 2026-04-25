#include <iostream>
using namespace std;

class My_class {
    unsigned int first;
    unsigned int second;
public:
    int cost(unsigned int a, unsigned int b) { 
        return a * b;                        
    }
};

int main() {
    My_class mc;
    cout << mc.cost(10, 5) << endl; // Выведет 50
    return 0;
}
