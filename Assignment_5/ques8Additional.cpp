#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        this->data = value;
        this->next = NULL;
    }
};

void insertAtEnd(Node* &head, int x) {
    Node* n = new Node(x);
    if (!head) head = n;
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = n;
    }
}

Node* rotateLeft(Node* head, int k) {
    if (!head || !head->next || k == 0) return head;
    Node* temp = head;
    int len = 1;
    while (temp->next) {
        temp = temp->next;
        len++;
    }
    k = k % len;
    if (k == 0) return head;
    temp->next = head;
    Node* newTail = head;
    for (int i = 1; i < k; i++) newTail = newTail->next;
    Node* newHead = newTail->next;
    newTail->next = NULL;
    return newHead;
}

void display(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    int n, x, k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        insertAtEnd(head, x);
    }
    cin >> k;
    head = rotateLeft(head, k);
    display(head);
    return 0;
}
