#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

void insertEnd(Node*& head, int val) {
    Node* temp = new Node(val);
    if (!head) {
        head = temp;
        return;
    }
    Node* curr = head;
    while (curr->next) curr = curr->next;
    curr->next = temp;
}

void display(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    while (curr) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

void rearrange(Node*& head) {
    if (!head || !head->next) return;

    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = even;

    while (odd->next && even->next) {
        odd->next = even->next;
        odd = odd->next;
        if (odd->next) {
            even->next = odd->next;
            even = even->next;
        } else {
            even->next = NULL;
            break;
        }
    }

    Node* revEven = reverseList(evenHead);
    odd->next = revEven;
}

int main() {
    Node* head = NULL;
    int arr[] = {10,4,9,1,3,5,9,4};
    for (int x : arr) insertEnd(head, x);

    cout << "original list: ";
    display(head);

    rearrange(head);

    cout << "modified list: ";
    display(head);

    return 0;
}
