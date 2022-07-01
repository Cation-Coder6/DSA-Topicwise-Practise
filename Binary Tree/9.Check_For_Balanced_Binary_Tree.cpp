#include<iostream>
#include<queue>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node *right;
    
    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

int height(Node *root){
    if(root == nullptr){
        return 0;
    }
    int count = height(root->left) + height(root->right) + 1;
    return count;
}

bool check(Node *root){
    if(root == nullptr){
        return 1;
    }
    if(abs(height(root->left)-height(root->right))<=1)
        return 1;
        
        return 0;
}


int main(){
    Node *root = new Node(1);
    root ->left = new Node (2);
    root -> right = new Node (3);
    root -> left -> left = new Node (4);
    root ->left->right = new Node (5);
    
    cout<<check(root);
}