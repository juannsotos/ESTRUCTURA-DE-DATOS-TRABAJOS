#include <iostream>
#include <string>
#include "FileSystem.h"

using namespace std;

int main() {
    FileSystem fs;
    string comando, argumento;

    cout << "=== MINI TERMINAL (Simulador de Arboles) ===\n";
    cout << "Comandos: mkdir <nombre>, touch <nombre>, ls, cd <nombre>, pwd, exit\n";

    while (true) {
        cout << "\nuser@console: ";
        fs.pwd(); // Muestra la ruta actual, ej: user@console: /home/docs/ >
        cout << "> ";

        cin >> comando;

        if (comando == "exit") break;

        else if (comando == "ls") {
            fs.ls();
        }
        else if (comando == "pwd") {
            fs.pwd(); // Ya se muestra en el prompt, pero por si acaso
        }
        else if (comando == "mkdir") {
            cin >> argumento;
            fs.mkdir(argumento);
        }
        else if (comando == "touch") {
            cin >> argumento;
            fs.touch(argumento);
        }
        else if (comando == "cd") {
            cin >> argumento;
            fs.cd(argumento);
        }
        else if (comando == "rm") {
            cin >> argumento;
            fs.rm(argumento);
        }
        else if (comando == "mv") {
            string destino;
            cin >> argumento >> destino; // mv necesita dos argumentos
            fs.mv(argumento, destino);
        }
        else {
            cout << "Comando desconocido.\n";
            // Limpiar buffer por si metieron espacios
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

    return 0;
}
