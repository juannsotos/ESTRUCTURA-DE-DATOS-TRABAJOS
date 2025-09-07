r = 3; c = 3
arr = [0] * r * c

TwoDArray = [
    [1,2,3],
    [4,5,6],
    [7,8,9]
]


k = 0
for x in range(r):
    for y in range(c):
        k = x * r + y
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