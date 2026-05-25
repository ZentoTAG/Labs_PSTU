#include <iostream>
#include <map>
#include <algorithm>
#include <numeric>
#include <limits>

void print_multimap(const std::multimap<double, double> &mm) {

    if (mm.empty()) {
        std::cout << "Multimap is empty" << std::endl;
        return;
    }

    for (const auto& p : mm) {
        std::cout << "(" << p.first << ", " << p.second << ") ";
    }
    std::cout << std::endl;
}

std::multimap<double, double>::iterator max_elem(std::multimap<double, double> &mm) {
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

void del_min(std::multimap<double, double> &mm) {
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


void averange_multimap(std::multimap<double, double>& mm) {
    if (mm.empty()) {
        return;
    }
    double sum = 0.0;

    for (const auto& p : mm) {
        sum += p.second;
    }
    double mean = sum / mm.size();

    for (auto& p : mm) {
        p.second += mean;
    }
}

int main() {
    std::multimap<double, double> mm;
    mm.insert({1.0, 5.5});
    mm.insert({2.0, 3.2});
    mm.insert({3.0, 8.1});
    mm.insert({4.0, 1.7});
    mm.insert({5.0, 4.4});

    print_multimap(mm);
    auto maxIt = max_elem(mm);

    if (maxIt != mm.end()) {
        double maxValue = maxIt->second;
        double minKey = mm.begin()->first;
        double newKey = minKey - 1.0;
        mm.insert({newKey, maxValue});
    }

    if (!mm.empty()) {
        double minKeyBefore = mm.begin()->first;
        double minValueBefore = mm.begin()->second;

        del_min(mm);
        std::cout << "Min: " << minKeyBefore << ": " << minValueBefore << std::endl;
        print_multimap(mm);
    }

    averange_multimap(mm);
    print_multimap(mm);

    return 0;
}