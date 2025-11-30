const readline = require("readline").createInterface({
    input: process.stdin,
    output: process.stdout
});

class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}

let head = null;

function input(q) {
    return new Promise(r => readline.question(q, ans => r(ans)));
}

async function begininsert() {
    let item = parseInt(await input(""));
    let ptr = new Node(item);
    if (head === null) {
        head = ptr;
        ptr.next = ptr;
        ptr.prev = ptr;
    } else {
        let last = head.prev;
        ptr.next = head;
        ptr.prev = last;
        last.next = ptr;
        head.prev = ptr;
        head = ptr;
    }
}

async function lastinsert() {
    let item = parseInt(await input(""));
    let ptr = new Node(item);
    if (head === null) {
        head = ptr;
        ptr.next = ptr;
        ptr.prev = ptr;
    } else {
        let last = head.prev;
        last.next = ptr;
        ptr.prev = last;
        ptr.next = head;
        head.prev = ptr;
    }
}

async function randominsert() {
    let item = parseInt(await input(""));
    let loc = parseInt(await input(""));
    if (head === null) return;
    let temp = head;
    for (let i = 0; i < loc; i++) {
        temp = temp.next;
        if (temp === head) return;
    }
    let ptr = new Node(item);
    let nxt = temp.next;
    ptr.next = nxt;
    ptr.prev = temp;
    temp.next = ptr;
    nxt.prev = ptr;
}

async function begin_delete() {
    if (head === null) return;
    if (head.next === head) {
        head = null;
        return;
    }
    let last = head.prev;
    head = head.next;
    head.prev = last;
    last.next = head;
}

async function last_delete() {
    if (head === null) return;
    if (head.next === head) {
        head = null;
        return;
    }
    let last = head.prev;
    let prev = last.prev;
    prev.next = head;
    head.prev = prev;
}

async function random_delete() {
    let loc = parseInt(await input(""));
    if (head === null) return;
    let temp = head;
    for (let i = 0; i < loc; i++) {
        temp = temp.next;
        if (temp === head) return;
    }
    let ptr = temp.next;
    if (ptr === head) return;
    temp.next = ptr.next;
    ptr.next.prev = temp;
}

async function search_item() {
    if (head === null) return;
    let item = parseInt(await input(""));
    let temp = head;
    let i = 1;
    let flag = true;
    while (true) {
        if (temp.data === item) {
            console.log(i);
            flag = false;
        }
        temp = temp.next;
        i++;
        if (temp === head) break;
    }
    if (flag) console.log("no");
}

async function display() {
    if (head === null) return;
    let temp = head;
    while (true) {
        console.log(temp.data);
        temp = temp.next;
        if (temp === head) break;
    }
}

async function main() {
    while (true) {
        console.log("1\n2\n3\n4\n5\n6\n7\n8\n9");
        let choice = parseInt(await input(""));
        if (choice === 1) await begininsert();
        else if (choice === 2) await lastinsert();
        else if (choice === 3) await randominsert();
        else if (choice === 4) await begin_delete();
        else if (choice === 5) await last_delete();
        else if (choice === 6) await random_delete();
        else if (choice === 7) await search_item();
        else if (choice === 8) await display();
        else if (choice === 9) break;
    }
    readline.close();
}

main();
