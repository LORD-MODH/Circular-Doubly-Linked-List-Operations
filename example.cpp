#include<iostream>
using namespace std;

struct node {
    int data;
    node* next, * prev;
};

// Function to create a new node with the given data
node* createnode(int data) {
    node* newnode = new node;
    newnode->data = data;
    newnode->next = nullptr;
    newnode->prev = nullptr;
    return newnode;
}

node* head = nullptr;

// Function to add a node to the circular doubly-linked list
void add(int data) {
    node* newnode = createnode(data);
    if (head == nullptr) {
        head = newnode;
        newnode->next = head;
    }
    else {
        node* current = head;
        while(current->next != head) {
            current = current->next;
        }
        current->next = newnode;
        newnode->next = head;
        head->prev = newnode;
        newnode->prev = current;
    }
}

// Function to add a node at the beginning of the circular doubly-linked list
void at_beginning(int data) {
    node* newnode = createnode(data);
    if (head == nullptr) {
        add(data);
        delete newnode;
    }
    else {
        head->prev->next = newnode;
        newnode->prev = head->prev;
        head->prev = newnode;
        newnode->next = head;
        head = newnode;
    }
}

// Function to add a node at the end of the circular doubly-linked list
void at_end(int data) {
    node* newnode = createnode(data);
    if (head == nullptr) {
        add(data);
        delete newnode;
    }
    else {
        newnode->next = head;
        newnode->prev = head->prev;
        head->prev->next = newnode;
        head->prev = newnode;
    }
}

// Function to insert a node at a specified position
void insert(int data, int pos) {
    node* newnode = createnode(data);
    if (pos == 0) {
        at_beginning(data);
        delete newnode;
    }
    else {
        node* current = head;
        int i = 1;
        for (i; i < pos && current->next != head; i++) {
            current = current->next;
        }
        if (current->next == head) {
            at_end(data);
            delete newnode;
        }
        newnode->next = current->next;
        current->next = newnode;
        newnode->prev = current;
    }
}

int main() {
    add(1);
    add(2);
    add(3);
    insert(0, 0);
    insert(4, 4);
    insert(5, 2);

    node* current = head;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);

    return 0;
}
