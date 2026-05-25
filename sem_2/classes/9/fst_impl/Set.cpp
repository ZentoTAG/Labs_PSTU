#include <iostream>
#include "Set.h"
#define MAX_SIZE 8

Set::Set() : size(0), data(nullptr) {}

Set::Set(int size) : size(size), data(nullptr) {
    if (size > MAX_SIZE) {
        throw 1;
    }

    if (size > 0) {
        data = new int[size];
    }

    for (int i = 0; i < size; i++) {
        data[i] = 0;
    }
}

Set::Set(const Set &obj) {
    size = obj.size;
    data = nullptr;

    if (size > 0) {
        data = new int[size];

        for (int i = 0; i < size; i++) {
            data[i] = obj.data[i];
        }
    }
}

Set::~Set() {
    if (data != nullptr) {
        delete[] data;
    }
}

Set& Set::operator=(const Set &obj) {
    if (&obj == this) {
        return *this;
    }

    if (data != nullptr) {
        delete[] data;
        data = nullptr;
    }
    
    size = obj.size;

    if (size > 0) {
        data = new int[size]; 

        for (int i = 0; i < size; i++) {
            data[i] = obj.data[i];
        }
    }

    return *this;
}

const int& Set::operator[](int idx) const{
    if (idx < 0) {
        throw 2;
    }
    else if (idx >= size) {
        throw 3;
    }

    return data[idx];
}

int Set::operator()() {
    return size;
}

Set Set::operator+(const Set &obj) {
    int new_size = size;
    int * temp = new int[size + obj.size];

    for (int i = 0; i < size; i++) {
        temp[i] = data[i];
    }

    for (int i = 0; i < obj.size; i++) {
        bool isIn = false;
        for (int j = 0; j < new_size; j++) {
            if (temp[j] == obj.data[i]) {
                isIn = true;
                break;
            }
        }
        if (!isIn) {
            temp[new_size++] = obj.data[i];
        }
    }
    if (new_size > MAX_SIZE) {
        delete[] temp;
        throw 1;
    }

    Set res(new_size);

    for (int i = 0; i < new_size; i++) {
        res.data[i] = temp[i];
    }
    delete[] temp;
    return res;  
}

std::istream& operator>>(std::istream &in, Set &obj) {
    if (obj.data == nullptr || obj.size == 0) {
        std::cout << "Size of set is 0" << std::endl;
        return in;
    }

    for (int i = 0; i < obj.size; i++) {
        int num;
        bool isIn = false;

        std::cout << "Enter element " << i + 1 << ": ";
        in >> num;

        for (int j = 0; j < obj.size; j++) {
            if (obj.data[j] == num) {
                isIn = true;
                break;
            }
        }

        if (!isIn) {
            obj.data[i] = num;
        }
    } 
        
    return in;
}
std::ostream& operator<<(std::ostream &out, const Set &obj) {
    if (obj.data == nullptr) {
        out << "{}" << std::endl;
        
        return out;
    }
    
    std::cout << "{"; 
    for (int i = 0; i < obj.size; i++) {
        out << obj.data[i] << " "; 
    }
    out << "}" << std::endl;

    return out;
}

Set& Set::operator++() {
    if (size + 1 > MAX_SIZE) {
        throw 1;
    }

    int num;
    std::cout << "Enter num: ";
    std::cin >> num;

    for (int i = 0; i < size; i++) {
        if (num == data[i]) {
            return *this;
        }
    }
    int * new_data = new int[size + 1];
    
    for (int i = 0; i < size; i++) {
        new_data[i] = data[i];
    }
    new_data[size] = num;
    size++;

    delete[] data;
    data = new_data;

    return *this;
}

Set Set::operator++(int) {
    if (size + 1 > MAX_SIZE) {
        throw 1;
    }

    Set old = *this;
    ++(*this);

    return old;
}