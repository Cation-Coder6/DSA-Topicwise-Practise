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


Node *util(Node *root){
    Node *current = root;    
    while(current !=nullptr && current->left != nullptr){
        current = current->left;
    }
     return current;
}

Node *delete_node(Node *root , int val){
    
    if(val<root->data){
        root->left = delete_node(root->left , val);
    }
    else if(val>root->data)
        root->right = delete_node(root->right , val);
        
    if(root->data == val){
        if(root->left == nullptr){
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == nullptr){
            Node *temp = root->left;
            free(root);
            return temp;
        }
        else{
        Node *temp = util(root->right);
        root->data = temp->data;
        root->right = delete_node(root->right , temp->data);
        }
    }    
    return root;
}


void inorder(Node *root){
    if(root == nullptr){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


int main(){
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);
    inorder(root);
    cout<<endl;
    Node *root1 = delete_node(root,5);
    inorder(root1);
}