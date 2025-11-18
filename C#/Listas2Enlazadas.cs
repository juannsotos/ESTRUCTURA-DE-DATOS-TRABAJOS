using System;

class Program {
    public class Node {
        public int data;
        public Node next;
        public Node prev; // nuevo puntero
        public Node(int d) { data = d; next = null; prev = null; }
    }

    public static Node head = null;

    static void Main(string[] args) {
        int choice = 0;
        while (choice != 9) {
            Console.WriteLine("\n\n*********menu principal*********");
            Console.WriteLine("\nelige una opcion de la siguiente lista ...");
            Console.WriteLine("\n===============================================");
            Console.WriteLine("\n1. insertar al principio\n2. insertar al final\n3. insertar despues de posicion\n4. eliminar del principio");
            Console.WriteLine("5. eliminar del final\n6. eliminar despues de posicion\n7. buscar elemento\n8. mostrar lista\n9. salir");
            Console.WriteLine("\ningrese su opcion?");
            
            try {
                choice = Convert.ToInt32(Console.ReadLine());
            } catch {
                Console.WriteLine("entrada invalida");
                continue;
            }

            switch (choice) {
                case 1: BeginInsert(); break;
                case 2: LastInsert(); break;
                case 3: RandomInsert(); break;
                case 4: BeginDelete(); break;
                case 5: LastDelete(); break;
                case 6: RandomDelete(); break;
                case 7: Search(); break;
                case 8: Display(); break;
                case 9: Environment.Exit(0); break;
                default: Console.WriteLine("introduzca una opcion valida.."); break;
            }
        }
    }

    static void BeginInsert() {
        Console.WriteLine("\ningrese valor");
        int item = int.Parse(Console.ReadLine());
        Node ptr = new Node(item);
        ptr.next = head;
        if (head != null) head.prev = ptr;
        head = ptr;
        Console.WriteLine("\nnodo insertado");
    }

    static void LastInsert() {
        Console.WriteLine("\ningrese valor?");
        int item = int.Parse(Console.ReadLine());
        Node ptr = new Node(item);
        if (head == null) {
            head = ptr;
        } else {
            Node temp = head;
            while (temp.next != null) temp = temp.next;
            temp.next = ptr;
            ptr.prev = temp;
        }
        Console.WriteLine("\nnodo insertado");
    }

    static void RandomInsert() {
        Console.WriteLine("\nintroduzca el valor del elemento");
        int item = int.Parse(Console.ReadLine());
        Node ptr = new Node(item);
        Console.WriteLine("\nintroduce la ubicacion despues de la cual deseas insertar ");
        int loc = int.Parse(Console.ReadLine());
        Node temp = head;
        for (int i = 0; i < loc; i++) {
            temp = temp.next;
            if (temp == null) {
                Console.WriteLine("\nno se puede insertar");
                return;
            }
        }
        ptr.next = temp.next;
        ptr.prev = temp;
        if (temp.next != null) temp.next.prev = ptr;
        temp.next = ptr;
        Console.WriteLine("\nnodo insertado");
    }

    static void BeginDelete() {
        if (head == null) {
            Console.WriteLine("\nla lista esta vacia");
        } else {
            head = head.next;
            if (head != null) head.prev = null;
            Console.WriteLine("\nnodo eliminado desde el principio ...");
        }
    }

    static void LastDelete() {
        if (head == null) {
            Console.WriteLine("\nla lista esta vacia");
        } else if (head.next == null) {
            head = null;
            Console.WriteLine("\nsolo se elimino un nodo de la lista ...");
        } else {
            Node ptr = head;
            while (ptr.next != null) {
                ptr = ptr.next;
            }
            ptr.prev.next = null;
            Console.WriteLine("\nnodo eliminado del ultimo ...");
        }
    }

    static void RandomDelete() {
        Console.WriteLine("\n introduzca la ubicacion despues de la cual desea realizar la eliminacion");
        int loc = int.Parse(Console.ReadLine());
        Node temp = head;
        for (int i = 0; i < loc; i++) {
            temp = temp.next;
            if (temp == null) {
                Console.WriteLine("\nno se puede eliminar");
                return;
            }
        }
        if (temp.next == null) {
             Console.WriteLine("\nno se puede eliminar");
             return;
        }
        Node ptr = temp.next;
        temp.next = ptr.next;
        if (ptr.next != null) ptr.next.prev = temp;
        Console.WriteLine("\nnodo eliminado " + (loc + 1));
    }

    static void Search() {
        Node ptr = head;
        int i = 0, flag = 1;
        if (ptr == null) {
            Console.WriteLine("\nlista vacia");
        } else {
            Console.WriteLine("\nintroduce el elemento que deseas buscar?");
            int item = int.Parse(Console.ReadLine());
            while (ptr != null) {
                if (ptr.data == item) {
                    Console.WriteLine("elemento encontrado en la ubicacion " + (i + 1));
                    flag = 0;
                } else {
                    flag = 1;
                }
                i++;
                ptr = ptr.next;
            }
            if (flag == 1) Console.WriteLine("elemento no encontrado");
        }
    }

    static void Display() {
        Node ptr = head;
        if (ptr == null) {
            Console.WriteLine("nada que imprimir");
        } else {
            Console.WriteLine("\nimprimiendo valores . . . . .");
            while (ptr != null) {
                Console.WriteLine("\n" + ptr.data);
                ptr = ptr.next;
            }
        }
    }
}