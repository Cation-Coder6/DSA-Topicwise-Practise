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

void postorder(Node *root){
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
        temp = temp->right;
        if(temp == nullptr){
            while(!s.empty()){
            cout<<s.top()->data;
            s.pop();
    }
    }
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
    postorder(root);
    return 0;
}