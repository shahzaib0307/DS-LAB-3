#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    Node* next;
};

Node* insertAlpha(Node* head, string n) {
    Node* t = new Node;
    t->name = n;
    t->next = NULL;
    if (!head || n < head->name) {
        t->next = head;
        return t;
    }
    Node* cur = head;
    while (cur->next && cur->next->name < n) cur = cur->next;
    t->next = cur->next;
    cur->next = t;
    return head;
}

Node* removeName(Node* head, string n) {
    if (!head) return NULL;
    if (head->name == n) {
        Node* tmp = head->next;
        delete head;
        return tmp;
    }
    Node* cur = head;
    while (cur->next && cur->next->name != n) cur = cur->next;
    if (cur->next) {
        Node* tmp = cur->next;
        cur->next = tmp->next;
        delete tmp;
    }
    return head;
}

bool findName(Node* head, string n) {
    while (head) {
        if (head->name == n) return true;
        head = head->next;
    }
    return false;
}

void show(Node* head) {
    if (!head) { cout << "no reservations" << endl; return; }
    while (head) {
        cout << head->name << endl;
        head = head->next;
    }
}

int main() {
    Node* head = NULL;
    int ch;
    string nm;
    while (true) {
        cout << endl;
        cout << "1.reserve" << endl;
        cout << "2.cancel" << endl;
        cout << "3.check" << endl;
        cout << "4.display" << endl;
        cout << "5.exit" << endl;
        cin >> ch;
        if (ch == 1) {
            cout << "enter name: "; cin >> nm;
            head = insertAlpha(head, nm);
        } else if (ch == 2) {
            cout << "enter name: "; cin >> nm;
            head = removeName(head, nm);
        } else if (ch == 3) {
            cout << "enter name: "; cin >> nm;
            if (findName(head, nm)) cout << "reserved" << endl;
            else cout << "not reserved" << endl;
        } else if (ch == 4) {
            show(head);
        } else break;
    }
}
