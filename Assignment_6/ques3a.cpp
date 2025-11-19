// to find size of a dll
# include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int val){
        this->data=val;
        next=prev=NULL;
    }
};
class DLL{
    public:
    Node* head;
    Node* tail;
    DLL(){
        head=tail=NULL;
    }
    void insertAtHead(int val){
    Node* new_node=new Node(val);
    if(head==NULL){
        head=tail=new_node;
        return;
    }
    new_node->next=head;
    head->prev=new_node;
    head=new_node;
    }
    void insertAtEnd(int val){
    Node* new_node=new Node(val);
    if(head==NULL){
        head=tail=new_node;
        return;
    }
    tail->next=new_node;
    new_node->prev=tail;
    tail=new_node;
    }
    void insertAtPos(int val,int pos){
        Node* new_node=new Node(val);
        if(head==NULL){
            head=tail=new_node;
            return;
        }
        int count=pos-1;
        Node* temp=this->head;
        while(count--){
            temp=temp->next;
        }
        Node* curr=temp->next;
        new_node->next=curr;
        curr->prev=new_node;
        new_node->prev=temp;
        temp->next=new_node;
    }
    void display(){
        if(head==NULL)return;
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
    int size(){
        Node* temp=head;
        int count=0;
        if(head==NULL)return 0;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        return count;
    }
};
int main(){
    DLL dll;
    int arr[]={1,2,3,4,5};
    for(int i=0;i<5;i++){
        dll.insertAtEnd(arr[i]);
    }
    cout<<dll.size()<<endl;

    return 0;
}