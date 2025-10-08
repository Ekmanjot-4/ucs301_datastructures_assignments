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

void insertAtBeginning(Node* &head, int x) {
    Node* n = new Node(x);
    n->next = head;
    head = n;
}

void insertAfter(Node* head, int val, int x) {
    while (head && head->data != val) head = head->next;
    if (!head) return;
    Node* n = new Node(x);
    n->next = head->next;
    head->next = n;
}

void insertBefore(Node* &head, int val, int x) {
    if (!head) return;
    if (head->data == val) {
        insertAtBeginning(head, x);
        return;
    }
    Node* temp = head;
    while (temp->next && temp->next->data != val) temp = temp->next;
    if (!temp->next) return;
    Node* n = new Node(x);
    n->next = temp->next;
    temp->next = n;
}

void deleteBeginning(Node* &head) {
    if (!head) return;
    Node* t = head;
    head = head->next;
    delete t;
}

void deleteEnd(Node* &head) {
    if (!head) return;
    if (!head->next) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next->next) temp = temp->next;
    delete temp->next;
    temp->next = NULL;
}

void deleteValue(Node* &head, int val) {
    if (!head) return;
    if (head->data == val) {
        deleteBeginning(head);
        return;
    }
    Node* temp = head;
    while (temp->next && temp->next->data != val) temp = temp->next;
    if (!temp->next) return;
    Node* del = temp->next;
    temp->next = del->next;
    delete del;
}

void search(Node* head, int val) {
    int pos = 1;
    while (head) {
        if (head->data == val) {
            cout << "Found at position " << pos << endl;
            return;
        }
        head = head->next;
        pos++;
    }
    cout << "Not found" << endl;
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
    int ch, x, val;
    while (1) {
        cout << "1.InsertBeg 2.InsertEnd 3.InsertBefore 4.InsertAfter 5.DelBeg 6.DelEnd 7.DelVal 8.Search 9.Display 10.Exit\n";
        cin >> ch;
        if (ch == 10) break;
        switch (ch) {
            case 1: cin >> x; insertAtBeginning(head, x); break;
            case 2: cin >> x; insertAtEnd(head, x); break;
            case 3: cin >> val >> x; insertBefore(head, val, x); break;
            case 4: cin >> val >> x; insertAfter(head, val, x); break;
            case 5: deleteBeginning(head); break;
            case 6: deleteEnd(head); break;
            case 7: cin >> val; deleteValue(head, val); break;
            case 8: cin >> val; search(head, val); break;
            case 9: display(head); break;
        }
    }
    return 0;
}
