#include <iostream>
#include "set.h"

int main() {
    Set<int> mySet;
    
    std::cout << "Enter elements for the set:\n";
    std::cin >> mySet;
    
    std::cout << mySet << std::endl;
    
    mySet.add_max();
    std::cout << mySet << std::endl;
    
    mySet.del_min();
    std::cout << mySet << std::endl;
    
    mySet.increase_average();
    std::cout << mySet << std::endl;
    
    return 0;
}