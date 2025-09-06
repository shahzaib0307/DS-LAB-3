#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node* createNode(int val) {
    node* temp = new node;
    temp->data = val;
    temp->next = NULL;
    return temp;
}

void insertEnd(node*& head, int val) {
    node* temp = createNode(val);
    if (!head) {
        head = temp;
        head->next = head;
        return;
    }
    node* curr = head;
    while (curr->next != head) curr = curr->next;
    curr->next = temp;
    temp->next = head;
}

void insertBegin(node*& head, int val) {
    node* temp = createNode(val);
    if (!head) {
        head = temp;
        head->next = head;
        return;
    }
    node* curr = head;
    while (curr->next != head) curr = curr->next;
    curr->next = temp;
    temp->next = head;
    head = temp;
}

void insertAtPos(node*& head, int val, int pos) {
    if (pos <= 1) {
        insertBegin(head, val);
        return;
    }
    node* temp = createNode(val);
    node* curr = head;
    for (int i = 1; i < pos - 1 && curr->next != head; i++) {
        curr = curr->next;
    }
    temp->next = curr->next;
    curr->next = temp;
}

void deleteNode(node*& head, int val) {
    if (!head) {
        cout << "list is empty" << endl;
        return;
    }
    node* curr = head;
    node* prev = NULL;
    while (curr->data != val) {
        prev = curr;
        curr = curr->next;
        if (curr == head) {
            cout << "value not found" << endl;
            return;
        }
    }
    if (curr == head && curr->next == head) {
        head = NULL;
    } else if (curr == head) {
        prev = head;
        while (prev->next != head) prev = prev->next;
        head = head->next;
        prev->next = head;
    } else {
        prev->next = curr->next;
    }
    delete curr;
    cout << "node deleted" << endl;
}

void display(node* head) {
    if (!head) {
        cout << "list is empty" << endl;
        return;
    }
    node* curr = head;
    do {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
    cout << endl;
}

int main() {
    node* head = NULL;
    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    insertEnd(head, 40);

    cout << "initial list: ";
    display(head);

    insertBegin(head, 5);
    cout << "after inserting 5 at beginning: ";
    display(head);

    insertAtPos(head, 25, 4);
    cout << "after inserting 25 at position 4: ";
    display(head);

    deleteNode(head, 30);
    cout << "after deleting 30: ";
    display(head);

}
