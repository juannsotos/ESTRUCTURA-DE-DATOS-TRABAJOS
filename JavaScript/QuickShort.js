function swap(arr,i,j){
    let temp = arr[i];  // 1. Guardamos el valor del primer elemento en una variable temporal.
    arr[i] = arr[j];  // 2. Reemplazamos el valor del primer elemento con el del segundo.
    arr[j] = temp; // 3. Asignamos el valor guardado (original del primer elemento) al segundo.
}
function quickshort(arr,inicio,fin){
    if (inicio < fin) {
        let pivot = particion(arr,inicio,fin)
        quickshort(arr,inicio,pivot-1)
        quickshort(arr,pivot+1,fin)

    }
}

function particion(arr,inicio,fin){
    let pivot = arr[fin] // Declaras al Pivot con el ultimo elemento del array
    let i = inicio - 1 // Inicalizas el apuntador

    for (let j = inicio; j < fin; j++){
        if (arr[j] <= pivot){
            i++;
            swap(arr,i,j)
            
        }
    }
    swap(arr,i+1,fin)
    return i + 1
}

arr = []
// ---------------------------------
for (let i  = 0; i < 10; i++){
    let n =  Math.floor(Math.random() * (100 - 1 + 1)) + 1
    arr[i] = n
}
console.log("El array desordenado es: ")
console.log(arr.join(", "));
console.log("\n")
// Todo lo anterior es para generar un arreglo con numeros aleatorios

quickshort(arr,0,arr.length - 1)
console.log("El array ordenado es; ")
console.log(arr.join(", "));
console.log("\n")

