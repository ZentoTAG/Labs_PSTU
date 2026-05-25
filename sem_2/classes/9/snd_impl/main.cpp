#include <iostream>
#include "Set.h"
#include "Error.h"

int main() {
    try {
        Set a(3);
        std::cin >> a;
        std::cout << a << std::endl;

        Set b(8);
        std::cin >> b;
        std::cout << b << std::endl;

        Set c(10);

        //std::cout << b + a << std::endl;
        //std::cout << b[-1] << std::endl;
        //std::cout << a[5] << std::endl;
        //b++;
    }
    catch (Error &e) {
        e.what();
    }

    return 0;
}