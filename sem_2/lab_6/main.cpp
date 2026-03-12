#include <iostream>
#include <string>
using namespace std;

// lab_6 var_3
int main() {
    string alphabet = "aeiuyoAEIUYO";  
    string word = "";
    string s;
    bool has_glasniy = false;

    getline(cin, s);

    s += " ";

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            if (word != "" && !has_glasniy) {
                cout << word << endl;
            }
            word = "";
            has_glasniy = false;
            continue;
        }
        word += s[i];

        for (int j = 0; j < alphabet.length(); j++) {
            if (s[i] == alphabet[j]) {
                has_glasniy = true;
                break;
            }
        }
    }

    return 0;
}