import java.util.Scanner;

class Node {
    int data;
    Node next;
    Node prev;
}

public class Main {
    static Node head;
    static Scanner sc = new Scanner(System.in);

    static void begininsert() {
        Node ptr = new Node();
        ptr.data = sc.nextInt();
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
        Node ptr = new Node();
        ptr.data = sc.nextInt();
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
        int item = sc.nextInt();
        int loc = sc.nextInt();
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
        int loc = sc.nextInt();
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
        int item = sc.nextInt();
        Node temp = head;
        int i = 1;
        boolean flag = true;
        while (true) {
            if (temp.data == item) {
                System.out.println(i);
                flag = false;
            }
            temp = temp.next;
            i++;
            if (temp == head) break;
        }
        if (flag) System.out.println("no");
    }

    static void display() {
        if (head == null) return;
        Node temp = head;
        while (true) {
            System.out.println(temp.data);
            temp = temp.next;
            if (temp == head) break;
        }
    }

    public static void main(String[] args) {
        while (true) {
            System.out.println("1\n2\n3\n4\n5\n6\n7\n8\n9");
            int choice = sc.nextInt();
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
