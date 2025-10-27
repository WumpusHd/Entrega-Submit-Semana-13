#include <iostream>
#include <thread>
#include <cstdlib>
using namespace std;

const int limiteHilos = 1000;

int partition(int* arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        int leftSize = pi - low;
        int rightSize = high - pi;

        if (leftSize > limiteHilos && rightSize > limiteHilos) {
            thread t1(quickSort, arr, low, pi - 1);
            thread t2(quickSort, arr, pi + 1, high);
            t1.join();
            t2.join();
        } 
        else if (leftSize > limiteHilos) {
            thread t1(quickSort, arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
            t1.join();
        } 
        else if (rightSize > limiteHilos) {
            quickSort(arr, low, pi - 1);
            thread t2(quickSort, arr, pi + 1, high);
            t2.join();
        } 
        else {
            // Si las particiones son pequeñas, hacerlo normal
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
}

int main() {
    int N;
    cout << "Ingrese un número N: ";
    cin >> N;

    int* arr = new int[N];
    for (int i = 0; i < N; i++)
        arr[i] = rand() % 100;

    cout << "Unsorted array:\n";
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
    cout << endl;

    quickSort(arr, 0, N - 1);

    cout << "Sorted array:\n";
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
    cout << endl;

    delete[] arr;
    return 0;
}
