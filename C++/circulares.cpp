#include <iostream>
#include <cstdlib>
using namespace std;

struct node {
    int data;
    node *next;
    node *prev;
};

node *head = NULL;

void begininsert() {
    int item;
    node *ptr = (node*)malloc(sizeof(node));
    cin >> item;
    ptr->data = item;
    if (head == NULL) {
        ptr->next = ptr;
        ptr->prev = ptr;
        head = ptr;
    } else {
        ptr->next = head;
        ptr->prev = head->prev;
        head->prev->next = ptr;
        head->prev = ptr;
        head = ptr;
    }
}

void lastinsert() {
    int item;
    node *ptr = (node*)malloc(sizeof(node));
    cin >> item;
    ptr->data = item;
    if (head == NULL) {
        ptr->next = ptr;
        ptr->prev = ptr;
        head = ptr;
    } else {
        ptr->next = head;
        ptr->prev = head->prev;
        head->prev->next = ptr;
        head->prev = ptr;
    }
}

void randominsert() {
    int item, loc;
    node *ptr = (node*)malloc(sizeof(node));
    cin >> item;
    ptr->data = item;
    cin >> loc;
    node *temp = head;
    for (int i = 0; i < loc; i++) temp = temp->next;
    ptr->next = temp->next;
    ptr->prev = temp;
    temp->next->prev = ptr;
    temp->next = ptr;
}

void begin_delete() {
    if (head == NULL) return;
    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        node *ptr = head;
        head->prev->next = head->next;
        head->next->prev = head->prev;
        head = head->next;
        free(ptr);
    }
}

void last_delete() {
    if (head == NULL) return;
    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        node *ptr = head->prev;
        ptr->prev->next = head;
        head->prev = ptr->prev;
        free(ptr);
    }
}

void random_delete() {
    int loc;
    cin >> loc;
    node *temp = head;
    for (int i = 0; i < loc; i++) temp = temp->next;
    node *ptr = temp->next;
    temp->next = ptr->next;
    ptr->next->prev = temp;
    free(ptr);
}

void search_value() {
    int item, pos = 1, found = 0;
    cin >> item;
    if (head == NULL) return;
    node *ptr = head;
    do {
        if (ptr->data == item) found = pos;
        ptr = ptr->next;
        pos++;
    } while (ptr != head);
    if (found) cout << found;
    else cout << "no encontrado";
}

void display() {
    if (head == NULL) return;
    node *ptr = head;
    do {
        cout << ptr->data << " ";
        ptr = ptr->next;
    } while (ptr != head);
}

int main() {
    int choice;
    while (true) {
        cin >> choice;
        if (choice == 1) begininsert();
        else if (choice == 2) lastinsert();
        else if (choice == 3) randominsert();
        else if (choice == 4) begin_delete();
        else if (choice == 5) last_delete();
        else if (choice == 6) random_delete();
        else if (choice == 7) search_value();
        else if (choice == 8) display();
        else if (choice == 9) break;
    }
}
