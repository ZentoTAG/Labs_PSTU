#ifndef SET_H
#define SET_H

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

template<class T>
class Set {
    private:
        std::stack<T> st;

        std::vector<T> to_vector() const {
            std::stack<T> temp = st;
            std::vector<T> vec;

            while (!temp.empty()) {
                vec.push_back(temp.top());
                temp.pop();
            }
            std::reverse(vec.begin(), vec.end());

            return vec;
        }

        void from_vector(const std::vector<T> &vec) {
            std::stack<T> empty;
            std::swap(st, empty);

            for (const auto& elem : vec) {
                st.push(elem);
            }
        }

    public:
        Set() {}
        Set(int size) {}

        int size() const {
            return st.size();
        }

        T& operator[](int index) {
            std::vector<T> vec = to_vector();

            return vec[index];
        }

        friend std::istream& operator>>(std::istream &in, Set<T> &obj) {
            int n;
            std::cout << "Enter number of elements: ";
            in >> n;
            std::vector<T> tempVec;

            for (int i = 0; i < n; ++i) {
                T value;

                while (true) {
                    std::cout << "Enter element " << i + 1 << ": ";
                    in >> value;

                    if (std::find(tempVec.begin(), tempVec.end(), value) == tempVec.end()) {
                        tempVec.push_back(value);
                        break;
                    }
                    std::cout << "Duplicate element! Try again.\n";
                }
            }
            obj.from_vector(tempVec);

            return in;
        }

        friend std::ostream& operator<<(std::ostream &out, const Set<T> &obj) {
            std::vector<T> vec = obj.to_vector();
            out << "{ ";

            for (const auto& elem : vec) {
                out << elem << " ";
            }
            out << "}";

            return out;
        }

        void add_max();
        void del_min();
        void increase_average();
};

template<class T>
void Set<T>::add_max() {
    if (st.empty()) {
        return;
    }
    std::vector<T> vec = to_vector();
    auto maxIt = std::max_element(vec.begin(), vec.end());

    if (maxIt != vec.end()) {
        T maxElem = *maxIt;
        vec.erase(maxIt);
        vec.insert(vec.begin(), maxElem);
    }
    from_vector(vec);
}

template<class T>
void Set<T>::del_min() {
    if (st.empty()) {
        return;
    }
    std::vector<T> vec = to_vector();
    auto minIt = std::min_element(vec.begin(), vec.end());

    if (minIt != vec.end()) {
        vec.erase(minIt);
    }
    from_vector(vec);
}

template<class T>
void Set<T>::increase_average() {
    if (st.empty()) {
        return;
    }
    std::vector<T> vec = to_vector();
    T sum = 0;

    for (const auto& elem : vec) {
        sum += elem;
    }
    T mean = sum / static_cast<T>(vec.size());

    for (auto& elem : vec) {
        elem += mean;
    }
    from_vector(vec);
}

#endif