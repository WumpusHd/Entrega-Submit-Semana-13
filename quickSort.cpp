#include <iostream>
#include <vector>
using namespace std;


void quickSort(int* arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int pi = i + 1;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main() {
    
    int N;
    cout << "Ingrese un número N: ";
    cin >> N;

    int size = N;
    int* arr = new int[size];

    for (int i = 0; i < size; i++)
        arr[i] = rand() % 100;
    cout << "Unsorted array: \n";

    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    quickSort(arr, 0, size - 1);

    cout << "Sorted array: \n";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    delete[] arr;
    return 0;
}