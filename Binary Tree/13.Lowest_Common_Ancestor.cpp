#include<iostream>
using namespace std;

class Node{
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

Node *LCA(Node *root, int n1, int n2){
    if(root == nullptr){
        return nullptr;
    }
    if(root->data == n1 || root->data){
        return root;
    }
    
    Node *LCA_Left = LCA(root->left, n2 , n1);
    Node *LCA_Right = LCA(root->right , n2 , n1);
    
    if(LCA_Left && LCA_Right){
        return root;
    }
    else if(LCA_Left){
        return LCA_Left;
    }
    
    return LCA_Right;
}



int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    Node *temp = LCA(root , 2,3);
    cout<<temp->data;
}