#include <iostream>
#include "Set.h"
#include "Iterator.h"

int main() {
    Set set(5);
    std::cin >> set;
    std::cout << set << std::endl;

    std::cout << set[1] << std::endl;

    try {
        std::cout << set[10] << std::endl;
    }
    catch (std::out_of_range &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    set[4] = 10;
    std::cout << set << std::endl;
    Set new_set(3);
    std::cin >> new_set;

    Set c = set + new_set;
    std::cout << c << std::endl;

    std::cout << *(c.fst()) << " " << *(--c.last()) << std::endl;

    return 0;
}

