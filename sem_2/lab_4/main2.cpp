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

    // 3 – Удаление нулей
    for (int i = 0; i < c; i++) {  
        if (arr[i] == 0) {
            for (int j = i; j < c - 1; j++) {
                arr[j] = arr[j + 1];
            }
            c--;      // уменьшаем размер
            i--;      // возвращаем индекс, чтобы проверить элемент, который пришёл на место удалённого
        } 
    }

    cout << "После удаления нулей:" << endl;
    for (int i = 0; i < c; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 4 – Вставка после первого чётного
    for (int i = 1; i < c; i++) {  // начинаем с 1, чтобы был предыдущий элемент
        if (arr[i] % 2 == 0) {
            int new_val = arr[i-1] + 2;   // значение для вставки
            
            // сдвигаем элементы правее i вправо на 1
            for (int j = c; j > i + 1; j--) {
                arr[j] = arr[j-1];
            }
            
            arr[i+1] = new_val;   // вставляем
            c++;                   // увеличиваем размер
            break;                  // вставили только после первого чётного
        }
    }

    cout << "Конечный результат:" << endl;
    for (int i = 0; i < c; i++) {
        cout << arr[i] << " "; 
    }
    cout << endl;
    
    return 0;
}
