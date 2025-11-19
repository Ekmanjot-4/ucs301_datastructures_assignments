# include <iostream>
using namespace  std;
class Node{
    public:
    char data;
    Node* prev;
    Node* next;
    Node(char val){
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
    void insertAtHead(char val){
    Node* new_node=new Node(val);
    if(head==NULL){
        head=tail=new_node;
        return;
    }
    new_node->next=head;
    head->prev=new_node;
    head=new_node;
    }
    void insertAtEnd(char val){
    Node* new_node=new Node(val);
    if(head==NULL){
        head=tail=new_node;
        return;
    }
    tail->next=new_node;
    new_node->prev=tail;
    tail=new_node;
    }
    void insertAtPos(char val,int pos){
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
    void delAtHead(){
        if(head==NULL)return;
        Node* temp=this->head;
        head=head->next;
        head->prev=NULL;
        temp->next=NULL;
        delete temp;
    }
    void delAtEnd(){
        if(head==NULL)return;
        Node* temp=tail;
        tail=tail->prev;
        tail->next=NULL;
        temp->next=temp->prev=NULL;
        delete temp;
    }
    void delAtPos(int pos){
        if(head==NULL)return;
        int count=pos;
        Node* prev;
        Node* temp=this->head;
        while(count--){
            prev=temp;
            temp=temp->next;
        }
        Node* next_ptr=temp->next;
        prev->next=next_ptr;
        next_ptr->prev=prev;
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
    int search(char val){
        if(head==NULL)return -1;
        Node* temp=head;
        int count=0;
        bool found=false;
        while(temp!=NULL){
            if(temp->data==val){
                found=true;
                break;
            }
            temp=temp->next;
            count++;
        }
        if(found)return count+1;
        else return -1;
    }
    bool palindrome(){
        Node* left=head;
        Node* right=tail;
        bool valid=false;
        while(left!=right){
            if(left->data==right->data){
                left=left->next;
                right=right->prev;
                valid=true;
            }
            else{
                valid=false;
                break;
            }
        }
        if(valid)return true;
        else return false;
    }
    
};
int main(){
    DLL dll;
    char arr[]={'L','E','V','E','L'};
    for(int i=0;i<5;i++){
        dll.insertAtEnd(arr[i]);
    }
    dll.display();
    if(dll.palindrome()){
        cout<<"Yes the elements of LL are a palindrome"<<endl;
    }
    else{
        cout<<"Elements  of LL are not a valid palindrome"<<endl;
    }
    return 0;
}