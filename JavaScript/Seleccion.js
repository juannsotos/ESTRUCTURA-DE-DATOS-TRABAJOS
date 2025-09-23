arr = []

for (let i  = 0; i < 10; i++){
    let n =  Math.floor(Math.random() * (100 - 1 + 1)) + 1
    arr[i] = n
}
console.log("El array desordenado es: ")
console.log(arr.join(", "));
console.log("\n")

for (let i = 0; i < arr.length; i++){
    let min = i
    for (let j = i +1; j < arr.length; j++){
        if (arr[min] > arr[j]){
            min = j
        }
    }
    let temp = arr[i]
    arr[i] = arr[min]
    arr[min] = temp
}

console.log("El array ordenado es: ")
console.log(arr.join(", "));
console.log("\n")