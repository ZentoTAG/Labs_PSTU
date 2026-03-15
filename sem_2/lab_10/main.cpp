#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    
    int size;
   	int key;
    int startPos, K;
    cout << "size, startpos, K, key" << endl;;
    cin >> size;
    cin >> startPos;
    cin >> K;
    cin >> key;

    int* arr = new int[size + 1];
    
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }

    cout << endl;
    
    for (int i = startPos; i < size - K; i++) {
        arr[i] = arr[i + K];
    }
    
    size -= K;
    arr[size] = key;
    size++;
    
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    
    delete[] arr;
    return 0;
}
