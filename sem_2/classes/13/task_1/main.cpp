#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include "Money.h"


void print_vector(const std::vector<Money> &v) {
    for (const auto& m : v) {
        std::cout << m;
    }
    std::cout << std::endl;
}

int main() {
    std::vector<Money> v;
    int n;

    std::cout << "Enter number of elements: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Vector is empty" << std::endl;

        return 0;
    }

    for (int i = 0; i < n; i++) {
        std::cout << "Element " << i + 1 << std::endl;
        Money m;
        std::cin >> m;
        v.push_back(m);
    }

    print_vector(v);

    auto maxIt = max_element(v.begin(), v.end(), [](const Money& a, const Money& b) {
            long valA = a.GetRubles() * 100 + a.GetPennies();
            long valB = b.GetRubles() * 100 + b.GetPennies();

            return valA < valB;
        }
    );
    Money maxElem = *maxIt;
    v.insert(v.begin(), maxElem);
    print_vector(v);

    auto minIt = min_element(v.begin(), v.end(), [](const Money& a, const Money& b) {
            long valA = a.GetRubles() * 100 + a.GetPennies();
            long valB = b.GetRubles() * 100 + b.GetPennies();

            return valA < valB;
        }
    );
    v.erase(minIt);
    print_vector(v);

    Money sum = accumulate(v.begin(), v.end(), Money(0, 0));
    Money avg = sum / static_cast<int>(v.size());

    transform(v.begin(), v.end(), v.begin(), [avg](const Money& m) {
        return m + avg;
        }
    );

    print_vector(v);

    return 0;
}