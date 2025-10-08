# include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int value)
    {
        this->data=value;
        this->next=NULL;
    }
};
void insertAtEnd(Node* &head,int x) {
    Node* n = new Node(x);
    if (!head) head = n;
    else {
        Node* temp = head;
        while (temp->next) 
        {
            temp=temp->next;
        };
        temp->next = n;
    }
}
Node* getMid(Node* head)
{
    Node* slow=head;
    Node* fast=head;
    while(fast->next && fast->next->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
int main()
{
    Node* head=NULL;
    int n,x;
    cout<<"Enter the number of nodes in the linked list: "<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the value of node: ";
        cin>>x;
        insertAtEnd(head,x);
    }
    Node* mid=getMid(head);
    cout<<"The middle node is "<<mid->data<<endl;

    return 0;
}