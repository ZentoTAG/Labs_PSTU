#include <iostream>
#include <string>

using namespace std;

int boyer_moore_search(string text, string ptn) {
    int size_line = text.size();
    int size_ptn = ptn.size();

    if (size_line == 0 || size_line < size_ptn) {
        return -1;
    }

    const int ALPHABET_SIZE = 256;
    int alpha[ALPHABET_SIZE];

    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        alpha[i] = -1;
    }

    for (int i = 0; i < size_ptn; ++i) {
        alpha[ptn[i]] = i;
    }

    int * suff = new int[size_ptn];
    int * shift = new int[size_ptn];

    suff[size_ptn - 1] = size_ptn;
    int g = size_ptn - 1, f = size_ptn - 1;
    for (int i = size_ptn - 2; i >= 0; --i) {
        if (i > g && suff[i + size_ptn - 1 - f] < i - g) {
            suff[i] = suff[i + size_ptn - 1 - f];
        } 
        else {
            if (i < g) {
                g = i;
            }
            f = i;

            while (g >= 0 && ptn[g] == ptn[size_ptn - 1 - (f - g)]) {
                --g;
            }
            suff[i] = f - g;
        }
    }

    for (int i = 0; i < size_ptn; i++) {
        shift[i] = size_ptn;
    }

    int j = 0;
    for (int i = size_ptn - 1; i >= 0; i--) {
        if (suff[i] == i + 1) {
            for (; j < size_ptn - 1 - i; j++) {
                if (shift[j] == size_ptn) shift[j] = size_ptn - 1 - i;
            }
        }
    }
    for (int i = 0; i <= size_ptn - 2; i++) {
        shift[size_ptn - 1 - suff[i]] = size_ptn - 1 - i;
    }

    int pos = 0;
    while (pos <= size_line - size_ptn) {
        int j = size_ptn - 1;

        while (j >= 0 && ptn[j] == text[pos + j]) {
            --j;
        }
        if (j < 0) {
            delete[] suff;
            delete[] shift;
            return pos;
        }
        int badShift = j - alpha[text[pos + j]];

        if (badShift < 1) {
            badShift = 1;
        }
        
        int goodShift = shift[j];
        pos += (badShift > goodShift) ? badShift : goodShift;
    }

    delete[] suff;
    delete[] shift;
    return -1;
}

int main() {
    string text = "skibididoppdopdopyes yes";
    string pattern = "kibidi";

    int idx = boyer_moore_search(text, pattern);
    if (idx != -1) {
        cout << idx << endl;
    } else {
        cout << "Not found" << endl;
    }

    return 0;
}