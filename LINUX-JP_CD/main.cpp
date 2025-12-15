#include <iostream>
#include <string>
#include <sstream> // Necesario para partir el texto (parsing)
#include "FileSystem.h"

using namespace std;

// Función para limpiar pantalla (detecta si es Windows o Linux)
void limpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}


// Función para quitar espacios extra y detectar cadenas vacías
string trim(string str) {
    size_t first = str.find_first_not_of(' ');
    // Si no encuentra ninguna letra (o sea, son puros espacios), devuelve vacío
    if (string::npos == first) return "";

    // Si sí hay letras, quita los espacios del final también
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

int main() {
    FileSystem fs;
    string lineaEntrada;


    limpiarPantalla();
    cout << "Escribe 'help' para ver los comandos.\n\n";

    while (true) {
        // --- 1. PROMPT DINÁMICO ---
        // Muestra: usuario@consola:/ruta/actual $
        cout << "\033[1;32musuario@consola\033[0m:\033[1;34m" << fs.obtenerRutaActual() << "\033[0m $ ";

        // --- 2. LEER LÍNEA COMPLETA (con espacios) ---
        if (!getline(cin, lineaEntrada)) break; // Si falla la entrada, salir
        if (lineaEntrada.empty()) continue;     // Si dio Enter vacio, repetir

        // --- 3. PARSEO (Separar comando de argumentos) ---
        stringstream ss(lineaEntrada);
        string comando;
        string restoDeLinea; // Para argumentos con espacios (ej: "tarea de mate")
        string arg1, arg2;   // Para comandos que requieren 2 argumentos (mv)

        ss >> comando; // Extrae la primera palabra (el comando)

        // --- 4. BLOQUE DE COMANDOS ---

        if (comando == "exit") {
            break;
        }
        else if (comando == "cls" || comando == "clear") {
            limpiarPantalla();
        }
        else if (comando == "help") {
            cout << "\n--- Comandos Disponibles ---\n";
            cout << "  mkdir <nombre>   : Crear carpeta (admite espacios)\n";
            cout << "  touch <nombre>   : Crear archivo\n";
            cout << "  ls               : Listar contenido\n";
            cout << "  cd <nombre/..>   : Cambiar directorio\n";
            cout << "  pwd              : Ver ruta actual\n";
            cout << "  rm <nombre>      : Enviar a papelera\n";
            cout << "  mv <org> <dest>  : Mover (SIN espacios en nombres)\n";
            cout << "  search <txt>     : Buscar por prefijo\n";
            cout << "  save / load      : Guardar o Cargar sistema\n";
            cout << "  cls              : Limpiar pantalla\n";
            cout << "  exit             : Salir\n\n";
        }
        // Comandos que aceptan espacios en el nombre
        else if (comando == "mkdir" || comando == "touch" || comando == "cd" || comando == "rm" || comando == "search") {
            getline(ss, restoDeLinea); // Lee todo lo que sobra de la línea
            restoDeLinea = trim(restoDeLinea); // Quita el espacio inicial

            if (restoDeLinea.empty()) {
                cout << "Error: Faltan argumentos para '" << comando << "'.\n";
            } else {
                if (comando == "mkdir") fs.mkdir(restoDeLinea);
                else if (comando == "touch") fs.touch(restoDeLinea);
                else if (comando == "cd")    fs.cd(restoDeLinea);
                else if (comando == "rm")    fs.rm(restoDeLinea);
                else if (comando == "search") fs.search(restoDeLinea);
            }
        }
        // Comandos simples sin argumentos
        else if (comando == "ls") {
            fs.ls();
        }
        else if (comando == "pwd") {
            fs.pwd();
        }
        else if (comando == "save") {
            fs.save();
        }
        // Solo para probar performance
        else if (comando == "test_boom") {
            for(int i = 0; i < 1000; i++) {
                fs.mkdir("carpeta_relleno_" + to_string(i));
            }
            cout << "Se crearon 1000 carpetas. Prueba hacer 'ls' o 'save' ahora.\n";
        }
        else if (comando == "load") {
            fs.load();
        }
        // Comando especial mv (requiere 2 argumentos distintos)
        else if (comando == "mv") {
            ss >> arg1 >> arg2; // mv no soporta espacios facilmente en esta version
            if (arg1.empty() || arg2.empty()) {
                cout << "Uso: mv <origen> <destino> (Nota: No usar espacios para mv)\n";
            } else {
                fs.mv(arg1, arg2);
            }
        }

        else {
            cout << "Comando '" << comando << "' no reconocido. Escribe 'help'.\n";
        }
    }

    return 0;
}
