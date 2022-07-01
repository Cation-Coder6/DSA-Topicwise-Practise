#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
    
    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


Node *buildtree(int *ar, int start , int end){
    if(start>end){
        return nullptr;
    }
    
    int mid = (start+end)/2;
    Node *root = new Node(ar[mid]);
    
    root->left = buildtree(ar,start, mid-1);
    root->right = buildtree(ar,mid+1,end);
}

void preorder_traversal(Node *root){
    if(root == nullptr){
        return;
    }
  
    preorder_traversal(root->left);
     cout<<root->data<<" ";
    preorder_traversal(root->right);
     
}

int main(){
    int arr[] = {10, 20, 30, 40, 50};

    Node* root = buildtree(arr, 0, 4);
    preorder_traversal(root);
    cout << endl;
    return 0;
}