import java.util.Scanner;

class LinkedList {
    static class Node {
        int data;
        Node next;
        Node prev; // nuevo puntero
        Node(int d) { data = d; next = null; prev = null; }
    }

    static Node head;
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int choice = 0;
        while (choice != 9) {
            System.out.println("\n\n*********menu principal*********");
            System.out.println("\nelige una opcion de la siguiente lista ...");
            System.out.println("\n===============================================");
            System.out.println("\n1. insertar al principio\n2. insertar al final\n3. insertar despues de posicion\n4. eliminar del principio");
            System.out.println("5. eliminar del final\n6. eliminar despues de posicion\n7. buscar elemento\n8. mostrar lista\n9. salir");
            System.out.println("\ningrese su opcion?");
            
            try {
                choice = sc.nextInt();
            } catch (Exception e) {
                System.out.println("entrada invalida");
                sc.next();
                continue;
            }

            switch (choice) {
                case 1: begininsert(); break;
                case 2: lastinsert(); break;
                case 3: randominsert(); break;
                case 4: begin_delete(); break;
                case 5: last_delete(); break;
                case 6: random_delete(); break;
                case 7: search(); break;
                case 8: display(); break;
                case 9: System.exit(0); break;
                default: System.out.println("introduzca una opcion valida..");
            }
        }
    }

    static void begininsert() {
        System.out.println("\ningrese valor");
        int item = sc.nextInt();
        Node ptr = new Node(item);
        ptr.next = head;
        if (head != null) {
            head.prev = ptr;
        }
        head = ptr;
        System.out.println("\nnodo insertado");
    }

    static void lastinsert() {
        System.out.println("\ningrese valor?");
        int item = sc.nextInt();
        Node ptr = new Node(item);
        if (head == null) {
            head = ptr;
        } else {
            Node temp = head;
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = ptr;
            ptr.prev = temp;
        }
        System.out.println("\nnodo insertado");
    }

    static void randominsert() {
        System.out.println("\nintroduzca el valor del elemento");
        int item = sc.nextInt();
        Node ptr = new Node(item);
        System.out.println("\nintroduce la ubicacion despues de la cual deseas insertar ");
        int loc = sc.nextInt();
        Node temp = head;
        for (int i = 0; i < loc; i++) {
            temp = temp.next;
            if (temp == null) {
                System.out.println("\nno se puede insertar");
                return;
            }
        }
        ptr.next = temp.next;
        ptr.prev = temp;
        if (temp.next != null) {
            temp.next.prev = ptr;
        }
        temp.next = ptr;
        System.out.println("\nnodo insertado");
    }

    static void begin_delete() {
        if (head == null) {
            System.out.println("\nla lista esta vacia");
        } else {
            head = head.next;
            if (head != null) head.prev = null;
            System.out.println("\nnodo eliminado desde el principio ...");
        }
    }

    static void last_delete() {
        if (head == null) {
            System.out.println("\nla lista esta vacia");
        } else if (head.next == null) {
            head = null;
            System.out.println("\nsolo se elimino un nodo de la lista ...");
        } else {
            Node ptr = head;
            while (ptr.next != null) {
                ptr = ptr.next;
            }
            ptr.prev.next = null;
            System.out.println("\nnodo eliminado del ultimo ...");
        }
    }

    static void random_delete() {
        System.out.println("\n introduzca la ubicacion despues de la cual desea realizar la eliminacion");
        int loc = sc.nextInt();
        Node temp = head;
        for (int i = 0; i < loc; i++) {
            temp = temp.next;
            if (temp == null) {
                System.out.println("\nno se puede eliminar");
                return;
            }
        }
        if (temp.next == null) {
             System.out.println("\nno se puede eliminar");
             return;
        }
        Node ptr = temp.next;
        temp.next = ptr.next;
        if (ptr.next != null) {
            ptr.next.prev = temp;
        }
        System.out.println("\nnodo eliminado " + (loc + 1));
    }

    static void search() {
        Node ptr = head;
        int item, i = 0, flag = 1;
        if (ptr == null) {
            System.out.println("\nlista vacia");
        } else {
            System.out.println("\nintroduce el elemento que deseas buscar?");
            item = sc.nextInt();
            while (ptr != null) {
                if (ptr.data == item) {
                    System.out.println("elemento encontrado en la ubicacion " + (i + 1));
                    flag = 0;
                } else {
                    flag = 1;
                }
                i++;
                ptr = ptr.next;
            }
            if (flag == 1) {
                System.out.println("elemento no encontrado");
            }
        }
    }

    static void display() {
        Node ptr = head;
        if (ptr == null) {
            System.out.println("nada que imprimir");
        } else {
            System.out.println("\nimprimiendo valores . . . . .");
            while (ptr != null) {
                System.out.println("\n" + ptr.data);
                ptr = ptr.next;
            }
        }
    }
}