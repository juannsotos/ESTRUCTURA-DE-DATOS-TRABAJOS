const prompt = require('prompt-sync')();

// 2. CONFIGURACIÓN DEL JUEGO
const DIFICULTADES = {
  // Rango de números a MOSTRAR
  MF: { min: 36, max: 44, nombre: "Mega Facil" },
  F:  { min: 32, max: 35, nombre: "Facil" },
  M:  { min: 28, max: 31, nombre: "Media" },
  D:  { min: 24, max: 27, nombre: "Dificil" },
  MD: { min: 17, max: 23, nombre: "Mega Dificil" }
};
const NIVELES_POR_DIFICULTAD = 5;
const VIDAS_INICIALES = 5;
const ORDEN_DIFICULTAD = ['MF', 'F', 'M', 'D', 'MD'];

// 3. TODAS LAS FUNCIONES "HERRAMIENTA" (Las que corregimos arriba)

// --- HERRAMIENTAS DE VALIDACIÓN ---
function esValidoEnFila(tablero, num, fila) {
  for (let i = 0; i < 9; i++) {
    if (tablero[fila][i] === num) return false;
  }
  return true;
}

function esValidoEnColumna(tablero, num, col) {
  for (let i = 0; i < 9; i++) {
    if (tablero[i][col] === num) return false;
  }
  return true;
}

function esValidoEnCaja(tablero, num, fila, col) {
  let inicioFilaCaja = fila - (fila % 3);
  let inicioColCaja = col - (col % 3);
  for (let f = 0; f < 3; f++) {
    for (let c = 0; c < 3; c++) {
      if (tablero[inicioFilaCaja + f][inicioColCaja + c] === num) return false;
    }
  }
  return true;
}

function esValido(tablero, num, fila, col) {
  // OJO: La validación para el *generador* es diferente a la del *jugador*.
  // Esta es para el generador.
  return (
    esValidoEnFila(tablero, num, fila) &&
    esValidoEnColumna(tablero, num, col) &&
    esValidoEnCaja(tablero, num, fila, col)
  );
}

// --- HERRAMIENTAS DEL GENERADOR (Backtracking) ---
function encontrarSiguienteVacia(tablero) {
  for (let f = 0; f < 9; f++) {
    for (let c = 0; c < 9; c++) {
      if (tablero[f][c] === 0) return [f, c];
    }
  }
  return [-1, -1];
}

function barajarNumeros(array) {
  for (let i = array.length - 1; i > 0; i--) {
    const j = Math.floor(Math.random() * (i + 1));
    [array[i], array[j]] = [array[j], array[i]];
  }
  return array;
}

function resolver(tablero) {
  let [fila, col] = encontrarSiguienteVacia(tablero);
  if (fila === -1) return true;

  let numeros = barajarNumeros([1, 2, 3, 4, 5, 6, 7, 8, 9]);

  for (let num of numeros) {
    if (esValido(tablero, num, fila, col)) {
      tablero[fila][col] = num;
      if (resolver(tablero)) return true;
      tablero[fila][col] = 0;
    }
  }
  return false;
}

function generarSudokuResuelto() {
  let tableroVacio = Array(9).fill(0).map(() => Array(9).fill(0));
  resolver(tableroVacio);
  return tableroVacio;
}

// --- HERRAMIENTAS DE JUEGO ---
function getRandomInt(min, max) {
  min = Math.ceil(min);
  max = Math.floor(max);
  return Math.floor(Math.random() * (max - min + 1)) + min;
}

function imprimirTablero(tableroAImprimir) {
  console.log("\n    0 1 2   3 4 5   6 7 8  ");
  console.log("  |=======|=======|=======|");
  for (let f = 0; f < 9; f++) {
    let linea = f + " | ";
    for (let c = 0; c < 9; c++) {
      linea += (tableroAImprimir[f][c] === 0 ? ". " : tableroAImprimir[f][c] + " ");
      if ((c + 1) % 3 === 0) linea += "| ";
    }
    console.log(linea);
    if ((f + 1) % 3 === 0) console.log("  |=======|=======|=======|");
  }
  console.log("  \n");
}

function crearTableroUsuario(sudokuResuelto, dificultadKey) {
  // 1. Clonamos el tablero resuelto
  let sudokuUsuario = structuredClone(sudokuResuelto);

  // 2. Obtenemos los ajustes de la dificultad
  let settings = DIFICULTADES[dificultadKey];
  let numerosAMostrar = getRandomInt(settings.min, settings.max);
  let numerosAOcultar = 81 - numerosAMostrar;

  // 3. Hacemos los huecos
  let celdasOcultadas = 0;
  while (celdasOcultadas < numerosAOcultar) {
    let fila = getRandomInt(0, 8);
    let col = getRandomInt(0, 8);
    if (sudokuUsuario[fila][col] !== 0) {
      sudokuUsuario[fila][col] = 0;
      celdasOcultadas++;
    }
  }
  return sudokuUsuario;
}

// Función para verificar si el tablero del usuario está completo
function estaCompleto(tablero) {
  let [fila, col] = encontrarSiguienteVacia(tablero);
  return fila === -1; // Si no hay celdas vacías, está completo
}

// 4. EL MOTOR PRINCIPAL DEL JUEGO

function iniciarJuego() {
  console.log("¡Bienvenido al Sudoku de Consola!");
  
  // Generamos la solución UNA SOLA VEZ al inicio
  console.log("Generando un nuevo tablero... ¡Paciencia!");
  const sudokuResuelto = generarSudokuResuelto();
  
  let dificultadIndex = 0; // Empezamos en 'MF'
  let nivelDentroDeDificultad = 1;

  // Bucle principal del juego (progresión de niveles)
  while (dificultadIndex < ORDEN_DIFICULTAD.length) {
    
    let keyDificultadActual = ORDEN_DIFICULTAD[dificultadIndex];
    let configActual = DIFICULTADES[keyDificultadActual];
    
    // Preparamos el nivel
    let vidas = VIDAS_INICIALES;
    let sudokuUsuario = crearTableroUsuario(sudokuResuelto, keyDificultadActual);
    // Guardamos las celdas originales para que el usuario no las borre
    const celdasOriginales = structuredClone(sudokuUsuario);

    console.log(`\n--- Dificultad: ${configActual.nombre} | Nivel: ${nivelDentroDeDificultad} / ${NIVELES_POR_DIFICULTAD} ---`);

    // Bucle del nivel actual (mientras haya vidas)
    while (vidas > 0) {
      imprimirTablero(sudokuUsuario);
      console.log(`Vidas restantes: ${'X '.repeat(vidas)}`);

      // --- Pedir datos al usuario ---
      let fila = parseInt(prompt("Ingresa la fila (0-8): "));
      let col = parseInt(prompt("Ingresa la columna (0-8): "));
      let num = parseInt(prompt("Ingresa el número (1-9): "));

      // --- Validar la entrada del usuario ---
      if (isNaN(fila) || isNaN(col) || isNaN(num) ||
          fila < 0 || fila > 8 || col < 0 || col > 8 || num < 1 || num > 9) {
        console.log("¡Entrada inválida! Introduce números entre 0-8 para fila/col y 1-9 para el número.");
        continue; // Saltamos al inicio del bucle
      }

      // Validar si la celda es una de las originales
      if (celdasOriginales[fila][col] !== 0) {
        console.log("¡No puedes modificar una celda original del tablero!");
        continue;
      }
      
      // --- Comprobar la jugada ---
      if (sudokuResuelto[fila][col] === num) {
        console.log("¡Correcto!");
        sudokuUsuario[fila][col] = num;

        // Comprobar si ganó
        if (estaCompleto(sudokuUsuario)) {
          console.log(`Felicidades Completaste el Nivel ${nivelDentroDeDificultad} de ${configActual.nombre}!`);
          break; // Salimos del bucle de vidas para pasar al siguiente nivel
        }

      } else {
        vidas--;
        console.log(`¡Incorrecto! El número ${num} no va en esa posición.`);
        if (vidas === 0) {
          console.log(`GAME OVER. Te has quedado sin vidas.`);
          console.log("El tablero se reiniciará en el mismo nivel.");
          // No hacemos 'break', el bucle while(vidas > 0) terminará solo
        }
      }
    } // Fin del bucle de vidas

    // Si salimos del bucle de vidas y el tablero está completo, pasamos de nivel
    if (estaCompleto(sudokuUsuario)) {
      nivelDentroDeDificultad++;
      
      // Si completamos los 5 niveles, pasamos a la siguiente dificultad
      if (nivelDentroDeDificultad > NIVELES_POR_DIFICULTAD) {
        dificultadIndex++;
        nivelDentroDeDificultad = 1; // Reseteamos el contador de nivel
        if (dificultadIndex >= ORDEN_DIFICULTAD.length) {
            console.log("¡FELICIDADES! ¡Has completado todas las dificultades!");
        } else {
            console.log(`¡Subes a dificultad ${DIFICULTADES[ORDEN_DIFICULTAD[dificultadIndex]].nombre}!`);
        }
      }
    }
    // Si salimos por vidas=0, el bucle principal se repite,
    // pero como 'dificultadIndex' y 'nivelDentroDeDificultad' no cambiaron,
    // simplemente se "resetea" el nivel actual.
    
  } // Fin del bucle principal del juego
}

// 5. ¡INICIAR EL JUEGO!
iniciarJuego();

