#include <iostream>
using namespace std;

const int N = 100;
void sum_matrix(int a[][N], int n) {
    int T_a[N][N];

    // Копирование матрицы
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            T_a[i][j] = a[i][j];
        }
    }

    //транспонирование матрицы
    for (int i=0; i < n; i++) {
        for (int j=i+1; j < n; j++) {
            int tmp = T_a[i][j];
            T_a[i][j] = T_a[j][i];
            T_a[j][i] = tmp;
        }
    }

    //сумма матриц
    for (int i=0; i < n; i++) {
        for (int j=0; j < n; j++) {
            a[i][j] = a[i][j] + T_a[i][j];
        }
    }
}
// вариант 3
int main() {
    int n;
    int k;
    cout << "n :";
    cin >> n;
    int arr[N][N];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> k;
            arr[i][j] = k;
        }
    }

    sum_matrix(arr, n);

    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
