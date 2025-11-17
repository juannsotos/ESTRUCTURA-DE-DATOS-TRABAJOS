const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
    }
}

let head = null;

function mainMenu() {
    console.log("\n\n*********Menú principal*********");
    console.log("\nElige una opción de la siguiente lista ...");
    console.log("\n===============================================");
    console.log("\n1. Insertar al principio\n2. Insertar al final\n3. Insertar\n4. Eliminar del principio");
    console.log("5. Eliminar desde el último\n6. Eliminar nodo después de la ubicación especificada\n7. Buscar un elemento\n8. Mostrar\n9. Salir");
    
    rl.question("\nIngrese su opción?\n", (answer) => {
        let choice = parseInt(answer);
        switch (choice) {
            case 1: begininsert(); break;
            case 2: lastinsert(); break;
            case 3: randominsert(); break;
            case 4: begin_delete(); break;
            case 5: last_delete(); break;
            case 6: random_delete(); break;
            case 7: search(); break;
            case 8: display(); break;
            case 9: process.exit(0); break;
            default: 
                console.log("Introduzca una opción válida..");
                mainMenu();
                break;
        }
    });
}

function begininsert() {
    rl.question("\nIngrese valor\n", (ans) => {
        let item = parseInt(ans);
        let ptr = new Node(item);
        ptr.next = head;
        head = ptr;
        console.log("\nNodo insertado");
        mainMenu();
    });
}

function lastinsert() {
    rl.question("\nIngrese valor?\n", (ans) => {
        let item = parseInt(ans);
        let ptr = new Node(item);
        if (head === null) {
            head = ptr;
        } else {
            let temp = head;
            while (temp.next !== null) temp = temp.next;
            temp.next = ptr;
        }
        console.log("\nNodo insertado");
        mainMenu();
    });
}

function randominsert() {
    rl.question("\nIntroduzca el valor del elemento\n", (ansItem) => {
        let item = parseInt(ansItem);
        let ptr = new Node(item);
        rl.question("\nIntroduce la ubicación después de la cual deseas insertar \n", (ansLoc) => {
            let loc = parseInt(ansLoc);
            let temp = head;
            for (let i = 0; i < loc; i++) {
                temp = temp.next;
                if (temp === null) {
                    console.log("\nNo se puede insertar");
                    mainMenu();
                    return;
                }
            }
            ptr.next = temp.next;
            temp.next = ptr;
            console.log("\nNodo insertado");
            mainMenu();
        });
    });
}

function begin_delete() {
    if (head === null) {
        console.log("\nLa lista está vacía");
    } else {
        head = head.next;
        console.log("\nNodo eliminado desde el principio ...");
    }
    mainMenu();
}

function last_delete() {
    if (head === null) {
        console.log("\nLa lista está vacía");
    } else if (head.next === null) {
        head = null;
        console.log("\nSolo se eliminó un nodo de la lista ...");
    } else {
        let ptr = head;
        let ptr1 = null;
        while (ptr.next !== null) {
            ptr1 = ptr;
            ptr = ptr.next;
        }
        ptr1.next = null;
        console.log("\nNodo eliminado del último ...");
    }
    mainMenu();
}

function random_delete() {
    rl.question("\n Introduzca la ubicación del nodo después del cual desea realizar la eliminación. \n", (ans) => {
        let loc = parseInt(ans);
        let ptr = head;
        let ptr1 = null;
        for (let i = 0; i < loc; i++) {
            ptr1 = ptr;
            ptr = ptr.next;
            if (ptr === null) {
                console.log("\nNo se puede eliminar");
                mainMenu();
                return;
            }
        }
        ptr1.next = ptr.next;
        console.log("\nNodo eliminado " + (loc + 1));
        mainMenu();
    });
}

function search() {
    let ptr = head;
    let i = 0;
    let flag = 1;
    if (ptr === null) {
        console.log("\nLista vacía");
        mainMenu();
    } else {
        rl.question("\nIntroduce el elemento que deseas buscar?\n", (ans) => {
            let item = parseInt(ans);
            while (ptr !== null) {
                if (ptr.data === item) {
                    console.log("Elemento encontrado en la ubicación " + (i + 1));
                    flag = 0;
                } else {
                    flag = 1;
                }
                i++;
                ptr = ptr.next;
            }
            if (flag === 1) {
                console.log("Elemento no encontrado");
            }
            mainMenu();
        });
    }
}

function display() {
    let ptr = head;
    if (ptr === null) {
        console.log("Nada que imprimir");
    } else {
        console.log("\nimprimiendo valores . . . . .");
        while (ptr !== null) {
            console.log("\n" + ptr.data);
            ptr = ptr.next;
        }
    }
    mainMenu();
}

// Iniciar el programa
mainMenu();