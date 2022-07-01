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


int counter(Node *root){
    if(root == nullptr){
        return 0;
    }
    int count = 0;
    count = counter(root->left) + counter(root->right)+1;
    return count;
}

int sumOfAllNodes(Node *root){
    if(root == nullptr){
        return 0;
    }
    int sum = 0;
    sum = sumOfAllNodes(root->left) + sumOfAllNodes(root->right) + root->data;
    return sum;
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    
    cout<<sumOfAllNodes(root);
}
