# include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        this->data=val;
        left=right=NULL;
    }
};
Node* insert(Node* root,int val){
    Node* new_node=new Node(val);
    if(root==NULL){
        return new_node;
    }
    if(val<root->data){
        root->left=insert(root->left,val);
    }
    else{
        root->right=insert(root->right,val);
    }
}
Node* buildBST(int arr[],int size){
    Node* root=NULL;
    for(int i=0;i<size;i++){
       root= insert(root,arr[i]);
    }
    return root;
}
Node* inorder(Node* root){
    if(root==NULL)return NULL;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
Node* preorder(Node* root){
    if(root==NULL)return NULL;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
Node* postorder(Node* root){
    if(root==NULL)return NULL;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
Node* minElement(Node* root){
    Node* curr=root;
    if(root==NULL)return NULL;
    while(curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}
Node* maxElement(Node* root){
    Node* curr=root;
    if(root=NULL)return NULL;
    while(curr->right!=NULL){
        curr=curr->right;
    }
    return curr;
}
bool searchRec(Node* root,int key){
    if(root==NULL)return false;
    if(root->data==key) return true;
    else if(key<root->data){
        searchRec(root->left,key);
    }
    else{
        searchRec(root->right,key);
    }
}
bool searchIt(Node* root, int key){
    Node* curr=root;
    while(curr!=NULL){
        if(key==curr->data){
            return true;
        }
        else if(key<curr->data){
            curr=curr->left;
        }
        else{
            curr=curr->right;
        }
    }
    if(curr==NULL)return false;
}
int main(){
    int arr[]={3,2,1,5,6,4};
    Node* root=buildBST(arr,6);
    inorder(root);
    cout<<endl;
    Node* min=minElement(root);
    cout<<min->data<<endl;
    Node* max=maxElement(root);
    cout<<max->data<<endl;
    if(searchRec(root,11)){
        cout<<"The node exists in BST"<<endl;
    }
    else{
        cout<<"The node does not exist in the BST"<<endl;
    }
    if(searchIt(root,2)){
        cout<<"The node exists in BST"<<endl;
    }
    else{
        cout<<"The node does not exist in the BST"<<endl;
    }
    return 0;
}