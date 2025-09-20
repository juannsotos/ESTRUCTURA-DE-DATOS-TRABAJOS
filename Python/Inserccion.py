import random
arr = []
for i in range(10):
    arr.append(random.randint(1,100))

print("El arreglo desordenado es: ", arr)

for i in range(1,len(arr)):
    actual = arr[i]
    j = i -1 
    while j >= 0 and arr[j] > actual:
        arr[j+1] = arr[j]
        j -= 1
    arr[j+1] = actual

print("El arreglo ordenado es: ", arr)