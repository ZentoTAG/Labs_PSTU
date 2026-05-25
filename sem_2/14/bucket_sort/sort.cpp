#include <iostream>
#include <ctime>
#include <random>

using namespace std;

void bucket_sort(int * arr, int size) {
    if (size <= 1) return;

    const int BUCKET_NUM = 10;
    const int BUCKET_SIZE = 100;
    int buckets[BUCKET_NUM][BUCKET_SIZE];
    int bucket_sizes[BUCKET_NUM] = {0};

    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    for (int i = 0; i < size; i++) {
        int bucket_idx = (BUCKET_NUM * arr[i]) / (max + 1);
        
        if (bucket_sizes[bucket_idx] < BUCKET_NUM) {
            buckets[bucket_idx][bucket_sizes[bucket_idx]] = arr[i];
            bucket_sizes[bucket_idx]++;
        }
    }

    for (int i = 0; i < BUCKET_NUM; i++) {
        for (int j = 1; j < bucket_sizes[i]; j++) {
            int tmp = buckets[i][j];
            int k = j - 1;

            while(k >= 0 && buckets[i][k] > tmp) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = tmp;
        }
    }

    int idx = 0;
    for (int i = 0; i < BUCKET_NUM; i++) {
        for (int j = 0; j < bucket_sizes[i]; j++) {
            arr[idx++] = buckets[i][j];
        }
    }
}

int main() {
    srand(time(0));
    int size = 10;
    int * arr = new int[size];

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 101;
        cout << arr[i] << " ";
    }
    cout << endl;

    bucket_sort(arr, 10);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    return 0;
}