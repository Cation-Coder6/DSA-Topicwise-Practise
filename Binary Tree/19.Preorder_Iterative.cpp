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

void preorder(Node *root){
    if(root == nullptr){
        return;
    }
    Node *temp = root;
    stack<Node *> s;
    
    while( temp || !s.empty()){
        while(temp){
            s.push(temp);
            cout<<temp->data<<" ";
            temp = temp->left;
        }
        temp = s.top();
        s.pop();

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
    preorder(root);
    return 0;
}