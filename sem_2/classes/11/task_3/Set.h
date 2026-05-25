#ifndef SET
#define SET
#include <iostream>
#include <vector>

template <class T>
class Set {
    private:
        std::vector<T> v;
    public:
        Set();
        Set(int);
        Set (const Set<T>&);
        ~Set();

        Set<T>& operator=(const Set<T>&);
        Set<T> operator+(const Set<T>&);

        T& operator[](int);
        int operator()();
        
        friend std::istream& operator>>(std::istream &in, Set<T> &obj) {
            if (obj.v.size() == 0) {
                std::cout << "Size of set is 0" << std::endl;
                return in;
            }

            int count = 0;
            while (count < obj.v.size()) {
                T elem;
                std::cout << "Enter element " << (count + 1) << ": " << std::endl;
                in >> elem;

                bool isIn = false;
                for (int i = 0; i < count; ++i) {
                    if (obj.v[i] == elem) {
                        isIn = true;
                        break;
                    }
                }

                if (!isIn) {
                    obj.v[count++] = elem;
                } else {
                    std::cout << "Duplicate! Enter again" << std::endl;
                }
            }
            return in;
        }

        friend std::ostream& operator<<(std::ostream &out, const Set<T> &obj) {
            if (obj.v.size() == 0) {
                out << "{}" << std::endl;
        
                return out;
            }
    
            out << "{ "; 
            for (int i = 0; i < obj.v.size(); i++) {
                out << obj.v[i] << " "; 
            }
            out << "}" << std::endl;

            return out;
        }

        void add_elem(T);
        void del_elem(int);
        T max_elem();
        int min_elem();
        T average_set();
        void increase_set();

};
#endif

template <class T>
Set<T>::Set() {
    v = std::vector<T>();
}

template <class T>
Set<T>::Set(int size) {
    if (size > 0) {
        v = std::vector<T>(size);
    }
}

template <class T>
Set<T>::Set(const Set &obj) {
    int size = obj.v.size();

    if (size > 0) {
        v = std::vector<T>(size);

        for (int i = 0; i < size; i++) {
            v[i] = obj.v[i];
        }
    }
}

template <class T>
Set<T>::~Set() {}

template <class T>
Set<T>& Set<T>::operator=(const Set &obj) {
    if (&obj == this) {
        return *this;
    }
    
    v = obj.v;

    return *this;
}

template <class T>
T& Set<T>::operator[](int idx) {
    if (idx >= 0 && idx < v.size()) {
        return v[idx];
    }
    throw std::out_of_range("Index out of range");
}

template <class T>
int Set<T>::operator()() {
    return v.size();
}

template <class T>
Set<T> Set<T>::operator+(const Set<T> &obj) {
    int new_size = v.size();
    std::vector<T> v_temp(new_size + obj.v.size());

    for (int i = 0; i < v.size(); i++) {
        v_temp.push_back(v[i]);
    }

    for (int i = 0; i < obj.v.size(); i++) {
        bool isIn = false;
        for (int j = 0; j < new_size; j++) {
            if (v_temp[j] == obj.v[i]) {
                isIn = true;
                break;
            }
        }
        if (!isIn) {
            v_temp.push_back(obj.v[i]);
            new_size++;
        }
    }

    Set<T> res(new_size);
    for (int i = 0; i < new_size; i++) {
        res.v[i] = v_temp[i];
    }

    return res;  
}

template<class T>
T Set<T>::max_elem() {
    if (v.size() <= 0) {
        throw std::out_of_range("Set is empty");
    }

    T max = v[0];
    int pos = 0;

    for (int i = 1; i < v.size(); i++) {
        if (max < v[i]) {
            max = v[i];
            pos = i;
        }
    }
    del_elem(pos);
    
    return max;
}

template<class T>
int Set<T>::min_elem() {
    if (v.size() <= 0) {
        throw std::out_of_range("Set is empty");
    }

    T min = v[0];
    int m_pos = 0;

    for (int i = 1; i < v.size(); i++) {
        if (min > v[i]) {
            min = v[i];
            m_pos = i;
        }
    }

    return m_pos;
}

template<class T>
T Set<T>::average_set() {
    if (v.size() <= 0) {
        throw std::out_of_range("Set is empty");
    }

    T average = 0;

    for (int i = 0; i < v.size(); i++) {
        average += v[i];
    }

    int n = v.size();
    

    return average / n;
}

template <class T>
void Set<T>::add_elem(T elem) {
    v.insert(v.begin(), elem);
}

template <class T>
void Set<T>::del_elem(int pos) {
    v.erase(v.begin() + pos);
}

template <class T>
void Set<T>::increase_set() {
    T val = average_set();

    for (int i = 0; i < v.size(); i++) {
        v[i] = v[i] + val;
    }
}