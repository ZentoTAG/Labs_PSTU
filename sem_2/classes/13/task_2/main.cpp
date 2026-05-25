#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void print_stack(stack<int> s) {
    if (s.empty()) {
        cout << "Stack is empty" << endl;
        return;
    }

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

vector<int> stackToVector(stack<int> s) {
    vector<int> v;

    while (!s.empty()) {
        v.push_back(s.top());
        s.pop();
    }
    reverse(v.begin(), v.end());
    return v;
}


void vectorToStack(stack<int> &s, const vector<int> &v) {
    stack<int> temp;

    for (int x : v) {
        temp.push(x);
    }

    while (!temp.empty()) {
        s.push(temp.top());
        temp.pop();
    }
}


void add_max(stack<int>& s) {
    if (s.empty()) {
        return;
    }
    vector<int> v = stackToVector(s);
    auto maxIt = max_element(v.begin(), v.end());
    int maxVal = *maxIt;
    v.insert(v.begin(), maxVal);

    while (!s.empty()) {
        s.pop();
    }
    vectorToStack(s, v);
}

void del_min(stack<int> &s) {
    if (s.empty()) {
        return;
    }
    vector<int> v = stackToVector(s);
    auto minIt = min_element(v.begin(), v.end());
    v.erase(minIt);

    while (!s.empty()) {
        s.pop();
    }
    vectorToStack(s, v);
}

void averange_stack(stack<int>& s) {
    if (s.empty()) {
        return;
    }
    vector<int> v = stackToVector(s);
    double sum = accumulate(v.begin(), v.end(), 0.0);
    double avg = sum / v.size();

    for (int& x : v) {
        x = static_cast<int>(x + avg); 
    }

    while (!s.empty()) {
        s.pop();
    }
    vectorToStack(s, v);
}

int main() {
    stack<int> s;

    for (int x : {5, 2, 8, 1, 9, 3}) {
        s.push(x);
    }

    print_stack(s);

    add_max(s);
    print_stack(s);

    del_min(s);
    print_stack(s);

    averange_stack(s);
    print_stack(s);

    return 0;
}