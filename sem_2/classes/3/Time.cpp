#include "Time.h"
#include <iostream>
using namespace std;

Time& Time::operator=(const Time& t) {
    if (this == &t) return *this;
    min = t.min;
    sec = t.sec;
    return *this;
}

// Префиксный ++a
Time& Time::operator++() {
    int total = min * 60 + sec + 1;
    min = total / 60;
    sec = total % 60;
    return *this;
}

// Постфиксный a++
Time Time::operator++(int) {
    Time old(*this);
    int total = min * 60 + sec + 1;
    min = total / 60;
    sec = total % 60;
    return old;
}

Time Time::operator+(const Time& t) {
    int total1 = min * 60 + sec;
    int total2 = t.min * 60 + t.sec;
    int sum = total1 + total2;
    return Time(sum / 60, sum % 60);
}

Time Time::operator+(int seconds) const {
    int total = min * 60 + sec + seconds; 
    if (total < 0) total = 0;             
    return Time(total / 60, total % 60);  
}

Time Time::operator-(int seconds) const {
    int total = min * 60 + sec - seconds;  
    if (total < 0) total = 0;             
    return Time(total / 60, total % 60); 
}
istream& operator>>(istream& in, Time& t) {
    cout << "min? ";
    in >> t.min;
    cout << "sec? ";
    in >> t.sec;
    return in;
}

ostream& operator<<(ostream& out, const Time& t) {
    out << t.min << " : " << t.sec;
    return out;
}
