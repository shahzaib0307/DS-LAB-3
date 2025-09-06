#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* addNode(Node* head, int val) {
    Node* t = new Node;
    t->data = val;
    t->next = NULL;
    if (!head) return t;
    Node* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = t;
    return head;
}

void show(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* rotate(Node* head, int k) {
    if (!head || !head->next || k == 0) return head;
    Node* cur = head;
    int cnt = 1;
    while (cur->next) {
        cur = cur->next;
        cnt++;
    }
    cur->next = head;
    k %= cnt;
    for (int i = 0; i < k; i++) head = head->next;
    Node* newHead = head;
    for (int i = 1; i < cnt; i++) head = head->next;
    head->next = NULL;
    return newHead;
}

int main() {
    Node* head = NULL;
    int arr[] = {5,3,1,8,6,4,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < n; i++) head = addNode(head, arr[i]);
    int k;
    cout<<"how many nodes to move?";
    cin >> k;
    head = rotate(head, k);
    show(head);
}
