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

    // --- NUEVO: Destructor para borrar en cadena ---
    ~Nodo() {
        for (Nodo* hijo : hijos) {
            delete hijo; // Borra a los hijos recursivamente
        }
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

    // --- NUEVO: COMANDO rm (Eliminar) ---
    void rm(string nombre) {
        for (auto it = actual->hijos.begin(); it != actual->hijos.end(); ++it) {
            if ((*it)->nombre == nombre) {
                // ¿Es carpeta y no está vacía? (Opcional: Advertencia)
                // Por ahora lo borramos directo
                delete *it; // Llama al destructor del Nodo
                actual->hijos.erase(it); // Lo quita de la lista del padre
                cout << "Elemento '" << nombre << "' eliminado.\n";
                return;
            }
        }
        cout << "Error: No se encontro '" << nombre << "'.\n";
    }

    // --- NUEVO: COMANDO mv (Mover) ---
    // Mueve un archivo/carpeta a otro destino (puede ser ".." o una carpeta hija)
    void mv(string nombreOrigen, string nombreDestino) {
        Nodo* nodoMover = nullptr;
        int indexMover = -1;

        // 1. Buscar lo que queremos mover
        for (int i = 0; i < actual->hijos.size(); i++) {
            if (actual->hijos[i]->nombre == nombreOrigen) {
                nodoMover = actual->hijos[i];
                indexMover = i;
                break;
            }
        }

        if (!nodoMover) {
            cout << "Error: No existe '" << nombreOrigen << "'.\n";
            return;
        }

        // 2. Buscar el destino
        Nodo* nodoDestino = nullptr;

        if (nombreDestino == "..") {
            if (actual->padre != nullptr) nodoDestino = actual->padre;
            else { cout << "Error: La raiz no tiene padre.\n"; return; }
        } else {
            // Buscar en hijos (mover a una subcarpeta)
            for (Nodo* hijo : actual->hijos) {
                if (hijo->nombre == nombreDestino && hijo->esCarpeta) {
                    nodoDestino = hijo;
                    break;
                }
            }
        }

        if (!nodoDestino) {
            cout << "Error: Destino '" << nombreDestino << "' no valido.\n";
            return;
        }

        // 3. Mover (Desconectar de aquí y conectar allá)
        // Borrar del vector actual (pero NO delete memoria, porque queremos conservarlo)
        actual->hijos.erase(actual->hijos.begin() + indexMover);

        // Agregarlo al destino
        nodoDestino->hijos.push_back(nodoMover);
        nodoMover->padre = nodoDestino; // Actualizar su nuevo padre

        cout << "Se movio '" << nombreOrigen << "' a '" << nombreDestino << "'.\n";
    }
};

#endif
