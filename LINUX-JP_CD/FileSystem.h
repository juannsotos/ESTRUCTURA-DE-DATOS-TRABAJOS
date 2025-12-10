#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Para buscar en vectores

using namespace std;

//  ---- ESTRUCTURA DEL NODO DIA 1 ----
struct Nodo {
    string nombre;
    bool esCarpeta; // true = carpeta, false = archivo
    string contenido; // Solo si es archivo
    Nodo* padre;      // Puntero hacia atras (para poder hacer "cd ..")
    vector<Nodo*> hijos; // LISTA de hijos (pueden ser infinitos)

    // Constructor
    Nodo(string n, bool carpeta, Nodo* p = nullptr) {
        nombre = n;
        esCarpeta = carpeta;
        padre = p;
        contenido = "";
    }
};

//   ---- CLASE DEL SISTEMA DE ARCHIVOS DIAS 2-3 ---
class FileSystem {
private:
    Nodo* raiz;
    Nodo* actual; // Puntero que dice "en que carpeta estoy parado"

public:
    FileSystem() {
        raiz = new Nodo("/", true); // La carpeta raíz
        actual = raiz; // Empezamos en la raíz
    }

    // --- COMANDO: mkdir (Crear carpeta) ---
    void mkdir(string nombre) {
        // Verificar si ya existe
        for (Nodo* hijo : actual->hijos) {
            if (hijo->nombre == nombre && hijo->esCarpeta) {
                cout << "Error: La carpeta '" << nombre << "' ya existe.\n";
                return;
            }
        }
        // Crear nueva carpeta y conectarla
        Nodo* nuevaCarpeta = new Nodo(nombre, true, actual);
        actual->hijos.push_back(nuevaCarpeta);
        cout << "Carpeta '" << nombre << "' creada.\n";
    }

    // --- COMANDO: touch (Crear archivo) ---
    void touch(string nombre) {
        for (Nodo* hijo : actual->hijos) {
            if (hijo->nombre == nombre && !hijo->esCarpeta) {
                cout << "Error: El archivo '" << nombre << "' ya existe.\n";
                return;
            }
        }
        Nodo* nuevoArchivo = new Nodo(nombre, false, actual);
        actual->hijos.push_back(nuevoArchivo);
        cout << "Archivo '" << nombre << "' creado.\n";
    }

    // --- COMANDO: ls (Listar contenido) ---
    void ls() {
        if (actual->hijos.empty()) {
            cout << "(vacio)\n";
            return;
        }
        for (Nodo* hijo : actual->hijos) {
            if (hijo->esCarpeta) cout << "[D] " << hijo->nombre << endl; // [D]irectory
            else                 cout << "[F] " << hijo->nombre << endl; // [F]ile
        }
    }

    // --- COMANDO: cd (Cambiar directorio) ---
    void cd(string nombre) {
        if (nombre == "..") {
            // Ir al padre
            if (actual->padre != nullptr) {
                actual = actual->padre;
            } else {
                cout << "Ya estas en la raiz.\n";
            }
            return;
        }

        // Buscar la carpeta hija
        for (Nodo* hijo : actual->hijos) {
            if (hijo->nombre == nombre && hijo->esCarpeta) {
                actual = hijo; // Movernos ahí
                return;
            }
        }
        cout << "Error: Directorio no encontrado.\n";
    }

    // --- COMANDO: pwd (Mostrar ruta actual) ---
    void pwd() {
        string ruta = "";
        Nodo* temp = actual;
        while (temp != nullptr) {
            if (temp->nombre == "/") ruta = "/" + ruta;
            else ruta = temp->nombre + "/" + ruta;
            temp = temp->padre;
        }
        if (ruta.length() > 1) ruta.pop_back(); // Quitar ultima barra
        cout << ruta << endl;
    }
};

#endif
