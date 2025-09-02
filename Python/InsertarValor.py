array = [2,4,5,67,43,34,6]  

valor =  int(input("Ingresa el valor que deseas agregar; "))
n = int(input("Ingresa el indice; "))


for i in range(len(array)-1,n,-1):
    array[i] = array[i-1]
    
array[n] = valor
    
print(array)


