#include <iostream>
#include "Set.h"

template<typename T>
T max_elem(const Set<T>& set) {
    if (set() == 0) {
        throw std::runtime_error("Set is empty");
    }

    return set[set() - 1];
}

template<typename T>
T min_elem(const Set<T>& set) {
    if (set() == 0) {
        throw std::runtime_error("Set is empty");
    }

    return set[0];
}

template<typename T>
void add_max(Set<T>& set) {
    if (set() == 0) {
        return;
    }
    T maxVal = max_elem(set);
    T minVal = min_elem(set);
    set.erase(maxVal);

    Set<T> newSet;
    newSet.insert(maxVal);    

    for (int i = 0; i < set(); i++) {
        newSet.insert(set[i]);
    }
    set = newSet;
}

template<typename T>
void del_min(Set<T>& set) {
    if (set() == 0) {
        return;
    }
    T minVal = min_elem(set);
    set.erase(minVal);
}

template<typename T>
void averange_set(Set<T>& set) {
    if (set() == 0) {
        return;
    }
    T sum = T();

    for (int i = 0; i < set(); i++) {
        sum = sum + set[i];
    }
    T mean = sum / set();
    Set<T> newSet;
    
    for (int i = 0; i < set(); i++) {
        newSet.insert(set[i] + mean);
    }
    set = newSet;
}

int main() {
    Set<int> s;
    std::cin >> s;
    std::cout << s << std::endl;

    int maxVal = max_elem(s);
    add_max(s);
    std::cout << s << std::endl;

    int minVal = min_elem(s);
    del_min(s);
    std::cout << s << std::endl;

    averange_set(s);
    std::cout << s << std::endl;
    
    return 0;
}