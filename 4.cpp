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

void rearrange(node*& head) {
    if (!head || !head->next) return;

    node* evenStart = NULL;
    node* evenEnd = NULL;
    node* oddStart = NULL;
    node* oddEnd = NULL;
    node* curr = head;

    while (curr) {
        if (curr->data % 2 == 0) {
            if (!evenStart) {
                evenStart = curr;
                evenEnd = evenStart;
            } else {
                evenEnd->next = curr;
                evenEnd = evenEnd->next;
            }
        } else {
            if (!oddStart) {
                oddStart = curr;
                oddEnd = oddStart;
            } else {
                oddEnd->next = curr;
                oddEnd = oddEnd->next;
            }
        }
        curr = curr->next;
    }

    if (!evenStart || !oddStart) return;

    evenEnd->next = oddStart;
    oddEnd->next = NULL;
    head = evenStart;
}

int main() {
    node* head = NULL;

    insertEnd(head, 17);
    insertEnd(head, 15);
    insertEnd(head, 8);
    insertEnd(head, 12);
    insertEnd(head, 10);
    insertEnd(head, 5);
    insertEnd(head, 4);
    insertEnd(head, 1);
    insertEnd(head, 7);
    insertEnd(head, 6);

    cout << "original list: ";
    display(head);

    rearrange(head);

    cout << "modified list: ";
    display(head);

  
}
