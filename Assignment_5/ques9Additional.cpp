#include <iostream>
using namespace std;

class Node {
public:
    int coeff, pow;
    Node* next;
    Node(int c, int p) {
        coeff = c;
        pow = p;
        next = NULL;
    }
};

void insertAtEnd(Node* &head, int c, int p) {
    Node* n = new Node(c, p);
    if (!head) head = n;
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = n;
    }
}

Node* addPolynomials(Node* p1, Node* p2) {
    Node* res = NULL;
    while (p1 && p2) {
        if (p1->pow == p2->pow) {
            insertAtEnd(res, p1->coeff + p2->coeff, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->pow > p2->pow) {
            insertAtEnd(res, p1->coeff, p1->pow);
            p1 = p1->next;
        } else {
            insertAtEnd(res, p2->coeff, p2->pow);
            p2 = p2->next;
        }
    }
    while (p1) {
        insertAtEnd(res, p1->coeff, p1->pow);
        p1 = p1->next;
    }
    while (p2) {
        insertAtEnd(res, p2->coeff, p2->pow);
        p2 = p2->next;
    }
    return res;
}

void display(Node* head) {
    while (head) {
        cout << head->coeff << "x^" << head->pow;
        if (head->next) cout << " + ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* p1 = NULL;
    Node* p2 = NULL;
    int n1, n2, c, p;
    cin >> n1;
    for (int i = 0; i < n1; i++) {
        cin >> c >> p;
        insertAtEnd(p1, c, p);
    }
    cin >> n2;
    for (int i = 0; i < n2; i++) {
        cin >> c >> p;
        insertAtEnd(p2, c, p);
    }
    Node* res = addPolynomials(p1, p2);
    display(res);
    return 0;
}
