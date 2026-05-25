#ifndef SET_H
#define SET_H

#include <iostream>
#include <map>
#include <stdexcept>
#include <algorithm>

template<typename T>
class Set {
    private:
        std::multimap<T, T> data; 

    public:
        Set() = default;
        explicit Set(int) {}
        Set(const Set&) = default;
        ~Set() = default;
        Set& operator=(const Set&) = default;

        Set operator+(const Set& other) const {
            Set result = *this;

            for (const auto& p : other.data) {
                if (result.data.find(p.first) == result.data.end()) {
                    result.data.insert(p);
                }
            }
            return result;
        }

        T& operator[](int index) {
            if (index < 0 || index >= static_cast<int>(data.size())) {
                throw std::out_of_range("Index out of range");
            }
            auto it = data.begin();
            std::advance(it, index);

            return const_cast<T&>(it->first);
        }

        const T& operator[](int index) const {
            if (index < 0 || index >= static_cast<int>(data.size())) {
                throw std::out_of_range("Index out of range");
            }
            auto it = data.begin();
            std::advance(it, index);

            return it->first;
        }

        int operator()() const { 
            return static_cast<int>(data.size()); 
        }

        void insert(const T& value) {
            if (data.find(value) == data.end()) {
                data.insert({value, value});
            }
        }

        void erase(const T& value) {
            auto it = data.find(value);

            if (it != data.end()) {
                data.erase(it);
            }
        }

        void clear() { 
            data.clear(); 
        }

        friend std::istream& operator>>(std::istream& in, Set<T>& set) {
            int size;

            std::cout << "Enter number of elements: ";
            in >> size;
            set.clear();

            int count = 0;

            while (count < size) {
                T elem;

                std::cout << "Element " << (count + 1) << ": ";
                in >> elem;

                if (set.data.find(elem) == set.data.end()) {
                    set.data.insert({elem, elem});
                    ++count;
                } 
                else {
                    std::cout << "Duplicate! Enter again" << std::endl;
                }
            }

            return in;
        }

        friend std::ostream& operator<<(std::ostream& out, const Set<T>& set) {
            out << "{ ";

            for (const auto& p : set.data) {
                out << p.first << " ";
            }
            out << "}";

            return out;
        }
};

#endif