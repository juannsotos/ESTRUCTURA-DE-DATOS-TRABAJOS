#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<double>& bukt) {
    for (size_t j = 1; j < bukt.size(); j++) {
        double val = bukt[j];
        int k = j - 1;
        while (k >= 0 && bukt[k] > val) {
            bukt[k + 1] = bukt[k];
            k--;
        }
        bukt[k + 1] = val;
    }
}

void bucketSort(vector<double>& inputArr) {
    int s = inputArr.size();
    vector<vector<double>> bucketArr(s);

    for (double j : inputArr) {
        int bi = s * j;
        if (bi != s)
            bucketArr[bi].push_back(j);
        else
            bucketArr[s - 1].push_back(j);
    }

    for (auto& bukt : bucketArr)
        insertionSort(bukt);

    int idx = 0;
    for (auto& bukt : bucketArr)
        for (double j : bukt)
            inputArr[idx++] = j;
}

int main() {
    vector<double> inputArr = {0.77, 0.16, 0.38, 0.25, 0.71, 0.93, 0.22, 0.11, 0.24, 0.67};

    cout << "Arreglo antes de ordenar:\n";
    for (double v : inputArr) cout << v << " ";

    bucketSort(inputArr);

    cout << "\nArreglo después de ordenar:\n";
    for (double v : inputArr) cout << v << " ";
    return 0;
}