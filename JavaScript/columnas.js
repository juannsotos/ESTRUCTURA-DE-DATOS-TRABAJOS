r = 3, c = 3
let arr = new Array(r*c);

TwoDArray = [
    [1,2,3],
    [4,5,6],
    [7,8,9]
]

let k = 0
for (let y = 0; y < c; y++){
    for(let x =0; x < r; x++){
         k = y * r + x
         arr[k] = TwoDArray[x][y]
    }
}

console.log("Los elementos del array bidimensional son: ")
for (let x = 0; x < r; x++){
    console.log(TwoDArray[x].join(" "))
}

console.log("\nLos elementos del array unidimensional son: ")
console.log(arr.join(" "))