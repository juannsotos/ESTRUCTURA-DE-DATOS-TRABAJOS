#include <iostream>
#include <cstdlib>
using namespace std;

struct node {
    int data;
    node* next;
    node* prev;
};

node* head = NULL;

void begininsert() {
    int item;
    cin >> item;
    node* ptr = (node*)malloc(sizeof(node));
    ptr->data = item;
    if (head == NULL) {
        head = ptr;
        ptr->next = ptr;
        ptr->prev = ptr;
    } else {
        node* last = head->prev;
        ptr->next = head;
        ptr->prev = last;
        last->next = ptr;
        head->prev = ptr;
        head = ptr;
    }
}

void lastinsert() {
    int item;
    cin >> item;
    node* ptr = (node*)malloc(sizeof(node));
    ptr->data = item;
    if (head == NULL) {
        head = ptr;
        ptr->next = ptr;
        ptr->prev = ptr;
    } else {
        node* last = head->prev;
        last->next = ptr;
        ptr->prev = last;
        ptr->next = head;
        head->prev = ptr;
    }
}

void randominsert() {
    int item, loc;
    cin >> item >> loc;
    if (head == NULL) return;
    node* temp = head;
    for (int i = 0; i < loc; i++) {
        temp = temp->next;
        if (temp == head) return;
    }
    node* ptr = (node*)malloc(sizeof(node));
    ptr->data = item;
    node* nxt = temp->next;
    ptr->next = nxt;
    ptr->prev = temp;
    temp->next = ptr;
    nxt->prev = ptr;
}

void begin_delete() {
    if (head == NULL) return;
    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }
    node* last = head->prev;
    node* temp = head;
    head = head->next;
    head->prev = last;
    last->next = head;
    free(temp);
}

void last_delete() {
    if (head == NULL) return;
    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }
    node* last = head->prev;
    node* prev = last->prev;
    prev->next = head;
    head->prev = prev;
    free(last);
}

void random_delete() {
    int loc;
    cin >> loc;
    if (head == NULL) return;
    node* temp = head;
    for (int i = 0; i < loc; i++) {
        temp = temp->next;
        if (temp == head) return;
    }
    node* ptr = temp->next;
    if (ptr == head) return;
    temp->next = ptr->next;
    ptr->next->prev = temp;
    free(ptr);
}

void search_item() {
    if (head == NULL) return;
    int item;
    cin >> item;
    node* temp = head;
    int i = 1;
    bool flag = true;
    while (true) {
        if (temp->data == item) {
            cout << i << endl;
            flag = false;
        }
        temp = temp->next;
        i++;
        if (temp == head) break;
    }
    if (flag) cout << "no" << endl;
}

void display() {
    if (head == NULL) return;
    node* temp = head;
    while (true) {
        cout << temp->data << endl;
        temp = temp->next;
        if (temp == head) break;
    }
}

int main() {
    int choice;
    while (true) {
        cout << "1\n2\n3\n4\n5\n6\n7\n8\n9\n";
        cin >> choice;
        if (choice == 1) begininsert();
        else if (choice == 2) lastinsert();
        else if (choice == 3) randominsert();
        else if (choice == 4) begin_delete();
        else if (choice == 5) last_delete();
        else if (choice == 6) random_delete();
        else if (choice == 7) search_item();
        else if (choice == 8) display();
        else if (choice == 9) break;
    }
}
