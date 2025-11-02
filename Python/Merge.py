def merge(a, l, m, r):  # Merge dos subarreglos de a[]
    a1 = m - l + 1      # Tamaño del primer subarreglo
    a2 = r - m          # Tamaño del segundo subarreglo

    # Crear arreglos temporales
    L = [0] * a1
    R = [0] * a2

    # Copiar datos a los arreglos temporales
    for j in range(0, a1):
        L[j] = a[l + j]
    for k in range(0, a2):
        R[k] = a[m + 1 + k]

    i = 0
    j = 0
    k = l

    # Mezclar los arreglos temporales de nuevo en a[l..r]
    while i < a1 and j < a2:
        if L[i] <= R[j]:
            a[k] = L[i]
            i += 1
        else:
            a[k] = R[j]
            j += 1
        k += 1

    # Copiar los elementos restantes de L[], si hay alguno
    while i < a1:
        a[k] = L[i]
        i += 1
        k += 1

    # Copiar los elementos restantes de R[], si hay alguno
    while j < a2:
        a[k] = R[j]
        j += 1
        k += 1


def mergeSort(a, l, r):
    if l < r:
        m = l + (r - l) // 2
        mergeSort(a, l, m)
        mergeSort(a, m + 1, r)
        merge(a, l, m, r)


# Código para probar la implementación
a = [39, 28, 44, 11]
s = len(a)
print("Antes de ordenar el arreglo:", a)
mergeSort(a, 0, s - 1)
print("Después de ordenar el arreglo:", a)