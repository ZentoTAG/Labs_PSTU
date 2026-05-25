#include <iostream>
#include "Set.h"
#include "Iterator.h"

Set::Set() : size(0), data(nullptr) {
    beg.elem = nullptr;
    end.elem = nullptr;
}

Set::Set(int size) : size(size) {
    if (size > 0) {
        data = new int[size];
        beg.elem = &data[0];
        end.elem = &data[size];
    }
    else {
        beg.elem = nullptr;
        end.elem = nullptr;
    }
    
}

Set::Set(const Set &obj) {
    size = obj.size;

    if (size > 0) {
        data = new int[size];

        for (int i = 0; i < size; i++) {
            data[i] = obj.data[i];
        }
        beg.elem = &data[0];
        end.elem = &data[size];
    }
    else {
        beg.elem = nullptr;
        end.elem = nullptr;
    }
}

Set::~Set() {
    if (data != nullptr) {
        delete[] data;
        beg.elem = nullptr;
        end.elem = nullptr;
    }
}

Set& Set::operator=(const Set &obj) {
    if (&obj == this) {
        return *this;
    }
    delete[] data;

    data = nullptr;
    size = obj.size;

    if (size > 0) {
        data = new int[size]; 

        for (int i = 0; i < size; i++) {
            data[i] = obj.data[i];
        }

        beg.elem = &data[0];
        end.elem = &data[size];
    }
    else {
        beg.elem = nullptr;
        end.elem = nullptr;
    }

    return *this;
}

int& Set::operator[](int idx) {
    if (idx >= 0 && idx < size) {
        return data[idx];
    }
    throw std::out_of_range("Index out of range");
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

    int count = 0;
    while (count < obj.size) {
        int num;
        std::cout << "Enter element " << (count + 1) << ": ";
        in >> num;

        bool isIn = false;
        for (int i = 0; i < count; ++i) {
            if (obj.data[i] == num) {
                isIn = true;
                break;
            }
        }

        if (!isIn) {
            obj.data[count++] = num;
        } else {
            std::cout << "Duplicate! Enter again" << std::endl;
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

Iterator Set::fst() {
    return beg;
}

Iterator Set::last() {
    return end;
}