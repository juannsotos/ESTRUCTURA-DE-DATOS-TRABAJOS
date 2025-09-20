#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>

using namespace std;


int main(){

    array<int, 10> arreglo;
    srand(time(NULL));

    for (int i = 0; i < 10; i++){
        int num = 1 + rand() % (100 - 1 + 1);
        arreglo[i] = num;
    }

    cout << "El arreglo desordenado es: ";
    cout << "[ ";
    for (int x : arreglo){
        cout << x << " ";
    }
    cout << "]";
    cout << endl;


    for (int i = 0; i < arreglo.size(); i ++){
        int actual = arreglo[i];
        int j = i - 1;

        while (j >= 0 && arreglo[j] > actual){
            arreglo[j + 1] = arreglo[j];
            j = j -1;
        }
        arreglo[j+1] = actual;

    }

    cout << "El arreglo ordenado es: [";
    for (int x : arreglo){
        cout << x << " ";
    }
    cout << " ]";
    return 0;
}
