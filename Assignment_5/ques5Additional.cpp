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

int getLength(Node* head) {
    int c = 0;
    while (head) {
        c++;
        head = head->next;
    }
    return c;
}

Node* getIntersection(Node* head1, Node* head2) {
    int l1 = getLength(head1);
    int l2 = getLength(head2);
    int d = abs(l1 - l2);
    if (l1 > l2) while (d--) head1 = head1->next;
    else while (d--) head2 = head2->next;
    while (head1 && head2) {
        if (head1 == head2) return head1;
        head1 = head1->next;
        head2 = head2->next;
    }
    return NULL;
}

int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;
    insertAtEnd(head1, 1);
    insertAtEnd(head1, 2);
    insertAtEnd(head1, 3);
    insertAtEnd(head2, 9);
    insertAtEnd(head2, 10);
    Node* common = new Node(30);
    common->next = new Node(40);
    common->next->next = new Node(50);
    Node* temp = head1;
    while (temp->next) temp = temp->next;
    temp->next = common;
    temp = head2;
    while (temp->next) temp = temp->next;
    temp->next = common;
    Node* inter = getIntersection(head1, head2);
    if (inter) cout << "Intersection Node: " << inter->data;
    else cout << "No Intersection";
    return 0;
}
