class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

head = None

def begininsert():
    global head
    item = int(input())
    ptr = Node(item)
    if head is None:
        head = ptr
        ptr.next = ptr
        ptr.prev = ptr
    else:
        last = head.prev
        ptr.next = head
        ptr.prev = last
        last.next = ptr
        head.prev = ptr
        head = ptr

def lastinsert():
    global head
    item = int(input())
    ptr = Node(item)
    if head is None:
        head = ptr
        ptr.next = ptr
        ptr.prev = ptr
    else:
        last = head.prev
        last.next = ptr
        ptr.prev = last
        ptr.next = head
        head.prev = ptr

def randominsert():
    global head
    item = int(input())
    loc = int(input())
    if head is None:
        return
    temp = head
    for _ in range(loc):
        temp = temp.next
        if temp == head:
            return
    ptr = Node(item)
    nxt = temp.next
    ptr.next = nxt
    ptr.prev = temp
    temp.next = ptr
    nxt.prev = ptr

def begin_delete():
    global head
    if head is None:
        return
    if head.next == head:
        head = None
        return
    last = head.prev
    head = head.next
    head.prev = last
    last.next = head

def last_delete():
    global head
    if head is None:
        return
    if head.next == head:
        head = None
        return
    last = head.prev
    prev = last.prev
    prev.next = head
    head.prev = prev

def random_delete():
    global head
    loc = int(input())
    if head is None:
        return
    temp = head
    for _ in range(loc):
        temp = temp.next
        if temp == head:
            return
    ptr = temp.next
    if ptr == head:
        return
    temp.next = ptr.next
    ptr.next.prev = temp

def search_item():
    global head
    if head is None:
        return
    item = int(input())
    temp = head
    i = 1
    flag = True
    while True:
        if temp.data == item:
            print(i)
            flag = False
        temp = temp.next
        i += 1
        if temp == head:
            break
    if flag:
        print("no")

def display():
    global head
    if head is None:
        return
    temp = head
    while True:
        print(temp.data)
        temp = temp.next
        if temp == head:
            break

def main():
    while True:
        print("1\n2\n3\n4\n5\n6\n7\n8\n9")
        choice = int(input())
        if choice == 1:
            begininsert()
        elif choice == 2:
            lastinsert()
        elif choice == 3:
            randominsert()
        elif choice == 4:
            begin_delete()
        elif choice == 5:
            last_delete()
        elif choice == 6:
            random_delete()
        elif choice == 7:
            search_item()
        elif choice == 8:
            display()
        elif choice == 9:
            break

main()
