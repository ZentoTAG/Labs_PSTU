#include <iostream>
#include <vector>
#include "Set.h"

int main() {
    srand(time(0));
    
    try {
        int size, pos;

        std::cout << "Enter size of set: ";
        std::cin >> size;

        Set<int> s(size);
        std::cout << "Enter elems of set: ";
        std::cin >> s;
        std::cout << s << std::endl;

        s.add_elem(s.max_elem());
        std::cout << s << std::endl;

        s.del_elem(s.min_elem());
        std::cout << s << std::endl;

        s.increase_set();
        std::cout << s << std::endl;
    }
    catch (int) {
        std::cout << "Error" << std::endl;
    }

    return 0;
}
