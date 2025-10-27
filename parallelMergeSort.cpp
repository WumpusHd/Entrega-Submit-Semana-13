#include <iostream>
#include <vector>
#include <thread>

using namespace std;

vector<int> merge(vector<int>& left, vector<int>& right);

void merge_sort(vector<int>& arr) {
    if (arr.size() > 1) {
        int mid = arr.size() / 2;

        vector<int> left(arr.begin(), arr.begin() + mid);
        vector<int> right(arr.begin() + mid, arr.end());

        // Si el arreglo es grande, paralelizamos
        if (arr.size() >= 1000) {
            thread t1(merge_sort, ref(left));
            thread t2(merge_sort, ref(right));

            // Esperamos a que terminen ambos hilos
            t1.join();
            t2.join();
        } else {
            // Si es pequeño, lo hacemos normal
            merge_sort(left);
            merge_sort(right);
        }

        arr = merge(left, right);
    }
}

vector<int> merge(vector<int>& left, vector<int>& right) {
    vector<int> result;
    int i = 0, j = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            result.push_back(left[i]);
            i++;
        } else {
            result.push_back(right[j]);
            j++;
        }
    }

    while (i < left.size()) {
        result.push_back(left[i]);
        i++;
    }

    while (j < right.size()) {
        result.push_back(right[j]);
        j++;
    }

    return result;
}

int main() {

    int N;
    cout << "Ingrese un número N: ";
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 100;
    }

    cout << "Unsorted array:\n";
    for(int n : arr) cout << n << " ";
    cout << endl;

    merge_sort(arr);

    cout << "Sorted array:\n";
    for (int n : arr) cout << n << " ";
    cout << endl;

    return 0;
}
