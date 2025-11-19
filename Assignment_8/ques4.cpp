# include <iostream>
# include <vector>
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
void inorder(Node* root,vector<int> &v){
    if(root==NULL)return;
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
    
}
bool isValidBST(Node* root){
    vector<int> v;
    inorder(root,v);
    bool valid=false;
    for(int i=0;i<v.size()-1;i++){
        if(v[i]>=v[i+1]){
            return false;
        }
    }
    return true;
}
int main(){
    int arr[]={3,2,1,5,6,4};
    Node* root=buildBST(arr,6);
    if(isValidBST(root)){
        cout<<"The tree is a valid BST"<<endl;
    }
    else{
        cout<<"Not a valid BST"<<endl;
    }
    return 0;
}