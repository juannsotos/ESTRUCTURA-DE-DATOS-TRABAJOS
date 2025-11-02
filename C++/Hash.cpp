#include <iostream>
using namespace std;

class ShellSort {
public:
    void displayArr(int arr[], int n) {
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    void sort(int arr[], int n) {
        for (int gap = n / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < n; i++) {
                int temp = arr[i];
                int j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                    arr[j] = arr[j - gap];
                arr[j] = temp;
            }
        }
    }
};

int main() {
    int arr[] = {36, 34, 43, 11, 15, 20, 28, 45};
    int n = sizeof(arr) / sizeof(arr[0]);

    ShellSort sorter;
    cout << "Arreglo antes de ser ordenado: ";
    sorter.displayArr(arr, n);

    sorter.sort(arr, n);

    cout << "Arreglo después de ser ordenado: ";
    sorter.displayArr(arr, n);
    return 0;
}