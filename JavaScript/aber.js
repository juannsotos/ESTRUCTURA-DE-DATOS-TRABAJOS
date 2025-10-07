console.log("como es esto")
console.log("le cambie algo para ver")
console.log("ahora si le muevo despues de un dia que pasa")

const readline = require('readline'); // Importar el módulo readline

const rl = readline.createInterface({
  input: process.stdin, // Entrada estándar (la consola)
  output: process.stdout // Salida estándar (la consola)
});

rl.question('¿Cuál es tu nombre? ', (nombre) => { // Pregunta al usuario
  console.log(`¡Hola, ${nombre}!`); // Muestra el nombre ingresado
  rl.close(); // Cierra la interfaz
});