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

void removeLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }
    if (!fast || !fast->next) return;
    slow = head;
    if (slow == fast) {
        while (fast->next != slow) fast = fast->next;
    } else {
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    fast->next = NULL;
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
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        insertAtEnd(head, x);
    }
    Node* temp = head;
    Node* loopNode = NULL;
    int pos;
    cin >> pos;
    if (pos > 0) {
        int c = 1;
        Node* join = NULL;
        while (temp->next) {
            if (c == pos) join = temp;
            temp = temp->next;
            c++;
        }
        temp->next = join;
    }
    removeLoop(head);
    display(head);
    return 0;
}
