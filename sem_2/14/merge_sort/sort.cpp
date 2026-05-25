#include <iostream>
#include <ctime>
#include <random>

using namespace std;

void merge(int * arr, int left, int mid, int right) {
    int left_r = mid - left + 1;
    int right_r = right - mid;

    int * left_arr = new int[left_r];
    int * right_arr = new int[right_r];

    for (int i = 0; i < left_r; i++) {
        left_arr[i] = arr[left + i];
    }
    for (int i = 0; i < right_r; i++) {
        right_arr[i] = arr[mid + i + 1];
    }

    int left_idx = 0;
    int right_idx = 0;
    int merge_idx = left;

    while (left_idx < left_r && right_idx < right_r) {
        if (left_arr[left_idx] <= right_arr[right_idx]) {
            arr[merge_idx] = left_arr[left_idx];
            left_idx++;
        }
        else {
            arr[merge_idx] = right_arr[right_idx];
            right_idx++;
        }
        merge_idx++;
    }

    while(left_idx < left_r) {
        arr[merge_idx] = left_arr[left_idx];
        left_idx++;
        merge_idx++;
    }

    while(right_idx < right_r) {
        arr[merge_idx] = right_arr[right_idx];
        right_idx++;
        merge_idx++;
    }

    delete[] left_arr;
    delete[] right_arr;
}

void merge_sort(int * arr, int start, int end) {
    if (start >= end) return;

    int mid = (start + end) / 2;

    merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);
    merge(arr, start, mid, end);
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

    merge_sort(arr, 0, 9);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    return 0;
}