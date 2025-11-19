# include<iostream>
using namespace  std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        this->data=val;
        next=NULL;
    }
};
class CLL{
    public:
    Node* head;
    Node* tail;
    CLL(){
        head=tail=NULL;
    }
    void insertAtHead(int val){
    Node* new_node=new Node(val);
    if(head==NULL){
        new_node->next=new_node;
        head=tail=new_node;
        return;
    }
    new_node->next=head;
    tail->next=new_node;
    head=new_node;
    }
    void insertAtEnd(int val){
    Node* new_node=new Node(val);
    if(head==NULL){
        new_node->next=new_node;
        head=tail=new_node;
        return;
    }
    tail->next=new_node;
    new_node->next=head;
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
        temp->next=new_node;
    }
    void display(){
        if(head==NULL)return;
        Node* temp=head;
        do{
            cout<<temp->data<<"->";
            temp=temp->next;
        }while(temp!=head);
        cout<<"NULL"<<endl;
    }
    int size(){
        if(head==NULL)return 0;
        Node* temp=head;
        int count=0;
        while(temp->next!=head){
            temp=temp->next;
            count++;
        }
        return count+1;
    }

};
int main(){
    CLL cll;
    int arr[]={6,7,8,9,11,12,13,14,15};
    for(int i=0;i<10;i++){
        cll.insertAtEnd(arr[i]);
    }
    cout<<cll.size()<<endl;
    return 0;
}