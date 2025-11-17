#include <iostream>
#include <cstdlib>

using namespace std;

struct node {
    int data;
    struct node *next;
};

struct node *head;

void begininsert();
void lastinsert();
void randominsert();
void begin_delete();
void last_delete();
void random_delete();
void display();
void search();

int main() {
    int choice = 0;
    while (choice != 9) {
        cout << "\n\n*********Menú principal*********\n";
        cout << "\nElige una opción de la siguiente lista ...\n";
        cout << "\n===============================================\n";
        cout << "\n1. Insertar al principio\n2. Insertar al final\n3. Insertar\n4. Eliminar del principio\n"
             << "5. Eliminar desde el último\n6. Eliminar nodo después de la ubicación especificada\n7. Buscar un elemento\n8. Mostrar\n9. Salir\n";
        cout << "\nIngrese su opción?\n";
        cin >> choice;

        switch (choice) {
            case 1: begininsert(); break;
            case 2: lastinsert(); break;
            case 3: randominsert(); break;
            case 4: begin_delete(); break;
            case 5: last_delete(); break;
            case 6: random_delete(); break;
            case 7: search(); break;
            case 8: display(); break;
            case 9: exit(0); break;
            default: cout << "Introduzca una opción válida..";
        }
    }
    return 0;
}

void begininsert() {
    struct node *ptr;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        cout << "\nOVERFLOW";
    } else {
        cout << "\nIngrese valor\n";
        cin >> item;
        ptr->data = item;
        ptr->next = head;
        head = ptr;
        cout << "\nNodo insertado";
    }
}

void lastinsert() {
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        cout << "\nOVERFLOW";
    } else {
        cout << "\nIngrese valor?\n"; cin >> item;
        ptr->data = item;
        if (head == NULL) {
            ptr->next = NULL;
            head = ptr;
            cout << "\nNodo insertado";
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = NULL;
            cout << "\nNodo insertado";
        }
    }
}

void randominsert() {
    int i, loc, item;
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        cout << "\nOVERFLOW";
    } else {
        cout << "\nIntroduzca el valor del elemento";
        cin >> item;
        ptr->data = item;
        cout << "\nIntroduce la ubicación después de la cual deseas insertar "; cin >> loc;
        temp = head;
        for (i = 0; i < loc; i++) {
            temp = temp->next;
            if (temp == NULL) {
                cout << "\nNo se puede insertar\n";
                return;
            }
        }
        ptr->next = temp->next;
        temp->next = ptr;
        cout << "\nNodo insertado";
    }
}

void begin_delete() {
    struct node *ptr;
    if (head == NULL) {
        cout << "\nLa lista está vacía\n";
    } else {
        ptr = head;
        head = ptr->next;
        free(ptr); // Usamos free porque usamos malloc, aunque delete también funciona en C++
        cout << "\nNodo eliminado desde el principio ...\n";
    }
}

void last_delete() {
    struct node *ptr, *ptr1;
    if (head == NULL) {
        cout << "\nLa lista está vacía";
    } else if (head->next == NULL) {
        head = NULL;
        free(head);
        cout << "\nSolo se eliminó un nodo de la lista ...\n";
    } else {
        ptr = head;
        while (ptr->next != NULL) {
            ptr1 = ptr;
            ptr = ptr->next;
        }
        ptr1->next = NULL;
        free(ptr);
        cout << "\nNodo eliminado del último ...\n";
    }
}

void random_delete() {
    struct node *ptr, *ptr1;
    int loc, i;
    cout << "\n Introduzca la ubicación del nodo después del cual desea realizar la eliminación. \n";
    cin >> loc;
    ptr = head;
    for (i = 0; i < loc; i++) {
        ptr1 = ptr;
        ptr = ptr->next;
        if (ptr == NULL) {
            cout << "\nNo se puede eliminar";
            return;
        }
    }
    ptr1->next = ptr->next;
    free(ptr);
    cout << "\nNodo eliminado " << loc + 1;
}

void search() {
    struct node *ptr;
    int item, i = 0, flag = 1; // Inicializo flag en 1 por seguridad
    ptr = head;
    if (ptr == NULL) {
        cout << "\nLista vacía\n";
    } else {
        cout << "\nIntroduce el elemento que deseas buscar?\n"; cin >> item;
        while (ptr != NULL) {
            if (ptr->data == item) {
                cout << "Elemento encontrado en la ubicación " << i + 1;
                flag = 0;
            } else {
                flag = 1;
            }
            i++;
            ptr = ptr->next;
        }
        if (flag == 1) {
            cout << "Elemento no encontrado\n";
        }
    }
}

void display() {
    struct node *ptr;
    ptr = head;
    if (ptr == NULL) {
        cout << "Nada que imprimir";
    } else {
        cout << "\nimprimiendo valores . . . . .\n";
        while (ptr != NULL) {
            cout << "\n" << ptr->data;
            ptr = ptr->next;
        }
    }
}
