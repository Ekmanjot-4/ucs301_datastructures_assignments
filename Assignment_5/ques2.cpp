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

int deleteKey(Node* &head, int key) {
    int count = 0;
    while (head && head->data == key) {
        Node* t = head;
        head = head->next;
        delete t;
        count++;
    }
    Node* temp = head;
    while (temp && temp->next) {
        if (temp->next->data == key) {
            Node* del = temp->next;
            temp->next = del->next;
            delete del;
            count++;
        } else temp = temp->next;
    }
    return count;
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
    int n, x, key;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        insertAtEnd(head, x);
    }
    cin >> key;
    int c = deleteKey(head, key);
    cout << "Count: " << c << " , Updated Linked List: ";
    display(head);
    return 0;
}
