#include<iostream>
#include<stack>

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

void inorder(Node *root){
    if(root == nullptr){
        return;
    }
    Node *temp = root;
    stack<Node *> s;
    
    while( temp || !s.empty()){
        while(temp){
            s.push(temp);
            temp = temp->left;
        }
        temp = s.top();
        s.pop();
        cout<<temp->data<<" ";
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
    inorder(root);
    return 0;
}