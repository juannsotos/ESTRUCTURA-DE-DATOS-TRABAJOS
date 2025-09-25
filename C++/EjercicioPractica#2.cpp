#include <iostream>
#include <array>
using namespace std;

int main(){

    array<int, 10> arr;
    float suma;
    int mayor,menor;
    for (int i = 0; i < 10; i++){
        cout << "Ingrese un numero entero: ";
        cin >> arr[i];
        suma = suma + arr[i];
    }
    mayor = arr[0];
    menor = arr[0];
    cout << endl;
    for(int i = 0; i < 10; i++){
       if(arr[i] > mayor){
            mayor = arr[i];
       } else if (arr[i] < menor){
            menor = arr[i];
       }
    }
    cout << "Menor: " << menor << endl;
    cout << "Mayor: " << mayor << endl;
    cout << "La suma es: " << suma << endl;
    cout << "Promedio: " << suma/arr.size();
    return 0;
}
