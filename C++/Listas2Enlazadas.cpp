#include <iostream>
#include <cstdlib>

using namespace std;

struct node {
    int data;
    struct node *next;
    struct node *prev; // nuevo puntero para el nodo anterior
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
        cout << "\n\n*********menu principal*********\n";
        cout << "\nelige una opcion de la siguiente lista ...\n";
        cout << "\n===============================================\n";
        cout << "\n1. insertar al principio\n2. insertar al final\n3. insertar despues de posicion\n4. eliminar del principio\n"
             << "5. eliminar del final\n6. eliminar despues de posicion\n7. buscar elemento\n8. mostrar lista\n9. salir\n";
        cout << "\ningrese su opcion?\n";
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
            default: cout << "introduzca una opcion valida..";
        }
    }
    return 0;
}

void begininsert() {
    struct node *ptr;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        cout << "\noverflow";
    } else {
        cout << "\ningrese valor\n";
        cin >> item;
        ptr->data = item;
        ptr->prev = NULL;
        ptr->next = head;
        if (head != NULL) {
            head->prev = ptr;
        }
        head = ptr;
        cout << "\nnodo insertado";
    }
}

void lastinsert() {
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        cout << "\noverflow";
    } else {
        cout << "\ningrese valor?\n"; cin >> item;
        ptr->data = item;
        ptr->next = NULL; // como sera el ultimo, next es null
        if (head == NULL) {
            ptr->prev = NULL;
            head = ptr;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp; // conectamos hacia atras
        }
        cout << "\nnodo insertado";
    }
}

void randominsert() {
    int i, loc, item;
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        cout << "\noverflow";
    } else {
        cout << "\nintroduzca el valor del elemento";
        cin >> item;
        ptr->data = item;
        cout << "\nintroduce la ubicacion despues de la cual deseas insertar "; cin >> loc;
        temp = head;
        for (i = 0; i < loc; i++) {
            temp = temp->next;
            if (temp == NULL) {
                cout << "\nno se puede insertar\n";
                return;
            }
        }
        // logica para doble enlace
        ptr->next = temp->next;
        ptr->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = ptr;
        }
        temp->next = ptr;
        cout << "\nnodo insertado";
    }
}

void begin_delete() {
    struct node *ptr;
    if (head == NULL) {
        cout << "\nla lista esta vacia\n";
    } else {
        ptr = head;
        head = ptr->next;
        if (head != NULL) {
            head->prev = NULL; // desconectamos el anterior del nuevo head
        }
        free(ptr);
        cout << "\nnodo eliminado desde el principio ...\n";
    }
}

void last_delete() {
    struct node *ptr;
    if (head == NULL) {
        cout << "\nla lista esta vacia";
    } else if (head->next == NULL) {
        free(head);
        head = NULL;
        cout << "\nsolo se elimino un nodo de la lista ...\n";
    } else {
        ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->prev->next = NULL; // el penultimo ahora apunta a null
        free(ptr);
        cout << "\nnodo eliminado del ultimo ...\n";
    }
}

void random_delete() {
    struct node *ptr, *temp;
    int loc, i;
    cout << "\n introduzca la ubicacion despues de la cual desea realizar la eliminacion \n";
    cin >> loc;
    temp = head;
    // buscamos el nodo ANTERIOR al que vamos a borrar
    for (i = 0; i < loc; i++) {
        temp = temp->next;
        if (temp == NULL) {
            cout << "\nno se puede eliminar";
            return;
        }
    }
    // temp esta en el nodo previo al que borraremos
    if (temp->next == NULL) {
        cout << "\nno se puede eliminar";
        return;
    }
    ptr = temp->next; // ptr es el nodo a borrar
    temp->next = ptr->next;
    if (ptr->next != NULL) {
        ptr->next->prev = temp;
    }
    free(ptr);
    cout << "\nnodo eliminado " << loc + 1;
}

void search() {
    struct node *ptr;
    int item, i = 0, flag = 1;
    ptr = head;
    if (ptr == NULL) {
        cout << "\nlista vacia\n";
    } else {
        cout << "\nintroduce el elemento que deseas buscar?\n"; cin >> item;
        while (ptr != NULL) {
            if (ptr->data == item) {
                cout << "elemento encontrado en la ubicacion " << i + 1;
                flag = 0;
            } else {
                flag = 1;
            }
            i++;
            ptr = ptr->next;
        }
        if (flag == 1) {
            cout << "elemento no encontrado\n";
        }
    }
}

void display() {
    struct node *ptr;
    ptr = head;
    if (ptr == NULL) {
        cout << "nada que imprimir";
    } else {
        cout << "\nimprimiendo valores . . . . .\n";
        while (ptr != NULL) {
            cout << "\n" << ptr->data;
            ptr = ptr->next;
        }
    }
}