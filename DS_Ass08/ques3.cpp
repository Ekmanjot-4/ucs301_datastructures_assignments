# include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int value){
        this->data=value;
        left=right=NULL;
    }
};
Node* insert(Node* root, int val){
    Node* new_node= new Node(val);
    if(root==NULL)return new_node;
    if(root->data==val){
        cout<<"Duplicates are not allowed"<<endl;
    }
    else if (root->data<val){
        root->right=insert(root->right,val);
    }
    else{
        root->left=insert(root->left,val);
    }
}
Node* buildBST(int arr[],int size){
    Node* root=NULL;
    for(int i=0;i<size;i++){
        root=insert(root,arr[i]);
    }
    return root;
}
Node* getInorderSuccessor(Node* root){
    while(root!=NULL && root->left!=NULL){
        root=root->left;
    }
    return root;
}
int minDepth(Node* root){
    if(root==NULL)return 0;
    
    if(root->left==NULL && root->right==NULL){
        return 1;
    }
    if(root->left==NULL){
        return 1+minDepth(root->right);
    }
    if(root->right==NULL){
        return 1+minDepth(root->left);
    }
    return 1+min(minDepth(root->left),minDepth(root->right));
}
int maxDepth(Node* root){
    if(root==NULL)return 0;
    int lh=maxDepth(root->left);
    int rh=maxDepth(root->right);
    return max(lh,rh)+1;
}
Node* delNode(Node* root, int key){
    if(root==NULL)return NULL;
    if(key<root->data){
        root->left=delNode(root->left,key);
    }
    else if(key>root->data){
        root->right=delNode(root->right,key);
    }
    else{
        if(root->left==NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        else{
            Node* IS= getInorderSuccessor(root->right);
            root->data=IS->data;
            root->right=delNode(root->right,IS->data);
            
        }
        return root;
    }
    return root;
}
void inorder(Node* root){
    if(root==NULL)return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    int arr[]={3,2,1,5,6,4};
    Node* root=buildBST(arr,6);
    inorder(root);
    cout<<endl;
    cout<<maxDepth(root)<<" "<<minDepth(root)<<endl;
    delNode(root,2);
    inorder(root);
    return 0;
}