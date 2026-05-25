#include <iostream>
#include <random>
#include<ctime>

using namespace std;

int lomuto_split(int * arr, int low, int high) {
    int i = low - 1;
    int pivot = arr[high];

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return (i + 1);
}

void lomuto_sort(int * arr, int low, int high) {
    if (low < high) {
        int p_idx = lomuto_split(arr, low, high);
        lomuto_sort(arr, low, p_idx - 1);
        lomuto_sort(arr, p_idx + 1, high);
    }
}

int main() {
    srand(time(0));
    int size = 10;
    int * arr = new int[size];

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }
    cout << endl;

    lomuto_sort(arr, 0, size - 1);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    return 0;
}