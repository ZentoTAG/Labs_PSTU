#include <iostream>
#include <set>
#include <numeric>
#include <algorithm>

template<typename T>
void print_data(const std::multiset<T> &ms) {
    for (const auto& elem : ms) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

void addMaxElement(std::multiset<double> &ms) {
    if (ms.empty()) {
        return;
    }
    auto maxIt = std::prev(ms.end());
    double maxVal = *maxIt;
    ms.insert(maxVal);
}


void del_min(std::multiset<double> &ms) {
    if (ms.empty()) {
        return;
    }
    auto minIt = ms.begin();
    ms.erase(minIt);
}

void averange(std::multiset<double> &ms) {
    if (ms.empty()) {
        return;
    }

    double sum = std::accumulate(ms.begin(), ms.end(), 0.0);
    double avg = sum / ms.size();
    std::multiset<double> transformed;

    for (double x : ms) {
        transformed.insert(x + avg);
    }
    ms = std::move(transformed);
}

int main() {
    std::multiset<double> data = {1.5, 2.0, 3.0, 2.0, 4.5, 1.0};

    print_data(data);

    addMaxElement(data);
    print_data(data);

    del_min(data);
    print_data(data);

    averange(data);
    print_data(data);

    return 0;
}