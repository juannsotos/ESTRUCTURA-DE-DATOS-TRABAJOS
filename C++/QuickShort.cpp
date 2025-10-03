#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <array>
using namespace std;

int particion(vector<int>&arreglo,int inicio,int finall){
    int pivote = arreglo[finall];
    int i = inicio - 1;

    for (int j = inicio; j < finall; j++){
        if (arreglo[j] <= pivote){
            i++;
            swap(arreglo[i],arreglo[j]);

        }
    }
    swap(arreglo[i+1],arreglo[finall]);
    return i + 1;
}


void quickshort(vector<int>&arreglo,int inicio,int finall){
    if (inicio < finall){
        int pivote = particion(arreglo,inicio,finall);
        quickshort(arreglo,inicio,pivote-1);
        quickshort(arreglo,pivote+1,finall);

    }
}

void ImprimirArreglo(vector<int>&arreglo){
    for (int i = 0; i < arreglo.size(); i++){
        cout << arreglo[i] << " ";
    }
    cout << endl;

}

int main(){
    vector<int> arreglo(10); // Con ambas formas de definirlo funciona
    //array<int, 10> arreglo;
    srand(time(NULL));
    int num = rand();
    // limiteInferior = 1
    // LimiteSuperior = 100  // Esta cosa genera numeros randoms dentro del arreglo, lo uso para no batallar en llenarlo
    for (int i = 0; i < 10; i++){
        int num = 1 + rand() % (100 - 1 + 1);
        arreglo[i] = num;
    }

    cout << "El arreglo desordenado es: ";
    ImprimirArreglo(arreglo);
    quickshort(arreglo,0,arreglo.size()-1);
    cout << "El arreglo ordenado es: ";
    ImprimirArreglo(arreglo);


    return 0;

}
