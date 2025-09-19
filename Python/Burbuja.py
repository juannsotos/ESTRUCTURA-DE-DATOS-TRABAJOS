import random
arr = []
for i in range(10):
    arr.append(random.randint(1,100))

print("El arreglo sin ordenarse es: ", arr)
for i in range(len(arr)):
    for j in range(len(arr) - i -1):
        if arr[j] > arr[j+1]:
            temp = arr[j]
            arr[j] = arr[j+1]
            arr[j+1] = temp

print("El arreglo ya ordenado es: ", arr)