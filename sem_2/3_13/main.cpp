#include <iostream>
using namespace std;
int main()
{
	int k = 1;
	int tmp;
	const int n = 3;
	int arr[n][n] = {
	{3, 7, 0},
	{9, 4, 6},
	{5, 1, 2}
	};

	cin >> k;
	if (k >= n) { k = n - 1; }

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	// сортируем по строке k по возрастанию, переставляя столбцы матрицы
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {  // добавил j++
			if (arr[k][j] > arr[k][j + 1]) {
				// меняем столбцы местами
				for (int r = 0; r < n; r++) {
					tmp = arr[r][j];
					arr[r][j] = arr[r][j + 1];
					arr[r][j + 1] = tmp;
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	return 0;
}
