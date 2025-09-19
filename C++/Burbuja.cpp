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
    int limInf = 1;
    int limSup = 100;
    for (int i = 0; i < 10; i++){
        int num = limInf + rand() % (limSup - limInf + 1);
        arreglo[i] = num;


    }
    cout << "El arreglo desordenado es: ";
    cout << "[ ";
    for (int x : arreglo){
        cout << x << " ";
    }
    cout << "]";
    cout << endl;

    for (int i = 0; i < arreglo.size() ; i++){
         for(int j = 0; j< arreglo.size() -i-1; j++){
            if (arreglo[j] > arreglo[j+1]){
                int temp = arreglo[j];
                arreglo[j] = arreglo[j+1];
                arreglo[j+1] = temp;
            }


         }
    }
    cout << "El arreglo ordenado es: ";
    cout << "[ ";
    for (int x : arreglo){
        cout << x << " ";
    }
    cout << "]";

    return 0;

}
