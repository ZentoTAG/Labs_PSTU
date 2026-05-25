#include <iostream>
#include <map>
#include <numeric>
#include <limits>
#include "Money.h"

void print_multimap(const std::multimap<double, Money> &mm) {
    if (mm.empty()) {
        std::cout << "Multimap is empty" << std::endl;
        return;
    }

    for (const auto& p : mm) {
        std::cout << "Key: " << p.first << " -> ";
        std::cout << p.second;
    }
    std::cout << std::endl;
}

std::multimap<double, Money>::iterator add_max(std::multimap<double, Money> &mm) {
    if (mm.empty()) {
        return mm.end();
    }
    auto maxIt = mm.begin();

    for (auto it = mm.begin(); it != mm.end(); ++it) {
        if (it->second > maxIt->second) { 
            maxIt = it;
        }
    }

    return maxIt;
}

void del_min(std::multimap<double, Money> &mm) {
    if (mm.empty()) {
        return;
    }
    auto minIt = mm.begin();

    for (auto it = mm.begin(); it != mm.end(); ++it) {
        if (it->second < minIt->second) {
            minIt = it;
        }
    }
    mm.erase(minIt);
}

void averange_multimap(std::multimap<double, Money> &mm) {
    if (mm.empty()) {
        return;
    }
    Money sum(0, 0);

    for (const auto& p : mm) {
        sum = sum + p.second; 
    }
    Money mean = sum / static_cast<int>(mm.size());

    for (auto& p : mm) {
        p.second = p.second + mean;
    }
}

int main() {
    std::multimap<double, Money> mm;

    mm.insert({1.0, Money(5, 50)});
    mm.insert({2.0, Money(3, 20)});
    mm.insert({3.0, Money(8, 10)});
    mm.insert({4.0, Money(1, 75)});
    mm.insert({5.0, Money(4, 40)});

    print_multimap(mm);

    auto maxIt = add_max(mm);

    if (maxIt != mm.end()) {
        Money maxMoney = maxIt->second;
        double minKey = mm.begin()->first;
        double newKey = minKey - 1.0;
        mm.insert({newKey, maxMoney});
        print_multimap(mm);
    }

    if (!mm.empty()) {
        double deletedKey = mm.begin()->first;
        Money deletedValue = mm.begin()->second;
        del_min(mm);
        print_multimap(mm);
    }

    averange_multimap(mm);
    print_multimap(mm);

    return 0;
}