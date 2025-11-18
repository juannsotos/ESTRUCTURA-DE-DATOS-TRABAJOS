import sys

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None # nuevo puntero

head = None

def begininsert():
    global head
    print("\ningrese valor")
    item = int(input())
    ptr = Node(item)
    ptr.next = head
    if head is not None:
        head.prev = ptr
    head = ptr
    print("\nnodo insertado")

def lastinsert():
    global head
    print("\ningrese valor?")
    item = int(input())
    ptr = Node(item)
    if head is None:
        head = ptr
    else:
        temp = head
        while temp.next is not None:
            temp = temp.next
        temp.next = ptr
        ptr.prev = temp
    print("\nnodo insertado")

def randominsert():
    global head
    print("\nintroduzca el valor del elemento")
    item = int(input())
    ptr = Node(item)
    print("\nintroduce la ubicacion despues de la cual deseas insertar ")
    loc = int(input())
    temp = head
    for i in range(loc):
        temp = temp.next
        if temp is None:
            print("\nno se puede insertar")
            return
    ptr.next = temp.next
    ptr.prev = temp
    if temp.next is not None:
        temp.next.prev = ptr
    temp.next = ptr
    print("\nnodo insertado")

def begin_delete():
    global head
    if head is None:
        print("\nla lista esta vacia")
    else:
        head = head.next
        if head is not None:
            head.prev = None
        print("\nnodo eliminado desde el principio ...")

def last_delete():
    global head
    if head is None:
        print("\nla lista esta vacia")
    elif head.next is None:
        head = None
        print("\nsolo se elimino un nodo de la lista ...")
    else:
        ptr = head
        while ptr.next is not None:
            ptr = ptr.next
        ptr.prev.next = None
        print("\nnodo eliminado del ultimo ...")

def random_delete():
    global head
    print("\n introduzca la ubicacion despues de la cual desea realizar la eliminacion")
    loc = int(input())
    temp = head
    for i in range(loc):
        temp = temp.next
        if temp is None:
            print("\nno se puede eliminar")
            return
    
    if temp.next is None:
        print("\nno se puede eliminar")
        return

    ptr = temp.next
    temp.next = ptr.next
    if ptr.next is not None:
        ptr.next.prev = temp
    print(f"\nnodo eliminado {loc + 1}")

def search():
    global head
    ptr = head
    i = 0
    flag = 1
    if ptr is None:
        print("\nlista vacia")
    else:
        print("\nintroduce el elemento que deseas buscar?")
        item = int(input())
        while ptr is not None:
            if ptr.data == item:
                print(f"elemento encontrado en la ubicacion {i + 1}")
                flag = 0
            else:
                flag = 1
            i += 1
            ptr = ptr.next
        if flag == 1:
            print("elemento no encontrado")

def display():
    global head
    ptr = head
    if ptr is None:
        print("nada que imprimir")
    else:
        print("\nimprimiendo valores . . . . .")
        while ptr is not None:
            print(f"\n{ptr.data}")
            ptr = ptr.next

def main():
    choice = 0
    while choice != 9:
        print("\n\n*********menu principal*********")
        print("\nelige una opcion de la siguiente lista ...")
        print("\n===============================================")
        print("\n1. insertar al principio\n2. insertar al final\n3. insertar despues de posicion\n4. eliminar del principio")
        print("5. eliminar del final\n6. eliminar despues de posicion\n7. buscar elemento\n8. mostrar lista\n9. salir")
        print("\ningrese su opcion?")
        try:
            choice = int(input())
        except ValueError:
            print("entrada invalida")
            continue

        if choice == 1: begininsert()
        elif choice == 2: lastinsert()
        elif choice == 3: randominsert()
        elif choice == 4: begin_delete()
        elif choice == 5: last_delete()
        elif choice == 6: random_delete()
        elif choice == 7: search()
        elif choice == 8: display()
        elif choice == 9: sys.exit(0)
        else: print("introduzca una opcion valida..")

if __name__ == "__main__":
    main()