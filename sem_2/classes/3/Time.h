#include <iostream>
using namespace std;

class Time {
    int min;
    int sec;
public:
    Time() : min(0), sec(0) {}
    Time(int m, int s) : min(m), sec(s) {}
    Time(const Time& t) : min(t.min), sec(t.sec) {}
    ~Time() {}

    void set_min(int m) { min = m; }
    void set_sec(int s) { sec = s; }
    int get_min() const { return min; }
    int get_sec() const { return sec; }

    Time& operator=(const Time&);
    Time& operator++();      // префиксный ++a
    Time operator++(int);    // постфиксный a++
    Time operator+(const Time&);
	Time operator+(int seconds) const;  // добавление секунд	
	Time operator-(int seconds) const;  // вычитание секунд

    friend istream& operator>>(istream& in, Time& t);
    friend ostream& operator<<(ostream& out, const Time& t);
};
