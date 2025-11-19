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
int main(){
    int arr[]={3,2,1,5,6,4};
    Node* root=buildBST(arr,6);
    inorder(root);
    return 0;
}