#include <iostream>
#include <string>

using namespace std;

int naive_search(string a, string b) {
    int a_size = a.size();
    int b_size = b.size();

    if (a_size < b_size || b_size == 0) {
        return -1;
    }
    for (int i = 0; i <= a_size - b_size; i++) {
        int j = 0;
        
        while (j < b_size && b[j] == a[i + j]) {
            j++;
        }

        if (j == b_size) {
            return i;
        }
    }
    return -1;
}

int main() {
    string a = "tralolelobobritobanditotralala";
    string b = "bobritobandito";

    int idx = naive_search(a, b);

    if (idx == -1) {
        cout << "Substring not found" << endl;
    }
    else {
        cout << "Substring found, index: " << idx << endl;
    }

    return 0;
}