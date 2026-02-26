#include <iostream>
#include <clocale>
#include <string>
using namespace std;

// lab 7_1 // variant 21

int func(int* arr, int N) {
	int res = 0;
	for (int i = 0; i < N; i++) {
		if (arr[i] < 0) {
			res++;
		}
	}
	return res;
}

int func(string word) {
	int k = 0;
	word += ' ';
	char tmp = word[0];

	for (int i = 1; i < word.length(); i++) {
		if (word[i] == ' ') {
			if (word[i - 1] == tmp) {
				k++;
			}

			i++;

			if (i < word.length()) {
				tmp = word[i];
			}
		}
	}
	return k;
}

int main() {
	int ch;
	system("chcp 1251 > nul");
	setlocale(LC_ALL, "ru_RU.UTF-8");
	cout << "массив или строка? выбери 1 или 2";
	cin >> ch;

	if (ch == 1) {
		int n;
		cin >> n;
		int* arr = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> ch;
			arr[i] = ch;
		}
		cout << func(arr, n);
	}
	else if (ch == 2) {
		string word;
		cin.ignore();
		getline(cin, word);
		cout << func(word);
	}
	
	return 0;
}
