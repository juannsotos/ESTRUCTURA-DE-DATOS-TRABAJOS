max = 100
min = 1
arr = []

for (let i = 0; i < 10; i++){
    let n =  Math.floor(Math.random() * (max - min + 1)) + min
    arr[i] = n
}
console.log("El array desordenado es: ")
console.log(arr.join(", "));
console.log("\n")


for (let i = 0; i < arr.length; i++){
    for(let j = 0; j < arr.length-1-i; j++){
        if (arr[j] > arr[j+1]){
            let temp = arr[j]
            arr[j] = arr[j+1]
            arr[j+1] = temp
        }
    }
}

console.log("El arreglo ordenado es: ")
console.log(arr.join(", "));

