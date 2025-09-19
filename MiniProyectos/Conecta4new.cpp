#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

const int filas = 6;
const int columnas = 7;
int NumColumna;
char valor,ganador;
char tablero[filas][columnas];
int x,y;


void MostrarTablero(char tablero[][columnas]){
    cout << endl;
    for (int i = 0; i < filas; i++){
        cout << "|";
        for (int j = 0; j < columnas; j++){
            cout << tablero[i][j] << " ";
        }
        cout << "|" << endl;
    }
    cout << " ";
    for (int j = 0; j < columnas; j++){
        cout << j+1 << " ";
    }
    cout << endl;
}

void Jugada(char valor){

    bool anoto = false;

    while (anoto == false) {
        cout << endl;
        cout << "Ingresa una columna (1 - 7): ";
        cin >> NumColumna;

        while ((NumColumna < 1) || (NumColumna > 7)){
            cout << " !! Ingrese una columna existente !! > ";
            cin >> NumColumna;
        }
        NumColumna = NumColumna -1;

        for (int i = 5; i >= 0; i--){
            if ((tablero[i][NumColumna]) == '.'){
                tablero[i][NumColumna] = valor;
                x = i;
                y = NumColumna;
                anoto = true;
                break;
            }
        }
        if (!anoto){
            cout << " !! Esa columna ya esta llena !! ";
        }
    }
    MostrarTablero(tablero);



}

bool Horizontal(){
    int contador = 1;

    for (int j = y +1; j < columnas && j <= y+3; j++){
        if (tablero[x][j] == tablero[x][y]){
            contador++;
        }else{
            break;
        }
    }

    for (int j = y -1; j >= 0 && j >= y-3; j--){
        if (tablero[x][j] == tablero[x][y]){
            contador++;
        }else{
            break;
        }
    }

    return contador >=4;

}

bool Vertical(){
    int contador = 1;

    for (int i = x +1; i < filas && i <= x+3; i++){
        if (tablero[i][y] == tablero[x][y]){
            contador++;
        }else{
            break;
        }
    }

    return contador >=4;
}

bool DiagonalesDerecha(){
    int contador = 1;

    for (int i = x -1, j = y +1; i >= 0 && j < columnas && contador < 4; i--,j++){
        if (tablero[i][j] == tablero[x][y]){
            contador++;
        }else{
            break;
        }

    }

    for (int i = x +1, j = y -1; j >= 0 && i < filas && contador < 4; i++,j--){
        if (tablero[i][j] == tablero[x][y]){
            contador++;
        }else{
            break;
        }

    }

    return contador >= 4;

}

bool DiagonalesIzquierda(){
    int contador = 1;

    for (int i = x +1, j = y + 1; j < columnas && i < filas && contador < 4; i++,j++){
        if (tablero[i][j] == tablero[x][y]){
            contador++;
        }else{
            break;
        }
    }

    for (int i = x -1, j = y -1; j >= 0 && i >= 0 && contador < 4; i--,j--){
        if (tablero[i][j] == tablero[x][y]){
            contador++;
        }else{
            break;
        }
    }


    return contador >= 4;

}

bool Empate(){

    for (int j = 0; j < columnas; j++){

        if (tablero[0][j] == '.'){
            return false;
        }
    }
    return true;

}

bool VerificarGanador(){

    return Horizontal() || Vertical() || DiagonalesDerecha() || DiagonalesIzquierda();

}


int main () {

    for (int i = 0; i < filas; i++){
        for (int j =0; j < columnas; j++){
            tablero[i][j] = '.';
        }
    }


    MostrarTablero(tablero);

    for (int turno = 0; turno < 21; turno++){
        cout << endl;
        cout << "Turno Del Jugador 1 - X" << endl;
        valor = 'X';
        Jugada(valor);


        if (VerificarGanador()){
            cout << "ganaron las X pa algo bien" << endl;
            return 0;
        }

        if (Empate()){
            cout << "Empataron pai" << endl;
            return 0;
        }

        cout << endl;
        cout << "Turno del Jugador 2 - 0" <<endl;
        valor = 'O';
        Jugada(valor);

         if (VerificarGanador()){
            cout << "ganaron las O pa algo bien" << endl;
            return 0;
        }

         if (Empate()){
            cout << "Empataron pai" << endl;
            return 0;
        }


        system("cls");
        MostrarTablero(tablero);




    }










return 0;
}
