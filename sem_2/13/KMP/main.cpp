#include <iostream>
#include <string>

using namespace std;

int kmp_search(string text, string ptn) {
    int size_line = text.size();
    int size_ptn = ptn.size();

    if (size_line == 0 || size_line < size_ptn) {
        return -1;
    }

    int * pi = new int[size_ptn];

    pi[0] = 0;
    for (int i = 1, j = 0; i < size_ptn; i++) {
        while (j > 0 && ptn[i] != ptn[j]) {
            j = pi[j - 1];
        }

        if (ptn[i] == ptn[j]) {
            j++;
        }
        pi[i] = j;
    }

    for (int i = 0, j = 0; i < size_line; i++) {
        while (j > 0 && text[i] != ptn[j]) {
            j = pi[j - 1];
        }
        if (text[i] == ptn[j]) {
            j++;
        }
        if (j == size_ptn) {
            delete[] pi;
            return i - size_ptn + 1;
        }
    }

    delete[] pi;
    return -1;
}

int main() {
    const char* text = "skibididoppdopdopyes yes";
    const char* pattern = "kibidi";

    int idx = kmp_search(text, pattern);
    if (idx != -1) {
        cout << idx << endl;
    } else {
        cout << "Not found" << endl;
    }

    return 0;
}