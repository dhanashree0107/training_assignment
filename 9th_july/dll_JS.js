class Node {
    constructor(element) {
        this.element = element;
        this.next = null;
        this.prev = null;
    }
}

class DLL {
    constructor() {
        this.head = null;
        this.tail = null;
        this.length = 0;
    }

    //inserting element at the end
    insert_at_end(element) {
        let newnode = new Node(element);
        let current = this.head;
        let previous;
        if (!this.head) {
            this.head = newnode;
            this.tail = newnode;
        } else {
            newnode.prev = this.tail;
            this.tail.next = newnode;
            this.tail = newnode;
        }
        this.length++;
        return this;
    }

    //inserting element at the start - at head
    insert_at_start(element) {
        let newnode = new Node(element);

        if (!this.head) {
            this.head = newNode;
            this.tail = newNode;
        } else {
            this.head.prev = newnode;
            newnode.next = this.head;
            this.head = newnode;
        }
        this.length++;
        return this;
    }

    //deleting element from end -tail element
    delete_from_end() {
        if (this.length === 0) {
            return "list is empty";
        }
        let current = this.tail;
        let new_tail = this.tail.prev;
        if (new_tail) {
            new_tail.next = null;
            this.tail.prev = null;
        } else {
            this.head = null;
        }
        this.tail = new_tail;
        this.length--;

    }

    //deleting element from start - head element
    delete_from_start() {
        if (this.length === 0) {
            return "list is empty";
        }
        let current = this.head;
        let new_head = this.head.next;
        if (new_head) {
            new_head.prev = null;
            this.head.next = null;
        } else {
            this.tail = null;
        }
        this.head = new_head;
        this.length--;

    }

    //printing the list showing next prev and value of every node in object
    printList() {

        if (this.head) {
            let current = this.head;
            while (current.next) {
                console.log(current);
                current = current.next;
            }
            console.log(current);
        } else {
            console.log("empty list")
        }
    }

    //converting list of nodes to array
    toArray() {
        let arr = [],
            current = this.head;

        while (current) {
            arr.push(current.element);
            current = current.next;
        }

        return arr;
    };
}

let dll = new DLL();
console.log(dll.insert_at_end("Hello"));
console.log(dll.insert_at_end("World"));
dll.delete_from_end();
console.log(dll.insert_at_start("World1"));
console.log(dll.insert_at_start("World2"));
console.log(dll.delete_from_start());
console.log(dll.printList());
console.log("\n complete list :");
console.log(dll.toArray());