using System;

class Node {
    public int data;
    public Node next;
    public Node prev;
}

class Program {
    static Node head;

    static void begininsert() {
        int item = int.Parse(Console.ReadLine());
        Node ptr = new Node();
        ptr.data = item;
        if (head == null) {
            head = ptr;
            ptr.next = ptr;
            ptr.prev = ptr;
        } else {
            Node last = head.prev;
            ptr.next = head;
            ptr.prev = last;
            last.next = ptr;
            head.prev = ptr;
            head = ptr;
        }
    }

    static void lastinsert() {
        int item = int.Parse(Console.ReadLine());
        Node ptr = new Node();
        ptr.data = item;
        if (head == null) {
            head = ptr;
            ptr.next = ptr;
            ptr.prev = ptr;
        } else {
            Node last = head.prev;
            last.next = ptr;
            ptr.prev = last;
            ptr.next = head;
            head.prev = ptr;
        }
    }

    static void randominsert() {
        int item = int.Parse(Console.ReadLine());
        int loc = int.Parse(Console.ReadLine());
        if (head == null) return;
        Node temp = head;
        for (int i = 0; i < loc; i++) {
            temp = temp.next;
            if (temp == head) return;
        }
        Node ptr = new Node();
        ptr.data = item;
        Node nxt = temp.next;
        ptr.next = nxt;
        ptr.prev = temp;
        temp.next = ptr;
        nxt.prev = ptr;
    }

    static void begin_delete() {
        if (head == null) return;
        if (head.next == head) {
            head = null;
            return;
        }
        Node last = head.prev;
        head = head.next;
        head.prev = last;
        last.next = head;
    }

    static void last_delete() {
        if (head == null) return;
        if (head.next == head) {
            head = null;
            return;
        }
        Node last = head.prev;
        Node prev = last.prev;
        prev.next = head;
        head.prev = prev;
    }

    static void random_delete() {
        int loc = int.Parse(Console.ReadLine());
        if (head == null) return;
        Node temp = head;
        for (int i = 0; i < loc; i++) {
            temp = temp.next;
            if (temp == head) return;
        }
        Node ptr = temp.next;
        if (ptr == head) return;
        temp.next = ptr.next;
        ptr.next.prev = temp;
    }

    static void search_item() {
        if (head == null) return;
        int item = int.Parse(Console.ReadLine());
        Node temp = head;
        int i = 1;
        bool flag = true;
        while (true) {
            if (temp.data == item) {
                Console.WriteLine(i);
                flag = false;
            }
            temp = temp.next;
            i++;
            if (temp == head) break;
        }
        if (flag) Console.WriteLine("no");
    }

    static void display() {
        if (head == null) return;
        Node temp = head;
        while (true) {
            Console.WriteLine(temp.data);
            temp = temp.next;
            if (temp == head) break;
        }
    }

    static void Main() {
        while (true) {
            Console.WriteLine("1\n2\n3\n4\n5\n6\n7\n8\n9");
            int choice = int.Parse(Console.ReadLine());
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
}
