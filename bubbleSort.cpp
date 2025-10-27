#include <iostream>
#include <cstdlib>


using namespace std;

int main() {

    int N;
    cout << "Ingrese un número N: ";
    cin >> N;

    int size = N;
    int* arr = new int[size];

    for (int i = 0; i < size; i++)
        arr[i] = rand() % 100;
    cout << "Unsorted array: \n";

    
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Sorted array: \n";
    for (int i = 0; i < size; i++) 
        cout << arr[i] << " ";
    cout << endl;

    return 0;
    
}
