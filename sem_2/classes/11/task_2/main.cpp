#include <iostream>
#include <vector>
#include "Money.h"

typedef std::vector<Money> Vec;

Vec make_vector(int n) {
    Vec v;

    for (int i = 0; i < n; i++) {
        Money m;
        m.SetRubles(rand() % 151);
        m.SetPennies(rand() % 151);
        v.push_back(m);
    }

    return v;
}

void print_vector(Vec v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

Money max_elem(Vec v) {
    Money max = v[0];

    for (int i = 1; i < v.size(); i++) {
        if (max < v[i]) {
            max = v[i];
        }
    }

    return max;
}

int min_elem(Vec v) {
    Money min = v[0];
    int m_pos = 0;

    for (int i = 1; i < v.size(); i++) {
        if (min > v[i]) {
            min = v[i];
            m_pos = i;
        }
    }

    return m_pos;
}

Money average_vector(Vec v) {
    Money average;

    for (int i = 0; i < v.size(); i++) {
        average = average + v[i];
    }

    int n = v.size();

    return average / n;
}

void add_elem(Vec &v, Money elem) {
    v.insert(v.begin(), elem);
}

void del_elem(Vec &v, int pos) {
    v.erase(v.begin() + pos);
}

void increase_vector(Vec &v) {
    Money val = average_vector(v);

    for (int i = 0; i < v.size(); i++) {
        v[i] = v[i] + val;
    }
}

int main() {
    srand(time(0));
    
    try {
        int size;
        Vec v;

        std::cout << "Enter size of vector: ";
        std::cin >> size;

        v = make_vector(size);
        print_vector(v);

        add_elem(v, max_elem(v));
        print_vector(v);

        del_elem(v, min_elem(v));
        print_vector(v);

        increase_vector(v);
        print_vector(v);
    }
    catch (int) {
        std::cout << "Error" << std::endl;
    }

    return 0;
}