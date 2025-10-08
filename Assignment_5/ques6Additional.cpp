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

Node* reverseK(Node* head, int k) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    int count = 0;
    while (curr && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if (next) head->next = reverseK(next, k);
    return prev;
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
    head = reverseK(head, k);
    display(head);
    return 0;
}
