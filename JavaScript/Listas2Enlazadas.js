const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
        this.prev = null; // nuevo puntero
    }
}

let head = null;

function mainMenu() {
    console.log("\n\n*********menu principal*********");
    console.log("\nelige una opcion de la siguiente lista ...");
    console.log("\n===============================================");
    console.log("\n1. insertar al principio\n2. insertar al final\n3. insertar despues de posicion\n4. eliminar del principio");
    console.log("5. eliminar del final\n6. eliminar despues de posicion\n7. buscar elemento\n8. mostrar lista\n9. salir");
    
    rl.question("\ningrese su opcion?\n", (answer) => {
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
                console.log("introduzca una opcion valida..");
                mainMenu();
                break;
        }
    });
}

function begininsert() {
    rl.question("\ningrese valor\n", (ans) => {
        let item = parseInt(ans);
        let ptr = new Node(item);
        ptr.next = head;
        if (head !== null) {
            head.prev = ptr;
        }
        head = ptr;
        console.log("\nnodo insertado");
        mainMenu();
    });
}

function lastinsert() {
    rl.question("\ningrese valor?\n", (ans) => {
        let item = parseInt(ans);
        let ptr = new Node(item);
        if (head === null) {
            head = ptr;
        } else {
            let temp = head;
            while (temp.next !== null) temp = temp.next;
            temp.next = ptr;
            ptr.prev = temp;
        }
        console.log("\nnodo insertado");
        mainMenu();
    });
}

function randominsert() {
    rl.question("\nintroduzca el valor del elemento\n", (ansItem) => {
        let item = parseInt(ansItem);
        let ptr = new Node(item);
        rl.question("\nintroduce la ubicacion despues de la cual deseas insertar \n", (ansLoc) => {
            let loc = parseInt(ansLoc);
            let temp = head;
            for (let i = 0; i < loc; i++) {
                temp = temp.next;
                if (temp === null) {
                    console.log("\nno se puede insertar");
                    mainMenu();
                    return;
                }
            }
            ptr.next = temp.next;
            ptr.prev = temp;
            if (temp.next !== null) temp.next.prev = ptr;
            temp.next = ptr;
            console.log("\nnodo insertado");
            mainMenu();
        });
    });
}

function begin_delete() {
    if (head === null) {
        console.log("\nla lista esta vacia");
    } else {
        head = head.next;
        if (head !== null) head.prev = null;
        console.log("\nnodo eliminado desde el principio ...");
    }
    mainMenu();
}

function last_delete() {
    if (head === null) {
        console.log("\nla lista esta vacia");
    } else if (head.next === null) {
        head = null;
        console.log("\nsolo se elimino un nodo de la lista ...");
    } else {
        let ptr = head;
        while (ptr.next !== null) {
            ptr = ptr.next;
        }
        ptr.prev.next = null;
        console.log("\nnodo eliminado del ultimo ...");
    }
    mainMenu();
}

function random_delete() {
    rl.question("\n introduzca la ubicacion despues de la cual desea realizar la eliminacion \n", (ans) => {
        let loc = parseInt(ans);
        let temp = head;
        for (let i = 0; i < loc; i++) {
            temp = temp.next;
            if (temp === null) {
                console.log("\nno se puede eliminar");
                mainMenu();
                return;
            }
        }
        if (temp.next === null) {
            console.log("\nno se puede eliminar");
            mainMenu();
            return;
        }
        let ptr = temp.next;
        temp.next = ptr.next;
        if (ptr.next !== null) ptr.next.prev = temp;
        console.log("\nnodo eliminado " + (loc + 1));
        mainMenu();
    });
}

function search() {
    let ptr = head;
    let i = 0;
    let flag = 1;
    if (ptr === null) {
        console.log("\nlista vacia");
        mainMenu();
    } else {
        rl.question("\nintroduce el elemento que deseas buscar?\n", (ans) => {
            let item = parseInt(ans);
            while (ptr !== null) {
                if (ptr.data === item) {
                    console.log("elemento encontrado en la ubicacion " + (i + 1));
                    flag = 0;
                } else {
                    flag = 1;
                }
                i++;
                ptr = ptr.next;
            }
            if (flag === 1) {
                console.log("elemento no encontrado");
            }
            mainMenu();
        });
    }
}

function display() {
    let ptr = head;
    if (ptr === null) {
        console.log("nada que imprimir");
    } else {
        console.log("\nimprimiendo valores . . . . .");
        while (ptr !== null) {
            console.log("\n" + ptr.data);
            ptr = ptr.next;
        }
    }
    mainMenu();
}

mainMenu();