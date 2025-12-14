# Proyecto: FileSystem con Árboles Generales

**Materia:** Estructura de Datos

**Integrantes:**
- Juan Pablo Flores Soto
- Carlos Daniel Delgado Villareal

## Descripción
Simulador de consola de comandos (Linux/CMD) implementado en C++ utilizando árboles generales.

## Comandos soportados (Avance Día 1-3)
- `mkdir <nombre>`: Crea una carpeta.
- `touch <nombre>`: Crea un archivo.
- `ls`: Muestra el contenido del directorio actual.
- `cd <nombre>`: Navega entre carpetas.
- `rm <nombre>`: Elimina la carpeta o archivo
- `mv <origen> <destino>`: Mueve un archivo o carpeta a otra ubicacion

## Comandos de Persistencia (Dia 4)
- `save`: Guarda todo el estado actual del sistema de archivos en el disco duro.
  - Utiliza formato **JSON** (`sistema.json`) para mantener la estructura de datos.
  - Permite cerrar el programa sin perder los datos creados.

- `load`: Carga un estado previamente guardado desde `sistema.json`.
  - Restaura el arbol de directorios exactamente como estaba la ultima vez.
  - **Nota:** Al usar este comando, se borra cualquier cambio no guardado en la sesión actual para reemplazarlo con la versión del archivo.

### Búsqueda Inteligente (Día 5-6)

- `search <prefijo>`: Busca y lista todos los archivos o carpetas que comiencen con las letras indicadas.
  - **Estructura de Datos:** Implementado mediante un **Trie (Árbol de Prefijos)**. Esto permite encontrar coincidencias de manera inmediata sin tener que recorrer todo el arbol de carpetas una por una.
  - **Autocompletado:** Funciona como un motor de sugerencias; si escribes `search m`, el sistema te devolverá todo lo que empiece con "m" (ej: `musica`, `memes`, `main.cpp`).

### Gestión de Archivos y Robustez (Día 7)

- **Papelera de Reciclaje (`.papelera`):**
  - Se implementó un sistema de "borrado seguro". El comando `rm` ahora mueve los archivos a una carpeta oculta llamada `.papelera` en lugar de eliminarlos permanentemente.
  - **Nota importante:** Si se ejecuta `rm` sobre un archivo que *ya está* dentro de la papelera, entonces sí se elimina de la memoria definitivamente.

- **Acceso a la Papelera:**
  - La carpeta `.papelera` se encuentra ubicada en la **raíz (`/`)** del sistema.
  - Para ver los archivos borrados, el usuario debe navegar manualmente:
    1. Ir a la raíz: `cd ..` (repetidas veces)
    2. Entrar a la carpeta: `cd .papelera`
    3. Listar archivos: `ls`

- **Validaciones de Seguridad (Manejo de Errores):**
  - Se blindó el comando `mv` para evitar paradojas lógicas:
    - No se puede mover una carpeta dentro de si misma.
    - No se puede mover una carpeta a una de sus subcarpetas (evita bucles infinitos en el arbol).

