#include<iostream>
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

int diameter(Node *root, int *height){
    if(root == nullptr){
        height = 0;
        return 0;
    }
    int lh = 0 , rh = 0;
    int ld = diameter(root->left, &lh);
    int rd = diameter(root->right, &rh);
    
    *height = max(lh,rh) + 1;
    
    return max(lh+rh+1 , max(ld,rd));
    
}
int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    int height = 0;
    cout<<diameter(root,&height);
}