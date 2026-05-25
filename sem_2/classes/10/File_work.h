#ifndef FWORK
#define FWORK

#include <fstream>
#include <iostream>
#include <string>
#include "Money.h"

int make_file(std::string path) {
    std::ofstream out(path);

    if (!out.is_open()) {
        std::cout << "File isn`t open" << std::endl;
        return -1;
    }

    unsigned int n = 0;
    Money m;
    std::cout << "Enter object count: ";
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cout << i + 1 << " object:" << std::endl;
        std::cin >> m;
        out << m << "\n";
    }

    out.close();

    return n;
}

int print_file(std::string path) {
    std::ifstream in(path);

    if (!in.is_open()) {
        std::cout << "Can`t open file" << std::endl;
        return -1;
    }
    int i = 0;
    Money m;
    
    while (in >> m) {
        std::cout << m << std::endl;
        i++;
    }

    in.close();

    return i;
}

int del_from_file(std::string path, Money m) {
    std::ifstream in(path);
    std::ofstream out("temp.txt");

    if (!in.is_open() || !out.is_open()) {
        std::cout << "Can`t open file" << std::endl;
        return -1;
    }

    int i = 0;
    Money other;

    while (in >> other) {
        if (in.eof()) {
            break;
        }
        
        if (m.GetRubles() != other.GetRubles() || m.GetPennies() != other.GetPennies()) {
            out << other;
            i++;
        }
    }
    in.close();
    out.close();
    remove(path.c_str());
    rename("temp.txt", path.c_str());

    return i;
}

int add_to_file(std::string path, int pos, int k) {
    std::ifstream in(path);
    std::ofstream out("temp.txt");

    if(!in.is_open() || !out.is_open()) {
        std::cout << "Can`t open file" << std::endl;
        return -1;
    }
    int i = 0, l = 0;
    Money other;

    while(in >> other) {
        if(in.eof()) {
            break;
        }
        i++;
        if (i == pos) {
            Money n;
            for (int j = 0; j < k; j++) {
                std::cout << "Enter " << j + 1 << " object:" << std::endl;
                std::cin >> n;
                out << n;
                l++;
            }
        }
        out << other;
    }
    in.close();
    out.close();
    remove(path.c_str());
    rename("temp.txt", path.c_str());

    return l;
}

int add_to_end(std::string path, int k) {
    std::ofstream out(path, std::ios::app);

    if (!out.is_open()) {
        std::cout << "Can`t open file" << std::endl;
        return -1;
    }
    Money n;
    for (int i = 0; i < k; i++) {
        std::cout << "Enter " << i + 1 << "object: ";
        std::cin >> n;
        out << n;
    }

    return k;
}

int increase_file(std::string path, Money m) {
    std::ifstream in(path);
    std::ofstream out("temp.txt");

    if (!in.is_open() || !out.is_open()) {
        std::cout << "Can`t open file" << std::endl;
        return -1;
    }

    int i = 0;
    std::string answ;
    Money other;
    Money summ(1, 50);

    while (in >> other) {
        if (in.eof()) {
            break;
        }
        
        if (m.GetRubles() == other.GetRubles() && m.GetPennies() == other.GetPennies()) {
            other = other + summ;
            i++;
        }
        out << other;
    }
    in.close();
    out.close();
    remove(path.c_str());
    rename("temp.txt", path.c_str());

    return i;
}

    
#endif