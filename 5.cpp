#include <iostream>
#include <stack>
using namespace std;

struct node {
    char data; 
    node* next;
};

node* createNode(char val) {
    node* temp = new node;
    temp->data = val;
    temp->next = NULL;
    return temp;
}

void insertEnd(node*& head, char val) {
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

bool isPalindrome(node* head) {
    stack<char> st;
    node* slow = head;
    node* fast = head;
    while (fast && fast->next) {
        st.push(slow->data);
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast) slow = slow->next;
    while (slow) {
        if (st.top() != slow->data) return false;
        st.pop();
        slow = slow->next;
    }
    return true;
}

int main() {
    node* head = NULL;
    insertEnd(head, '1');
    insertEnd(head, '0');
    insertEnd(head, '2');
    insertEnd(head, '0');
    insertEnd(head, '1');
    cout << "linked list: ";
    display(head);
    if (isPalindrome(head)) cout << "linked list is a palindrome" << endl;
    else cout << "linked list is not a palindrome" << endl;

    node* head2 = NULL;
    string word = "BORROWORROB";
    for (char c : word) insertEnd(head2, c);
    cout << "linked list: ";
    display(head2);
    if (isPalindrome(head2)) cout << "linked list is a palindrome" << endl;
    else cout << "linked list is not a palindrome" << endl;

    
}
