#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

template<typename T>
std::vector<T> stack_to_vector(const std::stack<T> &s) {
    std::stack<T> temp = s;
    std::vector<T> vec;

    while (!temp.empty()) {
        vec.push_back(temp.top());
        temp.pop();
    }
    std::reverse(vec.begin(), vec.end());

    return vec;
}

template<typename T>
void vector_to_stack(std::stack<T> &s, const std::vector<T> &vec) {
    std::stack<T> empty;
    std::swap(s, empty);

    for (const auto& elem : vec) {
        s.push(elem);
    }
}

template<typename T>
void print_stack(const std::stack<T> &s) {
    std::vector<T> vec = stack_to_vector(s);

    if (vec.empty()) {
        std::cout << "Stack is empty";
    }
    else {
        std::cout << "back -> ";

        for (size_t i = 0; i < vec.size(); ++i) {
            std::cout << vec[i];
            if (i != vec.size() - 1) {
                std::cout << " -> ";
            }
        }
        std::cout << " -> top";
    }
    std::cout << std::endl;
}

template<typename T>
void add_max(std::stack<T> &s) {
    if (s.empty()) return;
    
    std::vector<T> vec = stack_to_vector(s);
    T maxElem = *std::max_element(vec.begin(), vec.end());
    vec.insert(vec.begin(), maxElem);
    
    vector_to_stack(s, vec);
}

template<typename T>
void del_min(std::stack<T> &s) {
    if (s.empty()) return;
    
    std::vector<T> vec = stack_to_vector(s);
    auto minIt = std::min_element(vec.begin(), vec.end());

    if (minIt != vec.end()) {
        vec.erase(minIt);
    }
    
    vector_to_stack(s, vec);
}

template<typename T>
void average_vector(std::stack<T>& s) {
    if (s.empty()) {
        return;
    }
    
    std::vector<T> vec = stack_to_vector(s);
    T sum = 0;

    for (const auto& elem : vec) {
        sum += elem;
    }

    T mean = sum / static_cast<T>(vec.size());
    
    for (auto& elem : vec) {
        elem += mean;
    }
    
    vector_to_stack(s, vec);
}


int main() {
    std::stack<int> st;
    int size;

    std::cout << "Enter size: ";
    std::cin >> size;

    for (int i = 0; i < size; i++) {
        int x = rand() % 101 - 50;
        st.push(x);
    }
    
    print_stack(st);
    
    add_max(st);
    print_stack(st);
    
    del_min(st);
    print_stack(st);

    average_vector(st);
    print_stack(st);
    
    return 0;
}