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

Node *buildtree(int *preorder,int key ,int min ,int max ,int n){
    static int index = 0;
    if(index >= n){
        return nullptr;
    }
    Node *root = nullptr;
    if(key >min && key <max){
        root = new Node(key);
        index++;
        
        if(index<n)
            root->left = buildtree(preorder , preorder[index], min, key , n);
        if(index<n)
            root->right = buildtree(preorder ,preorder[index] , key , max, n);
    }
            return root;
}
void preorder_traversal(Node *root){
    if(root == nullptr){
        return;
    }
   cout<<root->data<<" ";
    preorder_traversal(root->left);
    
    preorder_traversal(root->right);
     
}

int main(){
    int preorder[] = {10,2,1,13,11};
    int n = 5;
    int index = 0;
    Node *root = buildtree(preorder, preorder[index] , INT_MIN , INT_MAX, n);
    preorder_traversal(root);
}