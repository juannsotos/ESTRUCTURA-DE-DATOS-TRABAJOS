#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

struct TrieNodo {
    map<char, TrieNodo*> hijos;
    bool finDePalabra;

    TrieNodo() {
        finDePalabra = false;
    }
};

class Trie {
private:
    TrieNodo* raiz;

    // Función auxiliar para recolectar palabras recursivamente
    void recolectar(TrieNodo* nodo, string palabraActual, vector<string>& resultados) {
        if (nodo->finDePalabra) {
            resultados.push_back(palabraActual);
        }

        // Recorrer todos los hijos (letras siguientes)
        for (auto const& [letra, hijo] : nodo->hijos) {
            recolectar(hijo, palabraActual + letra, resultados);
        }
    }

public:
    Trie() {
        raiz = new TrieNodo();
    }

    // Insertar una palabra (nombre de archivo/carpeta)
    void insertar(string palabra) {
        TrieNodo* temp = raiz;
        for (char c : palabra) {
            // Si la letra no existe, crearla
            if (temp->hijos.find(c) == temp->hijos.end()) {
                temp->hijos[c] = new TrieNodo();
            }
            temp = temp->hijos[c];
        }
        temp->finDePalabra = true;
    }

    // --- NUEVO: Función para "borrar" del índice ---
    void eliminar(string palabra) {
        TrieNodo* temp = raiz;
        for (char c : palabra) {
            // Si no encontramos el camino, la palabra no existe
            if (temp->hijos.find(c) == temp->hijos.end()) {
                return;
            }
            temp = temp->hijos[c];
        }
        // Al llegar al final, simplemente decimos "ya no es fin de palabra"
        temp->finDePalabra = false;
    }

    // Autocompletar: Buscar palabras que empiecen con "prefijo"
    vector<string> buscarPorPrefijo(string prefijo) {
        vector<string> resultados;
        TrieNodo* temp = raiz;

        // 1. Navegar hasta el final del prefijo (ej: "do")
        for (char c : prefijo) {
            if (temp->hijos.find(c) == temp->hijos.end()) {
                return resultados; // No hay nada con ese prefijo
            }
            temp = temp->hijos[c];
        }

        // 2. A partir de ahí, recolectar todo lo que haya abajo
        recolectar(temp, prefijo, resultados);
        return resultados;
    }
};

#endif
