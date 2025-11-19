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
class CLL{
    public:
    Node* head;
    Node* tail;
    CLL(){
        head=tail=NULL;
    }
    void insertAtEnd(int val){
        Node* new_node=new Node(val);
        if(head==NULL){
            head=tail=new_node;
            tail->next=new_node;
        }
        tail->next=new_node;
        new_node->next=head;
        tail=new_node;

    }
    void insertAtHead(int val){
        Node* new_node= new Node(val);
        if(head==NULL){
            head=tail=new_node;
        }
        new_node->next=head;
        tail->next=new_node;
        head=new_node;
    }
    void insertAtPos(int val,int pos){
        Node* new_node= new Node(val);
        int k=pos-1;
        if(head==NULL)return;
        Node* temp=head;
        while(k--){
            temp=temp->next;
        }
        Node* next_ptr=temp->next;
        temp->next=new_node;
        new_node->next=next_ptr;
    }
    void display(){
        if(head==NULL)return;
        Node* temp=head;
        /*do{
            cout<<temp->data<<" ";
            temp=temp->next;
        }while(temp!=head);*/
        do{
            cout<<temp->data<<"->";
            temp=temp->next;
        }while(temp!=tail->next);
        cout<<endl;
    }
   
};
int main(){
    CLL cll;
    int arr[]={1,2,3,4,5};
    for(int i=0;i<5;i++){
        cll.insertAtEnd(arr[i]);
    }
    cll.display();
    cll.insertAtHead(0);
    cll.display();
    
    cll.display();
    return 0;
}