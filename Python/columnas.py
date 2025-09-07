r = 3; c = 3
arr = [0] * r * c

TwoDArray = [
    [1,2,3],
    [4,5,6],
    [7,8,9]
]
# Es practicamente lo mismo que en filas simplemente invierte los valores de las filas y columnas, osea donde iba la "x" se pone "y" 
k = 0
for y in range(c):
    for x in range(r):
        k = y * r + x
        arr[k] = TwoDArray[x][y]
        k = k + 1 

print("Los elementos del array bidimensional son :")
for row in TwoDArray:
    for elemento in row:
        print(elemento, end=" ")
    print()
    
print("\nLos elementos del array unidimensional son: ")
for x in range(r):
    for y in range(c):
        print((arr[x * r + y]), end=" ")