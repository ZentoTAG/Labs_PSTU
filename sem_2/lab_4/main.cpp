#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    const int n = 100;
    int arr[n];
    int c;
    cout << "c: ";
    cin >> c;
    
    cout << "Исходный массив:" << endl;
    for (int i = 0; i < c; i++) {
        arr[i] = rand() % 200 - 100;
        cout << arr[i] << " "; 
    }
    cout << endl;

	//3
    for (int i = 0; i < c; i++) {  
        if (arr[i] == 0) {
            for (int j = i; j < c - 1; j++) {
                arr[j] = arr[j + 1];
                
            }
            c--;
        } 
    }

    cout << endl;


	// 4
	for (int i = 0; i < c - 1; i++) {
		int tmp = 0;
		if (arr[i] % 2 == 0) {
			for (int j=i+1; j < c; j++) {
				tmp = arr[j+1];
				arr[j+1] = arr[j];
			}
			arr[i] = arr[i-1] + 2;
			break;
		}
	}


    for (int i = 0; i < c; i++) {
        cout << arr[i] << " "; 
    }
    cout << endl;
    
    return 0;
}
