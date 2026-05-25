#include <iostream>
#include <ctime>
#include <random>

using namespace std;

void counting_sort(int * arr, int size) {
    if (size <= 1) {
        return;
    }

    int max = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int * cnt = new int[max + 1]{0};
    int * output = new int[size];

    for (int i = 0; i < size; i++) {
        cnt[arr[i]]++;
    }

    for (int i = 1; i <= max; i++) {
        cnt[i] += cnt[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        output[cnt[arr[i]] - 1] = arr[i];
        cnt[arr[i]]--;
    }

    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }

    delete[] cnt;
    delete[] output;
}

int main() {
    srand(time(0));
    int size = 10;
    int * arr = new int[size];

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 11;
        cout << arr[i] << " ";
    }
    cout << endl;

    counting_sort(arr, 10);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    return 0;
}