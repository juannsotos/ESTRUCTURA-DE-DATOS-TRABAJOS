import java.util.Scanner;

class Node {
    int data;
    Node next, prev;
}

public class circular {
    static Node head = null;
    static Scanner sc = new Scanner(System.in);

    static void begininsert() {
        Node ptr = new Node();
        ptr.data = sc.nextInt();
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

    static void lastinsert() {
        Node ptr = new Node();
        ptr.data = sc.nextInt();
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

    static void randominsert() {
        Node ptr = new Node();
        ptr.data = sc.nextInt();
        int loc = sc.nextInt();
        Node temp = head;
        for (int i = 0; i < loc; i++) temp = temp.next;
        ptr.next = temp.next;
        ptr.prev = temp;
        temp.next.prev = ptr;
        temp.next = ptr;
    }

    static void begin_delete() {
        if (head == null) return;
        if (head.next == head) {
            head = null;
        } else {
            Node ptr = head;
            head.prev.next = head.next;
            head.next.prev = head.prev;
            head = head.next;
        }
    }

    static void last_delete() {
        if (head == null) return;
        if (head.next == head) {
            head = null;
        } else {
            Node ptr = head.prev;
            ptr.prev.next = head;
            head.prev = ptr.prev;
        }
    }

    static void random_delete() {
        int loc = sc.nextInt();
        Node temp = head;
        for (int i = 0; i < loc; i++) temp = temp.next;
        Node ptr = temp.next;
        temp.next = ptr.next;
        ptr.next.prev = temp;
    }

    static void search_value() {
        int item = sc.nextInt(), pos = 1, found = 0;
        if (head == null) return;
        Node ptr = head;
        do {
            if (ptr.data == item) found = pos;
            ptr = ptr.next;
            pos++;
        } while (ptr != head);
        if (found != 0) System.out.print(found);
        else System.out.print("no");
    }

    static void display() {
        if (head == null) return;
        Node ptr = head;
        do {
            System.out.print(ptr.data + " ");
            ptr = ptr.next;
        } while (ptr != head);
    }

    public static void main(String[] args) {
        int choice;
        while (true) {
            choice = sc.nextInt();
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
}
