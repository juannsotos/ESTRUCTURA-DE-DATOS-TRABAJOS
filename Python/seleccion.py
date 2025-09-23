import random
arr = []
for i in range(10):
    arr.append(random.randint(1,100))

print("El arreglo desordenado es: ", arr)

def seleccion(arr):
    for i in range(len(arr)):
        min = i 
        for j in range(i+1,len(arr)):
            if arr[min] > arr[j]:
                min = j

        temp = arr[i]
        arr[i] = arr[min]
        arr[min] = temp

    return arr
    
print("El arreglo ordenado es: ", seleccion(arr))
