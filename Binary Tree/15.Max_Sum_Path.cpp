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

int maxSUM(Node *root , int &res){
    if(root == nullptr){
        return 0;
    }
    
    int l = maxSUM(root->left,res);
    int r = maxSUM(root->right,res);
    
    int max_single = max(max(l,r)+root->data , root->data);
    
    int max_top = max(max_single, l+r+root->data);
    
    res = max(res, max_top);
    cout<<"root->data = "<<root->data<<"\t max_single = "<<max_single<<"\tmax_top = "<<max_top<<"\tres = "<<res<<"\n\n\n\n";
    return max_single;
}

int maxfind(Node *root){
    int res = INT_MIN;
    maxSUM(root , res);
    return res;
    }
    
    
    
int main(void){
    struct Node *root = new Node(10);
    root->left        = new Node(2);
    root->right       = new Node(10);
    root->left->left  = new Node(20);
    root->left->right = new Node(1);
    root->right->right = new Node(-25);
    root->right->right->left   = new Node(3);
    root->right->right->right  = new Node(4);
    maxfind(root);
    return 0;
}