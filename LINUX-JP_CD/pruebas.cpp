#include <iostream>
#include "FileSystem.h" // Incluye tu código principal

using namespace std;

int main() {
    cout << "==========================================" << endl;
    cout << "   PRUEBAS UNITARIAS (VERIFICACION)      " << endl;
    cout << "==========================================" << endl;

    // 1. Instanciar el sistema
    FileSystem fs;

    // -------------------------------------------------
    // PRUEBA 1: Crear Directorios
    // -------------------------------------------------
    cout << "\n[PRUEBA 1] Intento de crear carpeta 'carpeta_prueba'..." << endl;
    fs.mkdir("carpeta_prueba");
    cout << ">> Resultado esperado: Mensaje de 'Carpeta creada'." << endl;

    // -------------------------------------------------
    // PRUEBA 2: Crear Archivos
    // -------------------------------------------------
    cout << "\n[PRUEBA 2] Intento de crear archivo 'archivo_test.txt'..." << endl;
    fs.touch("archivo_test.txt");
    cout << ">> Resultado esperado: Mensaje de 'Archivo creado'." << endl;

    // -------------------------------------------------
    // PRUEBA 3: Búsqueda (Trie)
    // -------------------------------------------------
    cout << "\n[PRUEBA 3] Buscando prefijo 'archi'..." << endl;
    fs.search("archi");
    cout << ">> Resultado esperado: Debe listar 'archivo_test.txt'." << endl;

    // -------------------------------------------------
    // PRUEBA 4: Validación de Duplicados
    // -------------------------------------------------
    cout << "\n[PRUEBA 4] Intentando crear duplicado de 'carpeta_prueba'..." << endl;
    fs.mkdir("carpeta_prueba");
    cout << ">> Resultado esperado: Mensaje de ERROR (Ya existe)." << endl;

    // -------------------------------------------------
    // PRUEBA 5: Borrado Seguro
    // -------------------------------------------------
    cout << "\n[PRUEBA 5] Borrando 'archivo_test.txt'..." << endl;
    fs.rm("archivo_test.txt");

    cout << "Verificando si aun aparece en busqueda:" << endl;
    fs.search("archivo_test.txt");
    cout << ">> Resultado esperado: NO debe encontrar coincidencias." << endl;

    cout << "\n==========================================" << endl;
    cout << "      FIN DE LA EJECUCION DE PRUEBAS      " << endl;
    cout << "==========================================" << endl;

    return 0;
}
