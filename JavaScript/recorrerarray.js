a = [2,45,4,6,3]

for (let i =0; i < a.length; i++){
    console.log("Posicion: ", i, ' valor: ', a[i])
}

///Buscar el numero en un array, no pude pedir el dato tengo que abrirlo en navegador jajaj
console.log(" ")
b = [20,32,13,543,7]
let numero = 2
console.log("Busqueda de numero en array")

function buscar_numero(b,numero){
    for (let i = 0; i < b.length; i++){
        if (b[i] === numero){
            return i 
        }
    }
    return "no esta"
}

let resultado = buscar_numero(b,numero)
console.log("posicion de numero: ", resultado)
 
///Inserccion de numero en array
console.log(" ")
c = [11,35,31,66,12]
indice = 1 //se supone que se pide
valor = 77 //esto tmb

for (let i = c.length - 1; i > indice; i--){
    c[i] = c[i-1]
}

c[indice] = valor
console.log(c)
