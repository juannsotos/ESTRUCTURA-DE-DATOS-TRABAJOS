#include <iostream>
using namespace std;

//Declarar un TDA
typedef struct Circulo {
    float radio;
};

//Definir la interfaz
void CalcularArea(Circulo&);

int main(){

Circulo c;
CalcularArea(c);

return 0;
}

void CalcularArea(Circulo&){
    Circulo circulo;
    cout << "Radio: "; cin >> circulo.radio;
    cout << "Area :" << 2 * 3.1416 * circulo.radio;
}




