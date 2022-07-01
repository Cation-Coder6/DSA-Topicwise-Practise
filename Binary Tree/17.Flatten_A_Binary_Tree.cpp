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

void flatten(Node *root){
    if(root == nullptr){
        return;
    }
     flatten(root->left);
     if(root->left != nullptr){
         Node *child = root->right;
         root->right = root->left;
         
         Node *temp = root->right;
         while(temp->right){
             temp = temp->right;
         }
         temp->right = child;
     }
     flatten(root->right);
     root->left = nullptr;
}

void print(Node *root){
    Node *temp = root;
    while(temp){
        cout<<temp->data<<"->";
        temp = temp->right;
    }
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    flatten(root);
    print(root);
    return 0;
}