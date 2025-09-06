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
        return;
    }
    node* curr = head;
    while (curr->next) curr = curr->next;
    curr->next = temp;
}

void display(node* head) {
    node* curr = head;
    while (curr) {
        cout << curr->data;
        if (curr->next) cout << "->";
        curr = curr->next;
    }
    cout << "->NULL" << endl;
}

void deleteValue(node*& head, int val) {
    if (!head) {
        cout << "list is empty" << endl;
        return;
    }
    node* curr = head;
    node* prev = NULL;
    while (curr && curr->data != val) {
        prev = curr;
        curr = curr->next;
    }
    if (!curr) {
        cout << "value not present in the list" << endl;
        return;
    }
    if (!prev) {
        head = head->next;
    } else {
        prev->next = curr->next;
    }
    delete curr;
    cout << "value deleted successfully" << endl;
}

int main() {
    node* head = NULL;
    insertEnd(head, 5);
    insertEnd(head, 3);
    insertEnd(head, 8);
    insertEnd(head, 6);
    insertEnd(head, 4);

    cout << "original list: ";
    display(head);

    int val;
    cout << "enter value to delete: ";
    cin >> val;

    deleteValue(head, val);

    cout << "updated list: ";
    display(head);

    return 0;
}
