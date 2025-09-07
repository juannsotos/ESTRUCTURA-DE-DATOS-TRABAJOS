#include <iostream>
using namespace std;

int main() {

int r = 3, c = 3;
int TwoArray[3][3] = {
    {1,2,3},
    {4,5,6},
    {7,8,9}

};

int arr[r * c];

for (int y = 0; y < c; y++){
     for (int x = 0; x < r; x++){
        int k = y * r + x;
        arr[k] = TwoArray[x][y];
     }
}

cout << "Los elementos del arreglo bidimensional son: " << endl;
for (int x = 0; x < r; x++){
     for (int y = 0; y < c; y++){
        cout << TwoArray[x][y] << " ";

     }
     cout << endl;
}
cout << endl;

cout << "Los elementos del arreglo unidimensional son ;" << endl;
for (int i = 0; i < r * c; i++){
    cout << arr[i] << " ";
}







return 0;
}
