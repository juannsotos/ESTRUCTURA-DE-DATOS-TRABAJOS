#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <array>
using namespace std;

int main(){

     array<int, 10> arreglo;
    srand(time(NULL));
    int num = rand();
    // limiteInferior = 1
    // LimiteSuperior = 100
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

    for (int i = 0; i < arreglo.size(); i++){
            int minimo = i;
        for(int j = i+1; j < arreglo.size(); j++){
            if  (arreglo[minimo] > arreglo[j]){
                minimo = j;
            }
        }
        int temp = arreglo[i];
        arreglo[i] = arreglo[minimo];
        arreglo[minimo] = temp;
    }

      cout << "El arreglo desordenado es: ";
    cout << "[ ";
    for (int x : arreglo){
        cout << x << " ";
    }
    cout << "]";
    cout << endl;






    return 0;
}
