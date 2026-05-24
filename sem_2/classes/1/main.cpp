#include "calc.h"
#include <iostream>
using namespace std;

int main() {
    Calc c;              
    c.Init(10, 20);      
    c.Show();           
    c.Read();
    cout << c.cost()<< endl;          
    c.Show();            
    return 0;
}
