arr = []

for (let i  = 0; i < 10; i++){
    let n =  Math.floor(Math.random() * (100 - 1 + 1)) + 1
    arr[i] = n
}
console.log("El array desordenado es: ")
console.log(arr.join(", "));
console.log("\n")

for (let i = 1; i < arr.length; i++){
    let actual = arr[i]
    let j = i - 1
    while (j >= 0 && arr[j] > actual){
        arr[j+1] = arr[j]
        j = j - 1

    }
    arr[j+1] = actual
}

console.log("Ordenado es: ")
console.log(arr.join(", "));
