array = [2,4,5,67,43,34,6]  

valor =  int(input("Ingresa el valor que deseas agregar; "))
n = int(input("Ingresa el indice; "))

for i in range(len(array)-1,n,-1):
    array[i] = array[i-1]
    
array[n] = valor
print(array)


print("\n Busqueda de numero")
#Esto es otra cosa
num = int(input("Coloca el numero a comparar: "))
arr1 = [450,403,340,213,12,5]

def buscar_numero_en_arreglo(arr1,num):
    for i in range(len(arr1)):
         if arr1[i] == num:
             return i
    return "No se encuentra dentro del array"
        
resultado = buscar_numero_en_arreglo(arr1,num)
print(" Posicion de numero:", resultado)
         


