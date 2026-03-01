#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// lab 9, var. 3
int main() {
	string row;
	int s = 0;
	ifstream input("F1.txt");
	ofstream output("F2.txt");

	while (getline(input, row)) {
		if (row[0] == row[row.length() - 1]) {
			output << row << "\n";
			s += row.length();
		}
	}

	cout << s << endl;

	input.close();
	output.close();
	return 0;
}