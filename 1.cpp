
#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node *next;
    Node(int dat) {
        val = dat;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node *head;
    Node *tail;
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertatstart(int val) {
        Node *newnode = new Node(val);
        newnode->next = head;
        head = newnode;
        if (!tail) tail = newnode;
    }

    void insertatlast(int val) {
        Node *newnode = new Node(val);
        if (!head) {
            head = tail = newnode;
            return;
        }
        tail->next = newnode;
        tail = newnode;
    }

    void insertatpos(int pos, int val) {
        if (pos == 0) {
            insertatstart(val);
            return;
        }
        Node *curr = head;
        for (int i = 0; i < pos - 1 && curr; i++) {
            curr = curr->next;
        }
        if (!curr) return;
        Node *newnode = new Node(val);
        newnode->next = curr->next;
        curr->next = newnode;
        if (!newnode->next) tail = newnode;
    }

    void deletebyval(int val) {
        if (!head) return;
        if (head->val == val) {
            Node *temp = head;
            head = head->next;
            if (temp == tail) tail = nullptr;
            delete temp;
            return;
        }
        Node *curr = head->next;
        Node *prev = head;
        while (curr) {
            if (curr->val == val) {
                prev->next = curr->next;
                if (curr == tail) tail = prev;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    void print() {
        Node *temp = head;
        while (temp) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int arr[5] = {3, 1, 2, 5, 8};
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    cout << endl;

    LinkedList l1;
    l1.insertatlast(9);        
    l1.insertatpos(1, 11);    
    l1.insertatstart(4);       
    l1.deletebyval(1);        
    l1.deletebyval(2);         
    l1.deletebyval(5);        
    l1.print();                

    return 0;
}