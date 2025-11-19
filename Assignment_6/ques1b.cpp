# include<iostream>
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
    void delAtHead(){
        if(head==NULL)return;
        Node* temp=this->head;
        tail->next=head->next;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    void delAtEnd(){
        if(head==NULL)return;
        Node* prev=head;
        while(prev->next!=tail){
            prev=prev->next;
        }
        Node* temp=tail;
        prev->next=head;
        tail=prev;
        temp->next=NULL;
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
    int search(int val){
        if(head==NULL)return -1;
        Node* temp=head;
        int count=0;
        bool found=false;
        do{
            if(temp->data==val){
                found=true;
                break;
            }
            temp=temp->next;
            count++;
        }while(temp->next!=head);
        if(found)return count+1;
        else return -1;
    }
    
};

int main(){
    CLL cll;
    int choice;
    int n,p,s;
    do{
        cout<<"    Choose any one option from the menu"<<endl;
        cout<<"    1.Insertion at End"<<endl;
        cout<<"    2.Insertion at Head"<<endl;
        cout<<"    3.Insertion at a Position"<<endl;
        cout<<"    4.Deletion of nth Node"<<endl;
        cout<<"    5.Search for a node"<<endl;
        cout<<"    6.Exit the menu"<<endl;
        cout<<"    Enter the option you want to choose"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
            cout<<"Enter the value of Node to be inserted"<<endl;
            cin>>n;
            cll.insertAtEnd(n);
            cll.display();
            break;
            case 2:
            cout<<"Enter the value of Node to be inserted"<<endl;
            cin>>n;
            cll.insertAtHead(n);
            cll.display();
            break;
            case 3:
            cout<<"Enter the value of Node and the it's position for insertion"<<endl;
            cin>>n>>p;
            cll.insertAtPos(n,p);
            cll.display();
            break;
            case 4:
            cout<<"Enter the position of Node to be deleted"<<endl;
            cin>>p;
            cll.delAtPos(p);
            cll.display();
            break;
            case 5:
            cout<<"Enter the value to be searched"<<endl;
            cin>>s;
            int found=cll.search(s);
            if(found!=(-1)){
                cout<<"Node found at "<<s<<" position"<<endl;
            }
            else{
                cout<<"Node not found"<<endl;
            }
        }


    }while(choice!=6);
    return 0;
}