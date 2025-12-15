### 1. INICIO Y ESTÉTICA (UX)
**Objetivo:** Mostrar la interfaz, colores y comando de ayuda.

* **Comando:** `help`
  * **Explicación:** Muestra la lista de comandos disponibles y sintaxis.

* **Comando:** `mkdir semestre_1`
* **Comando:** `cd semestre_1`
* **Comando:** `mkdir "progra estructurada"`
  * **Explicación:** Demostración de soporte para nombres con espacios.

* **Comando:** `cd "progra estructurada"`
* **Comando:** `pwd`
  * **Explicación:** Muestra la ruta absoluta dinámica.

---

### 2. BÚSQUEDA INTELIGENTE (TRIE)
**Objetivo:** Demostrar inserción en tiempo real y autocompletado.

* **Comando:** `touch main.cpp`
* **Comando:** `touch matriz.cpp`
* **Comando:** `touch manual.txt`
* **Comando:** `ls`
  * **Explicación:** Se listan los archivos creados.

* **Comando:** `search ma`
  * **Explicación:** El Trie devuelve instantáneamente: `main.cpp`, `matriz.cpp`, `manual.txt`.

* **Comando:** `search manu`
  * **Explicación:** Autocompletado específico para 'manual.txt'.

---

### 3. SISTEMA DE PAPELERA Y BORRADO SEGURO
**Objetivo:** Mostrar que rm no elimina permanentemente, sino que mueve.

* **Comando:** `rm main.cpp`
* **Comando:** `ls`
  * **Explicación:** El archivo ya no está en la carpeta actual.

* **Comando:** `search main`
  * **Explicación:** Validación: El archivo también desapareció del buscador.

* **Comando:** `cd ..`
* **Comando:** `cd ..`
* **Comando:** `cd .papelera`
* **Comando:** `ls`
  * **Explicación:** El archivo main.cpp se encuentra resguardado aquí.

---

### 4. ROBUSTEZ Y VALIDACIONES (MANEJO DE ERRORES)
**Objetivo:** Demostrar que el sistema no permite operaciones ilegales.

* **Comando:** `rm .papelera`
  * **Resultado:** "Error: No puedes borrar la papelera del sistema."

* **Comando:** `cd ..`
* **Comando:** `touch duplicado.txt`
* **Comando:** `mkdir duplicado.txt`
  * **Resultado:** "Error: Ya existe un elemento llamado 'duplicado.txt'..."
  * **Explicación:** El sistema evita colisiones de nombres (Archivos vs Carpetas).

---

### 5. PERSISTENCIA DE DATOS (JSON)
**Objetivo:** Guardar el árbol completo y restaurarlo tras reiniciar.

* **Comando:** `save`
* **Comando:** `exit`

> *(Acción: Cerrar consola y volver a abrir el programa)*

#### --- NUEVA SESIÓN ---

* **Comando:** `ls`
  * **Resultado:** (Vacío)

* **Comando:** `load`
  * **Resultado:** "Sistema cargado exitosamente."

* **Comando:** `ls`
  * **Resultado:** Aparece la carpeta 'semestre_1'.

* **Comando:** `search ma`
  * **Resultado:** El Trie se reconstruyó correctamente y encuentra los archivos.