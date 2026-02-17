#include <iostream>
#include <cstdlib>
#include <ctime>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    srand(time(0));
    const int n = 100;
    int arr[n];
    int c;
    cout << "c: ";
    cin >> c;

    for (int i = 0; i < c; i++) {
        arr[i] = rand() % 200 - 100;
        cout << arr[i] << " ";
    }
    cout << endl;

    // 3
    for (int i = 0; i < c; i++) {
        if (arr[i] == 0) {
            for (int j = i; j < c - 1; j++) {
                arr[j] = arr[j + 1];
            }
            c--;
            i--;
            // не увеличиваем i, чтобы проверить новый элемент на месте i
        }
    }

    // 4
    int index = -1; // индекс первого чётного
    for (int i = 0; i < c; i++) {
        if (arr[i] % 2 == 0) {
            index = i;
            if (index != -1) {
                if (index == 0) {
                    cout << "Первый чётный эл. на 1й позиции." << endl;
                }
                else {
                    for (int j = c; j > index + 1; j--) {
                        arr[j] = arr[j - 1];
                    }
                    arr[index + 1] = arr[index - 1] + 2;
                    c++;
                }
            }
            break;
        }
    }

    // 5
    for (int i = 0; i < c; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}