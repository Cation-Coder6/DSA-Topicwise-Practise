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

void insert(Node *&root, int val){
    if(root == nullptr){
        root = new Node(val);
        return;
    }
    else if(val<root->data){
        insert(root->left,val);
    }
    else if(val>root->data){
        insert(root->right , val);
    }
}

void traverse(Node *root){
    if(root == nullptr)
        return;
        
    traverse(root->left);
    cout<<root->data<<" ";
    traverse(root->right);
}

bool search(Node *root, int key){
    if(root == nullptr)
        return 0;
    
    else if(root->data == key)
        return 1;
    
    else if(key<root->data)
        return search(root->left, key);
    
    else if(key>root->data)
        return search(root->right, key);
}

int main(){
     Node * root = NULL;
    insert(root, 5);
    insert(root, 4);
    insert(root, 3);
    insert(root, 2);
    insert(root, 1);
    insert(root, 6);
    insert(root, 7);
    traverse(root);
    cout<<search(root,6);
    return 0;
}