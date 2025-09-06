#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

struct DoublyList {
    Node* head;
    Node* tail;
    DoublyList() {
        head = NULL;
        tail = NULL;
    }
    void insertEnd(int val) {
        Node* temp = new Node(val);
        if (!head) {
            head = tail = temp;
            return;
        }
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    void display() {
        Node* curr = head;
        while (curr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

DoublyList concatenate(DoublyList& L, DoublyList& M) {
    if (!L.head) return M;
    if (!M.head) return L;
    L.tail->next = M.head;
    M.head->prev = L.tail;
    L.tail = M.tail;
    return L;
}

int main() {
    DoublyList L, M;
    L.insertEnd(1);
    L.insertEnd(2);
    L.insertEnd(3);

    M.insertEnd(4);
    M.insertEnd(5);
    M.insertEnd(6);

    cout << "list L: ";
    L.display();
    cout << "list M: ";
    M.display();

    DoublyList result = concatenate(L, M);
    cout << "concatenated list: ";
    result.display();

    return 0;
}
