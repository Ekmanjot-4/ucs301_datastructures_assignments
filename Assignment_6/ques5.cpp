# include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        this->data=val;
        next=NULL;
    }
};
class LL{
    public:
    Node* head;
    Node* tail;
    LL(){
        head=tail=NULL;
    }
    void insertAtEnd(int val){
        Node* new_node=new Node(val);
        if(head==NULL){
            head=tail=new_node;
            return;
        }
        tail->next=new_node;
        tail=new_node;
    }
    void insertAtHead(int val){
        Node* new_node= new Node(val);
        if(head==NULL){
            head=tail=new_node;
        }
        new_node->next=head;
        head= new_node;
    }

};
bool isCircular(Node* head){
    if(head==NULL)return false;
    Node* temp=head->next;
    if(temp==head)return true;
    while(temp!=head && temp!=NULL){
        temp=temp->next;
    }
    if(temp==NULL){
        return false;
    }
    else{
        return true;
    }
}
int main(){
    LL ll;
    int arr[]={1,2,3,4,5,6};
    for(int i=0;i<6;i++){
        ll.insertAtEnd(arr[i]);
    }
    //ll.tail->next=ll.head;
    if(isCircular(ll.head)){
        cout<<"The given linked list is circular"<<endl;
    }
    else{
        cout<<"The given linked list is not circular"<<endl;
    }
    return 0;
}