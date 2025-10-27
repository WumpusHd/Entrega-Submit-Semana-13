#include <iostream>
#include <cstdlib>
#include <thread>
#include <vector>

using namespace std;

void oddEvenSort(int* arr, int N) {
    bool isSorted = false;

    while (!isSorted) {
        isSorted = true; // asumimos que ya está ordenado

        // ----- Fase impar -----
        vector<thread> threads_odd;
        for (int i = 1; i < N - 1; i += 2) {
            threads_odd.emplace_back([&, i]() {
                if (arr[i] > arr[i + 1]) {
                    swap(arr[i], arr[i + 1]);
                    isSorted = false; // hubo un intercambio
                }
            });
        }
        for (auto& t : threads_odd) t.join();

        // ----- Fase par -----
        vector<thread> threads_even;
        for (int i = 0; i < N - 1; i += 2) {
            threads_even.emplace_back([&, i]() {
                if (arr[i] > arr[i + 1]) {
                    swap(arr[i], arr[i + 1]);
                    isSorted = false; // hubo un intercambio
                }
            });
        }
        for (auto& t : threads_even) t.join();
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

    oddEvenSort(arr, N);

    cout << "Sorted array:\n";
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
    cout << endl;

    delete[] arr;
    return 0;
}
