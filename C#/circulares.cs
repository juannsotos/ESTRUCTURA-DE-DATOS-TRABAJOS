using System;

class Node {
    public int data;
    public Node next, prev;
}

class Program {
    static Node head = null;

    static void BeginInsert() {
        Node ptr = new Node();
        ptr.data = int.Parse(Console.ReadLine());
        if (head == null) {
            ptr.next = ptr;
            ptr.prev = ptr;
            head = ptr;
        } else {
            ptr.next = head;
            ptr.prev = head.prev;
            head.prev.next = ptr;
            head.prev = ptr;
            head = ptr;
        }
    }

    static void LastInsert() {
        Node ptr = new Node();
        ptr.data = int.Parse(Console.ReadLine());
        if (head == null) {
            ptr.next = ptr;
            ptr.prev = ptr;
            head = ptr;
        } else {
            ptr.next = head;
            ptr.prev = head.prev;
            head.prev.next = ptr;
            head.prev = ptr;
        }
    }

    static void RandomInsert() {
        Node ptr = new Node();
        ptr.data = int.Parse(Console.ReadLine());
        int loc = int.Parse(Console.ReadLine());
        Node temp = head;
        for (int i = 0; i < loc; i++) temp = temp.next;
        ptr.next = temp.next;
        ptr.prev = temp;
        temp.next.prev = ptr;
        temp.next = ptr;
    }

    static void BeginDelete() {
        if (head == null) return;
        if (head.next == head) head = null;
        else {
            Node ptr = head;
            head.prev.next = head.next;
            head.next.prev = head.prev;
            head = head.next;
        }
    }

    static void LastDelete() {
        if (head == null) return;
        if (head.next == head) head = null;
        else {
            Node ptr = head.prev;
            ptr.prev.next = head;
            head.prev = ptr.prev;
        }
    }

    static void RandomDelete() {
        int loc = int.Parse(Console.ReadLine());
        Node temp = head;
        for (int i = 0; i < loc; i++) temp = temp.next;
        Node ptr = temp.next;
        temp.next = ptr.next;
        ptr.next.prev = temp;
    }

    static void Search() {
        int item = int.Parse(Console.ReadLine());
        int pos = 1, found = 0;
        if (head == null) return;
        Node ptr = head;
        do {
            if (ptr.data == item) found = pos;
            ptr = ptr.next;
            pos++;
        } while (ptr != head);
        if (found != 0) Console.Write(found);
        else Console.Write("no");
    }

    static void Display() {
        if (head == null) return;
        Node ptr = head;
        do {
            Console.Write(ptr.data + " ");
            ptr = ptr.next;
        } while (ptr != head);
    }

    static void Main() {
        int choice;
        while (true) {
            choice = int.Parse(Console.ReadLine());
            if (choice == 1) BeginInsert();
            else if (choice == 2) LastInsert();
            else if (choice == 3) RandomInsert();
            else if (choice == 4) BeginDelete();
            else if (choice == 5) LastDelete();
            else if (choice == 6) RandomDelete();
            else if (choice == 7) Search();
            else if (choice == 8) Display();
            else if (choice == 9) break;
        }
    }
}
